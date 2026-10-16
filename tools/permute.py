#!/usr/bin/env python3

###
# Small source permuter for near misses.
#
# Usage:
#   python tools/permute.py build/<who>/nonmatching/unit_8001C340.c [--write]
#   python tools/permute.py --all [--write]
#
# Only tries rewrites that keep the source plausible:
#   - reordering the local declarations at the top of the function
#   - swapping two adjacent simple statements (assignments / compound assignments
#     on separate lines, no calls, no control flow) in the same block
# One rewrite at a time, then pairs of statement swaps. A candidate counts only if
# tools/funcdiff.py exits 0 (objdiff + link check). With --write a match goes to
# src/game/unit_<ADDR>.c; without it the result is just printed. Swapping two
# statements can change behaviour when they alias, so read the result before
# keeping it.
###

import argparse
import itertools
import re
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path
from typing import Iterator, List, Optional, Tuple

ROOT = Path(__file__).resolve().parent.parent
SCRATCH = ROOT / "build" / "permute"

DECL = re.compile(r"^    (?!return\b)(?:const\s+)?[A-Za-z_]\w*(?:\s*\*)*\s+\**\w+(?:\[[^\]]*\])?(?:\s*=\s*[^;]+)?;\s*$")
SIMPLE = re.compile(r"^(\s+)(?:[\w\->\.\[\]\(\)\* ]+?)\s*(?:[-+*/&|^]?=|\+\+|--)[^=;][^;]*;\s*$|^(\s+)[\w\->\.\[\]]+(?:\+\+|--);\s*$")


def function_body(lines: List[str], fn: str) -> Tuple[int, int]:
    start = next(i for i, l in enumerate(lines) if re.match(rf"^\S.*\b{fn}\(.*\)\s*\{{\s*$", l))
    depth = 0
    for i in range(start, len(lines)):
        depth += lines[i].count("{") - lines[i].count("}")
        if depth == 0:
            return start, i
    raise ValueError("unbalanced braces")


def decl_variants(lines: List[str], lo: int, hi: int) -> Iterator[List[str]]:
    i = lo + 1
    decls = []
    while i < hi and DECL.match(lines[i]) and "(" not in lines[i].split("=")[0]:
        decls.append(i)
        i += 1
    # initialised declarations depend on order; only permute plain ones
    plain = [d for d in decls if "=" not in lines[d]]
    if len(plain) < 2 or len(plain) > 6:
        return
    texts = [lines[d] for d in plain]
    for perm in itertools.permutations(texts):
        if list(perm) == texts:
            continue
        out = list(lines)
        for d, t in zip(plain, perm):
            out[d] = t
        yield out


def is_simple(l: str) -> bool:
    return bool(SIMPLE.match(l)) and "(" not in l.split("=")[-1].replace("(s32)", "").replace("(u32)", "") \
        and not re.search(r"\b(if|for|while|switch|return|case)\b", l)


def swap_sites(lines: List[str], lo: int, hi: int) -> List[int]:
    sites = []
    for i in range(lo + 1, hi - 1):
        a, b = lines[i], lines[i + 1]
        if is_simple(a) and is_simple(b) and len(a) - len(a.lstrip()) == len(b) - len(b.lstrip()):
            sites.append(i)
    return sites


def swapped(lines: List[str], sites: Tuple[int, ...]) -> List[str]:
    out = list(lines)
    for i in sites:
        out[i], out[i + 1] = out[i + 1], out[i]
    return out


def check(src: str, fn: str, tag: str) -> bool:
    SCRATCH.mkdir(parents=True, exist_ok=True)
    p = SCRATCH / f"unit_{fn[3:]}.{tag}.c"
    p.write_text(src, newline="\n")
    r = subprocess.run([sys.executable, "tools/funcdiff.py", str(p), fn],
                       cwd=ROOT, capture_output=True, text=True, timeout=120)
    ok = r.returncode == 0
    p.unlink(missing_ok=True)
    for extra in SCRATCH.glob(f"unit_{fn[3:]}.{tag}.*"):
        extra.unlink(missing_ok=True)
    return ok


def permute(path: Path, write: bool, jobs: int) -> Optional[str]:
    fn = "fn_" + path.stem[len("unit_"):]
    lines = path.read_text().splitlines(keepends=True)
    try:
        lo, hi = function_body(lines, fn)
    except (StopIteration, ValueError):
        print(f"{path.name}: couldn't find {fn}'s body")
        return None
    cands: List[List[str]] = list(decl_variants(lines, lo, hi))
    sites = swap_sites(lines, lo, hi)
    cands += [swapped(lines, (s,)) for s in sites]
    cands += [swapped(lines, pair) for pair in itertools.combinations(sites, 2) if pair[1] - pair[0] > 1]
    # decl orders combined with each single swap
    for d in list(decl_variants(lines, lo, hi))[:24]:
        cands += [swapped(d, (s,)) for s in sites]
    print(f"{path}: {len(cands)} candidates")

    def run(item):
        n, c = item
        return c if check("".join(c), fn, f"p{n}") else None

    with ThreadPoolExecutor(jobs) as pool:
        for hit in pool.map(run, enumerate(cands)):
            if hit:
                text = "".join(hit)
                print(f"  MATCH for {fn}")
                if write:
                    (ROOT / "src" / "game" / path.name).write_text(text, newline="\n")
                    print(f"  wrote src/game/{path.name}")
                else:
                    print(text)
                return text
    print(f"  no match for {fn}")
    return None


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("paths", nargs="*", type=Path)
    parser.add_argument("--all", action="store_true", help="every build/*/nonmatching attempt not yet in src/game")
    parser.add_argument("--write", action="store_true")
    parser.add_argument("--jobs", type=int, default=8)
    args = parser.parse_args()
    paths = list(args.paths)
    if args.all:
        paths += [p for p in sorted((ROOT / "build").glob("*/nonmatching/unit_*.c"))
                  if not (ROOT / "src" / "game" / p.name).exists()]
    for p in paths:
        permute(p, args.write, args.jobs)


if __name__ == "__main__":
    main()
