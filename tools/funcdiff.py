#!/usr/bin/env python3

###
# Compile one source file with a library's cflags (the game's by default) and diff
# functions against the original, without touching splits.txt, configure.py or the
# ninja build.
#
# Usage:
#   python tools/funcdiff.py src/game/unit_8004DCBC.c fn_8004DCBC [fn_... ...]
#   python tools/funcdiff.py --lib RVL_SDK src/revolution/OS/OSArena.c OSGetArenaHi ...
#
# Requires a configured and split build (`python configure.py && ninja`) plus the
# capstone and pyelftools Python packages.
# Two independent checks run per function:
#  1. objdiff against the dtk split object that covers the function (the named split
#     from splits.txt if there is one, otherwise the auto split whose start address is
#     the closest one at or below it).
#  2. a link check: relocations are applied with the original symbol addresses and
#     the bytes must equal the DOL exactly; capstone disassembles any mismatch.
# With --lib, named data the object defines (.data/.sdata/.bss/.sbss statics) must
# also sit at a unique original address with the original size and initial bytes.
# Exit status is 0 only if every requested function passes.
###

import argparse
import json
import re
import struct
import subprocess
import sys
from pathlib import Path
from typing import Dict, List, Optional, Tuple

ROOT = Path(__file__).resolve().parent.parent
VERSION = "WR9E"
BUILD = ROOT / "build" / VERSION
SCRATCH = ROOT / "build" / "funcdiff"
OBJDIFF = ROOT / "build" / "tools" / "objdiff-cli.exe"
SYMBOLS = ROOT / "config" / VERSION / "symbols.txt"


def lib_cflags(lib: str = "game") -> Tuple[str, List[str]]:
    # Take mw_version/cflags from the library's first source edge in build.ninja so
    # the flags can't drift from configure.py. Only objects with source get an edge.
    text = (ROOT / "build.ninja").read_text().replace("$\n", "")
    m = re.search(
        rf"# \S+: {re.escape(lib)} \(linked \w+\)\nbuild [^\n]*\n"
        r"\s+mw_version = (\S+)\n\s+cflags = ([^\n]*)\n",
        text,
    )
    if not m:
        sys.exit(f"funcdiff: no {lib} source object in build.ninja; add one to configure.py "
                 "and run `python configure.py` first.")
    flags = re.findall(r'"[^"]*"|\S+', m.group(2))
    return m.group(1).replace("\\", "/"), [f.strip('"') for f in flags]


def symbol_address(name: str) -> Tuple[int, int]:
    pat = re.compile(rf"^{re.escape(name)} = \.text:0x([0-9A-F]+); // type:function size:0x([0-9A-F]+)", re.M)
    m = pat.search(SYMBOLS.read_text())
    if not m:
        sys.exit(f"funcdiff: {name} isn't a .text function in {SYMBOLS}")
    return int(m.group(1), 16), int(m.group(2), 16)


def named_split_object(addr: int) -> Optional[Path]:
    # A unit from splits.txt whose .text covers addr; dtk writes its original object
    # to obj/<unit path without extension>.o.
    text = (ROOT / "config" / VERSION / "splits.txt").read_text()
    for m in re.finditer(r"^(\S[^\n]*):\n((?:\t[^\n]*\n)*)", text, re.M):
        t = re.search(r"^\t\.text\s+start:0x([0-9A-F]+) end:0x([0-9A-F]+)", m.group(2), re.M)
        if t and int(t.group(1), 16) <= addr < int(t.group(2), 16):
            obj = BUILD / "obj" / Path(m.group(1)).with_suffix(".o")
            return obj if obj.exists() else None
    return None


def target_object(addr: int) -> Path:
    named = named_split_object(addr)
    if named is not None:
        return named
    # Auto split objects are named by start address: auto_03_XXXXXXXX_text.o
    best: Optional[Tuple[int, Path]] = None
    for p in (BUILD / "obj").rglob("*.o"):
        m = re.search(r"(?:auto_03_([0-9A-F]{8})_text|unit_([0-9A-F]{8}))\.o$", p.name)
        if not m:
            continue
        start = int(m.group(1) or m.group(2), 16)
        if start <= addr and (best is None or start > best[0]):
            best = (start, p)
    if best is None:
        sys.exit(f"funcdiff: no split object covers 0x{addr:08X}; run ninja first.")
    return best[1]


def compile_source(src: Path, mw_override: Optional[str] = None, lib: str = "game",
                   extra: Optional[List[str]] = None) -> Path:
    mw_version, cflags = lib_cflags(lib)
    if mw_override:
        mw_version = mw_override
    cflags = cflags + (extra or [])
    SCRATCH.mkdir(parents=True, exist_ok=True)
    # keyed by compiler too, so comparing compilers in parallel can't clobber objects
    out = SCRATCH / f"{src.stem}.{mw_version.replace('/', '_')}.o"
    cc = ROOT / "compilers" / mw_version / "mwcceppc.exe"
    if not cc.exists():
        sys.exit(f"funcdiff: no compiler at {cc.relative_to(ROOT)}")
    cmd = [str(cc), *cflags, "-c", str(src), "-o", str(out)]
    r = subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True)
    if r.returncode != 0:
        sys.stdout.write(r.stdout + r.stderr)
        sys.exit(f"funcdiff: {src} failed to compile.")
    return out


def diff(target: Path, base: Path, name: str) -> bool:
    out = SCRATCH / f"{name}.{base.stem}.json"
    r = subprocess.run(
        [str(OBJDIFF), "diff", "-1", str(target), "-2", str(base), "-o", str(out), name],
        cwd=ROOT, capture_output=True, text=True,
    )
    if r.returncode != 0:
        sys.stdout.write(r.stdout + r.stderr)
        print(f"{name}: objdiff failed")
        return False
    d = json.loads(out.read_text())

    def find(side: str) -> Optional[Dict]:
        for s in d.get(side, {}).get("symbols", []):
            if s.get("name") == name:
                return s
        return None

    left, right = find("left"), find("right")
    if right is None:
        print(f"{name}: not found in {base}")
        return False
    pct = right.get("match_percent", 0.0)
    li = left.get("instructions", []) if left else []
    ri = right.get("instructions", [])
    exact = pct == 100.0 and left is not None and left.get("size") == right.get("size")
    print(f"{name}: {pct:.2f}% ({'MATCH' if exact else 'mismatch'}) target {target.relative_to(ROOT)}")
    if not exact:
        for a, b in zip(li, ri):
            kind = b.get("diff_kind") or a.get("diff_kind") or ""
            fa = a.get("instruction", {}).get("formatted", "")
            fb = b.get("instruction", {}).get("formatted", "")
            mark = "  " if not kind else "!!"
            print(f"  {mark} {fa:<36} | {fb:<36} {kind.replace('DIFF_', '').lower()}")
    return exact


# Small-data bases from the DOL's ABS symbols (_SDA_BASE_, _SDA2_BASE_) and the
# ranges of the sections they cover.
SDA_BASE = 0x804F4660
SDA2_BASE = 0x804F74A0
SDA_RANGE = (0x804EC660, 0x804EF488)   # .sdata + .sbss
SDA2_RANGE = (0x804EF4A0, 0x804F0274)  # .sdata2 + .sbss2

R_PPC_ADDR32, R_PPC_ADDR16_LO, R_PPC_ADDR16_HI, R_PPC_ADDR16_HA = 1, 4, 5, 6
R_PPC_REL24, R_PPC_REL14, R_PPC_EMB_SDA21 = 10, 11, 109


def dol_bytes(addr: int, size: int) -> bytes:
    dol = (ROOT / "game" / "base" / "mm9-game.dol").read_bytes()
    offs = struct.unpack(">18I", dol[0x00:0x48])
    addrs = struct.unpack(">18I", dol[0x48:0x90])
    sizes = struct.unpack(">18I", dol[0x90:0xD8])
    for off, start, length in zip(offs, addrs, sizes):
        if length and start <= addr and addr + size <= start + length:
            return dol[off + addr - start:off + addr - start + size]
    sys.exit(f"funcdiff: 0x{addr:08X} isn't inside a DOL section")


def symbol_addresses() -> Dict[str, List[int]]:
    out: Dict[str, List[int]] = {}
    for m in re.finditer(r"^(\S+) = (?:\.?\w+:)?0x([0-9A-F]+);", SYMBOLS.read_text(), re.M):
        out.setdefault(m.group(1), []).append(int(m.group(2), 16))
    return out


def all_jumptables() -> Dict[str, List[Tuple[int, int]]]:
    # fn name -> (address, size) of every jumptable_ the original function references,
    # in address order. They belong to the function's unit: mwcc emits the table into
    # the same object's .data as a local @N symbol.
    sizes = {
        int(m.group(1), 16): int(m.group(2), 16)
        for m in re.finditer(r"^jumptable_([0-9A-F]{8}) = \.data:0x[0-9A-F]+; // type:object size:0x([0-9A-F]+)",
                             SYMBOLS.read_text(), re.M)
    }
    out: Dict[str, List[Tuple[int, int]]] = {}
    block = re.compile(r"^\.fn (fn_[0-9A-F]{8}), \w+\n(.*?)^\.endfn \1", re.M | re.S)
    for p in (BUILD / "asm").rglob("*.s"):
        for m in block.finditer(p.read_text()):
            tables = sorted({int(t, 16) for t in re.findall(r"\bjumptable_([0-9A-F]{8})\b", m.group(2))})
            if tables:
                out[m.group(1)] = [(t, sizes[t]) for t in tables]
    return out


def jumptables_of(name: str) -> List[Tuple[int, int]]:
    return all_jumptables().get(name, [])


def only_jumptable_diffs(name: str, base: Path) -> bool:
    # True when every row objdiff flagged (target side) references a jumptable_ symbol.
    d = json.loads((SCRATCH / f"{name}.{base.stem}.json").read_text())
    left = next((s for s in d.get("left", {}).get("symbols", []) if s.get("name") == name), None)
    right = next((s for s in d.get("right", {}).get("symbols", []) if s.get("name") == name), None)
    if left is None or right is None or left.get("size") != right.get("size"):
        return False
    for a, b in zip(left.get("instructions", []), right.get("instructions", [])):
        if not (a.get("diff_kind") or b.get("diff_kind")):
            continue
        fa = a.get("instruction", {}).get("formatted", "")
        fb = b.get("instruction", {}).get("formatted", "")
        # the indexed load through the table gets flagged along with the lis/addi pair
        if "jumptable_" not in fa and fa != fb:
            return False
    return True


def apply_relocs(buf: bytearray, base: int, relocs: List[Tuple[int, int, int]],
                 problems: List[str], label: str) -> int:
    # relocs: (offset in buf, type, resolved target). base = original address of buf[0].
    applied = 0
    for off, kind, s in relocs:
        p = base + off
        if kind == R_PPC_ADDR32:
            buf[off:off + 4] = struct.pack(">I", s)
        elif kind in (R_PPC_ADDR16_LO, R_PPC_ADDR16_HI, R_PPC_ADDR16_HA):
            half = {R_PPC_ADDR16_LO: s, R_PPC_ADDR16_HI: s >> 16, R_PPC_ADDR16_HA: (s + 0x8000) >> 16}[kind]
            buf[off:off + 2] = struct.pack(">H", half & 0xFFFF)
        elif kind in (R_PPC_REL24, R_PPC_REL14):
            mask = 0x03FFFFFC if kind == R_PPC_REL24 else 0xFFFC
            w = struct.unpack(">I", buf[off:off + 4])[0]
            buf[off:off + 4] = struct.pack(">I", (w & ~mask & 0xFFFFFFFF) | ((s - p) & mask))
        elif kind == R_PPC_EMB_SDA21:
            wo = off & ~3
            if SDA_RANGE[0] <= s < SDA_RANGE[1]:
                reg, sbase = 13, SDA_BASE
            elif SDA2_RANGE[0] <= s < SDA2_RANGE[1]:
                reg, sbase = 2, SDA2_BASE
            else:
                problems.append(f"{label}+0x{off:X}: sda21 target 0x{s:08X} is outside small data")
                continue
            w = struct.unpack(">I", buf[wo:wo + 4])[0]
            buf[wo:wo + 4] = struct.pack(">I", (w & 0xFFE00000) | (reg << 16) | ((s - sbase) & 0xFFFF))
        else:
            problems.append(f"{label}+0x{off:X}: unsupported relocation type {kind}")
            continue
        applied += 1
    return applied


def link_check(obj: Path, name: str, addr: int, size: int, own_data: bool = False) -> bool:
    # Independent of objdiff: apply every relocation of the compiled function (and of
    # its jump tables) the way the linker would, using the original symbol addresses,
    # and require the result to equal the DOL bytes exactly. Capstone disassembles
    # both sides of any mismatching instruction.
    from capstone import CS_ARCH_PPC, CS_MODE_BIG_ENDIAN, CS_MODE_32, CS_MODE_PS, Cs
    from elftools.elf.elffile import ELFFile

    problems: List[str] = []
    known = symbol_addresses()
    tables = jumptables_of(name)
    # the tables must be contiguous to sit in one unit's .data range
    data_base = tables[0][0] if tables else None
    data_size = sum(sz for _, sz in tables)
    if tables and tables[-1][0] + tables[-1][1] != data_base + data_size:
        problems.append("jump tables aren't contiguous in .data")

    with open(obj, "rb") as f:
        elf = ELFFile(f)
        symtab = elf.get_section_by_name(".symtab")
        sym = next((s for s in symtab.iter_symbols() if s.name == name), None)
        if sym is None or elf.get_section(sym["st_shndx"]).name != ".text":
            print(f"  link check: {name} isn't a .text symbol in {obj.name}")
            return False
        start, length = sym["st_value"], sym["st_size"]
        code = bytearray(elf.get_section(sym["st_shndx"]).data()[start:start + length])
        data_sec = elf.get_section_by_name(".data")
        data = bytearray(data_sec.data()) if data_sec is not None else bytearray()

        def resolve(r) -> Optional[int]:
            s = symtab.get_symbol(r["r_info_sym"])
            where = known.get(s.name, []) if s.name else []
            if s.name and not s.name.startswith("@") and len(where) == 1:
                return (where[0] + r["r_addend"]) & 0xFFFFFFFF
            sec = elf.get_section(s["st_shndx"]).name if isinstance(s["st_shndx"], int) else None
            if sec == ".text":  # case labels inside this function
                return (addr + s["st_value"] + r["r_addend"] - start) & 0xFFFFFFFF
            if sec == ".data" and data_base is not None:  # this function's own jump table
                return (data_base + s["st_value"] + r["r_addend"]) & 0xFFFFFFFF
            return None

        def collect(sec_name: str, lo: int, hi: int, label: str) -> List[Tuple[int, int, int]]:
            rela = elf.get_section_by_name(".rela" + sec_name)
            out = []
            for r in (rela.iter_relocations() if rela else []):
                if not lo <= r["r_offset"] < hi:
                    continue
                s = resolve(r)
                if s is None:
                    tname = symtab.get_symbol(r["r_info_sym"]).name or "<section>"
                    problems.append(f"{label}+0x{r['r_offset'] - lo:X}: can't resolve '{tname}' to one original address")
                    continue
                out.append((r["r_offset"] - lo, r["r_info_type"], s))
            return out

        text_relocs = collect(".text", start, start + length, "text")
        data_relocs = collect(".data", 0, len(data), "data") if tables else []

    if length != size:
        problems.append(f"size 0x{length:X}, original 0x{size:X}")
    applied = apply_relocs(code, addr, text_relocs, problems, "text")
    orig = dol_bytes(addr, size)
    data_ok = True
    if tables:
        if len(data) != data_size:
            problems.append(f".data is 0x{len(data):X} bytes, its jump tables are 0x{data_size:X}")
        applied += apply_relocs(data, data_base, data_relocs, problems, "data")
        data_ok = bytes(data) == dol_bytes(data_base, data_size)
        if not data_ok:
            problems.append(f"jump table bytes differ from the DOL at 0x{data_base:08X}")
    elif len(data) and not own_data:
        problems.append(f"object has 0x{len(data):X} bytes of .data that no unit split owns")

    if bytes(code) == orig and data_ok and not problems:
        extra = f", {len(tables)} jump table(s)" if tables else ""
        print(f"  link check OK: {applied} relocations applied{extra}, bytes equal the DOL")
        return True
    for msg in problems:
        print(f"  link check: {msg}")
    md = Cs(CS_ARCH_PPC, CS_MODE_32 | CS_MODE_BIG_ENDIAN | CS_MODE_PS)
    for i in range(0, max(len(code), len(orig)), 4):
        a, b = orig[i:i + 4], bytes(code[i:i + 4])
        if a == b:
            continue
        da = next((f"{x.mnemonic} {x.op_str}" for x in md.disasm(a, addr + i)), a.hex()) if a else ""
        db = next((f"{x.mnemonic} {x.op_str}" for x in md.disasm(b, addr + i)), b.hex()) if b else ""
        print(f"  link check !! {addr + i:08X}  {da:<34} | {db}")
    return False


def symbol_sizes() -> Dict[str, Tuple[int, int]]:
    # name -> (address, size) for every symbols.txt entry that records a size
    out: Dict[str, Tuple[int, int]] = {}
    for m in re.finditer(r"^(\S+) = \.\w+:0x([0-9A-F]+); // \S*.*?size:0x([0-9A-F]+)",
                         SYMBOLS.read_text(), re.M):
        out[m.group(1)] = (int(m.group(2), 16), int(m.group(3), 16))
    return out


def data_check(obj: Path) -> bool:
    # A library TU owns its statics. Every named object in .data/.sdata/.bss/.sbss
    # must exist in symbols.txt at one address with the same size, and initialized
    # ones must start out with the DOL's bytes (relocated data isn't handled yet).
    from elftools.elf.elffile import ELFFile

    known = symbol_addresses()
    sizes = symbol_sizes()
    ok = True
    checked = 0
    with open(obj, "rb") as f:
        elf = ELFFile(f)
        symtab = elf.get_section_by_name(".symtab")
        for s in symtab.iter_symbols():
            if s["st_info"]["type"] != "STT_OBJECT" or not isinstance(s["st_shndx"], int):
                continue
            sec = elf.get_section(s["st_shndx"])
            if sec.name not in (".data", ".sdata", ".bss", ".sbss") or s.name.startswith("@"):
                continue
            where = known.get(s.name, [])
            if len(where) != 1:
                print(f"  data check: {s.name} ({sec.name}) has {len(where)} original addresses")
                ok = False
                continue
            want = sizes.get(s.name, (where[0], None))[1]
            if want is not None and want != s["st_size"]:
                print(f"  data check: {s.name} is 0x{s['st_size']:X} bytes, original 0x{want:X}")
                ok = False
            if sec.name in (".data", ".sdata"):
                rela = elf.get_section_by_name(".rela" + sec.name)
                lo, hi = s["st_value"], s["st_value"] + s["st_size"]
                if rela and any(lo <= r["r_offset"] < hi for r in rela.iter_relocations()):
                    print(f"  data check: {s.name} has relocations; compare it by hand")
                    ok = False
                elif sec.data()[lo:hi] != dol_bytes(where[0], s["st_size"]):
                    print(f"  data check: {s.name} initial bytes differ from the DOL at 0x{where[0]:08X}")
                    ok = False
            checked += 1
    if ok:
        print(f"  data check OK: {checked} static(s) at their original addresses and sizes")
    return ok


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("source", type=Path)
    parser.add_argument("functions", nargs="+")
    parser.add_argument("--lib", default="game",
                        help="configure.py lib whose mw_version/cflags to compile with (default: game)")
    parser.add_argument("--mw-version", help="compiler dir under compilers/ to use instead of the lib's (e.g. GC/3.0a5)")
    parser.add_argument("--extra-cflags", default="",
                        help="flags appended after the lib's, for compiler/flag experiments")
    args = parser.parse_args()
    lib_mode = args.lib != "game"
    obj = compile_source(args.source.resolve(), args.mw_version, args.lib, args.extra_cflags.split())
    ok = data_check(obj) if lib_mode else True
    for name in args.functions:
        addr, size = symbol_address(name)
        exact = diff(target_object(addr), obj, name)
        linked = link_check(obj, name, addr, size, own_data=lib_mode)
        if not exact and linked and jumptables_of(name):
            # objdiff compares the jump table reloc by name (jumptable_X vs mwcc's @N)
            # until the unit owns the table; the link check verified table and code.
            print(f"  objdiff difference is the jump table symbol only; link check is authoritative")
            exact = only_jumptable_diffs(name, obj)
        ok &= linked and exact
    sys.exit(0 if ok else 1)


if __name__ == "__main__":
    main()
