#!/usr/bin/env python3

###
# Match functions from an already matched twin.
#
# Usage:
#   python tools/twins.py [--dry-run] [--jobs 8] [--imm]
#
# Two functions are twins when their dtk disassembly is identical after every
# fn_/lbl_/jumptable_ name is replaced by its order of first appearance. With
# --imm, twins may also differ in trailing immediate operands (li/addi/cmpwi
# etc., not memory offsets); each differing value is then swapped for literals
# of the same value inside the twin's function body only, so struct offsets in
# the local types stay put. For each
# unmatched game function with a twin in src/game/, the twin's source is copied
# with the names swapped and written to src/game/unit_<ADDR>.c only if
# tools/funcdiff.py passes (objdiff + link check). Nothing unverified is kept.
# Run tools/sync_units.py afterwards to register the new units.
###

import argparse
import re
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path
from typing import Dict, List, Optional, Tuple

ROOT = Path(__file__).resolve().parent.parent
ASM_DIR = ROOT / "build" / "WR9E" / "asm"
SRC_GAME = ROOT / "src" / "game"
SCRATCH = ROOT / "build" / "twins"
GAME_START, GAME_END = 0x8000BF80, 0x800EB1CC

NAME = re.compile(r"\b(?:fn|lbl|jumptable)_[0-9A-F]{8}\b")
# trailing immediate of an instruction line, but not a d(rA) memory offset
IMM = re.compile(r"(?<=, )(-?0x[0-9a-f]+|-?\d+)$", re.M)
C_LIT = re.compile(r"\b(0x[0-9A-Fa-f]+|\d+)\b")
FN_BLOCK = re.compile(r"^\.fn (fn_[0-9A-F]{8}), \w+\n(.*?)^\.endfn \1", re.M | re.S)
LINE = re.compile(r"/\* [0-9A-F]{8} [0-9A-F]{8}  (?:[0-9A-F]{2} ){4}\*/\t")


def functions() -> Dict[str, Tuple[str, List[str], str, List[int]]]:
    # name -> (normalized body, referenced names in order of first appearance,
    #          body with immediates abstracted too, trailing immediates in order)
    out = {}
    for p in ASM_DIR.rglob("*.s"):
        for m in FN_BLOCK.finditer(p.read_text()):
            fn = m.group(1)
            if not GAME_START <= int(fn[3:], 16) < GAME_END:
                continue
            body = LINE.sub("", m.group(2))
            body = re.sub(r"^\.L_[0-9A-F]{8}:", ".L:", body, flags=re.M)
            body = re.sub(r"\.L_[0-9A-F]{8}", ".L", body)
            refs: List[str] = []
            # the function's own name counts too, so self-references line up
            for n in [fn] + NAME.findall(body):
                if n not in refs:
                    refs.append(n)
            norm = NAME.sub(lambda mm: f"@{refs.index(mm.group(0))}", body)
            imms = [int(v, 0) for v in IMM.findall(norm)]
            out[fn] = (norm, refs, IMM.sub("#", norm), imms)
    return out


def swap_immediates(src: str, fn: str, old: List[int], new: List[int]) -> Optional[str]:
    # map |old| -> |new| for every differing position; conflicting maps give up
    vals: Dict[int, int] = {}
    for a, b in zip(old, new):
        if a == b:
            continue
        a, b = abs(a), abs(b)
        if vals.setdefault(a, b) != b:
            return None
    if not vals:
        return src
    m = re.search(rf"^\S[^\n]*\b{fn}\(", src, re.M)
    if not m:
        return None
    head, body = src[:m.start()], src[m.start():]
    seen = set()

    def sub(mm: "re.Match[str]") -> str:
        tok = mm.group(1)
        v = int(tok, 16) if tok.lower().startswith("0x") else int(tok)
        if v not in vals:
            return tok
        seen.add(v)
        return f"0x{vals[v]:X}" if tok.lower().startswith("0x") else str(vals[v])

    body = C_LIT.sub(sub, body)
    # every changed value has to show up as a literal, otherwise this is a guess
    return head + body if seen == set(vals) else None


def try_twin(fn: str, twin: str, info: Dict[str, Tuple[str, List[str], str, List[int]]], dry: bool) -> Optional[str]:
    src = (SRC_GAME / f"unit_{twin[3:]}.c").read_text()
    mapping = dict(zip(info[twin][1], info[fn][1]))
    # swap all names in one pass so a swap can't be swapped again
    new_src = NAME.sub(lambda m: mapping.get(m.group(0), m.group(0)), src)
    if info[twin][0] != info[fn][0]:
        swapped = swap_immediates(new_src, fn, info[twin][3], info[fn][3])
        if swapped is None:
            return None
        new_src = swapped
    SCRATCH.mkdir(parents=True, exist_ok=True)
    # local types are named after their function (Unk<ADDR>); keep that true
    new_src = new_src.replace(f"Unk{twin[3:]}", f"Unk{fn[3:]}")
    cand = SCRATCH / f"unit_{fn[3:]}.c"
    cand.write_text(new_src, newline="\n")
    r = subprocess.run([sys.executable, "tools/funcdiff.py", str(cand), fn],
                       cwd=ROOT, capture_output=True, text=True, timeout=120)
    if r.returncode != 0:
        return None
    if not dry:
        (SRC_GAME / cand.name).write_text(new_src, newline="\n")
    return twin


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--dry-run", action="store_true")
    parser.add_argument("--imm", action="store_true", help="also try twins that differ in immediates")
    parser.add_argument("--jobs", type=int, default=8)
    args = parser.parse_args()

    info = functions()
    matched = {"fn_" + p.stem[5:] for p in SRC_GAME.glob("unit_*.c")} & info.keys()
    key = 2 if args.imm else 0
    by_shape: Dict[str, List[str]] = {}
    for fn in sorted(matched):
        by_shape.setdefault(info[fn][key], []).append(fn)

    # with --imm a shape can hold several twins whose literals differ; try each
    todo = [(fn, by_shape[info[fn][key]]) for fn in sorted(info)
            if fn not in matched and info[fn][key] in by_shape]
    print(f"{len(todo)} unmatched functions have a matched twin")

    def first_twin(fn: str, twins: List[str]) -> Optional[str]:
        for twin in twins:
            if try_twin(fn, twin, info, args.dry_run):
                return twin
        return None

    with ThreadPoolExecutor(args.jobs) as pool:
        results = list(pool.map(lambda t: (t[0], first_twin(t[0], t[1])), todo))
    ok = [fn for fn, tw in results if tw]
    for fn, tw in results:
        if not tw:
            print(f"  twin source didn't match for {fn}")
    print(f"{len(ok)} matched from twins{' (dry run, nothing written)' if args.dry_run else ''}")


if __name__ == "__main__":
    main()
