#!/usr/bin/env python3

###
# Register verified single-function game units with the build.
#
# Usage:
#   python tools/sync_units.py [--jobs 8]
#
# Every src/game/unit_XXXXXXXX.c is checked with tools/funcdiff.py. Files that
# match exactly get a split in config/WR9E/splits.txt and an Object(Matching, ...)
# entry in configure.py. Files that compile but don't match yet get the same
# split and an Object(NonMatching, ...) entry: dtk links the original split object
# in their place, and objdiff scores them for the fuzzy progress number. Files
# that don't compile are listed and left out. Both blocks are regenerated in
# address order. Run `python configure.py && ninja` afterwards; the SHA-1 check
# proves the linked result.
###

import argparse
import re
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path
from typing import Dict, List, Tuple

sys.path.insert(0, str(Path(__file__).resolve().parent))
from funcdiff import all_jumptables  # noqa: E402

ROOT = Path(__file__).resolve().parent.parent
SPLITS = ROOT / "config" / "WR9E" / "splits.txt"
CONFIG_YML = ROOT / "config" / "WR9E" / "config.yml"
SYMBOLS = ROOT / "config" / "WR9E" / "symbols.txt"
CONFIGURE = ROOT / "configure.py"
SRC_GAME = ROOT / "src" / "game"


def function_sizes() -> Dict[str, Tuple[int, int]]:
    pat = re.compile(r"^(fn_[0-9A-F]{8}) = \.text:0x([0-9A-F]+); // type:function size:0x([0-9A-F]+)", re.M)
    return {m.group(1): (int(m.group(2), 16), int(m.group(3), 16)) for m in pat.finditer(SYMBOLS.read_text())}


def check(path: Path) -> Tuple[Path, bool, str]:
    fn = "fn_" + path.stem[len("unit_"):]
    try:
        r = subprocess.run([sys.executable, "tools/funcdiff.py", str(path), fn],
                           cwd=ROOT, capture_output=True, text=True, timeout=120)
    except subprocess.TimeoutExpired:
        return path, False, "funcdiff timed out"
    first = (r.stdout.splitlines() or [r.stderr.strip()])[0]
    return path, r.returncode == 0, first


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--jobs", type=int, default=8)
    args = parser.parse_args()

    sizes = function_sizes()
    files = sorted(SRC_GAME.glob("unit_*.c"))
    with ThreadPoolExecutor(args.jobs) as pool:
        results = list(pool.map(check, files))

    matched: List[str] = []
    partial: List[str] = []
    for path, ok, msg in results:
        fn = "fn_" + path.stem[len("unit_"):]
        if fn not in sizes:
            print(f"skipped {path.name}: {fn} isn't a known function")
        elif ok:
            matched.append(path.stem)
        elif "% (mismatch)" in msg:
            # compiled and diffed, just not exact
            partial.append(path.stem)
        else:
            print(f"skipped {path.name}: {msg}")
    units = sorted(matched + partial)
    partial_set = set(partial)

    # a unit owns its function's jump tables; funcdiff's link check already proved
    # they're contiguous and byte-identical
    tables = all_jumptables()

    def split_entry(u: str) -> str:
        fn = "fn_" + u[5:]
        lines = f"game/{u}.c:\n\t.text       start:0x{u[5:]} end:0x{sum(sizes[fn]):08X}\n"
        if fn in tables:
            lo = tables[fn][0][0]
            hi = tables[fn][-1][0] + tables[fn][-1][1]
            lines += f"\t.data       start:0x{lo:08X} end:0x{hi:08X}\n"
        return lines + "\n"

    split_block = "".join(split_entry(u) for u in units)
    text = SPLITS.read_text()
    # game units sit between the Sections header and the first non-game split
    m = re.match(r"(Sections:\n(?:\t[^\n]*\n)*\n)((?:game/[^\n]*\n(?:\t[^\n]*\n)*\n)*)(.*)", text, re.S)
    if not m:
        sys.exit("sync_units: couldn't find the game block in splits.txt")
    SPLITS.write_text(m.group(1) + split_block + m.group(3), newline="\n")

    # mwcc gives .data 8-byte alignment. A table that sat at a 4-mod-8 address in its
    # original TU would get padded in front and shift all of .data, so such units
    # count as matched but stay unlinked until their real TU's data is reconstructed.
    def linkable(u: str) -> bool:
        fn = "fn_" + u[5:]
        return u not in partial_set and (fn not in tables or tables[fn][0][0] % 8 == 0)

    objs = "".join(
        f'            Object({"Matching" if linkable(u) else "NonMatching"}, "game/{u}.c"),\n'
        for u in units
    )
    cfg = CONFIGURE.read_text()
    new_cfg, n = re.subn(
        r'(        "lib": "game",\n(?:        [^\n]*\n)*?        "objects": \[\n)(.*?)(        \],)',
        lambda mm: mm.group(1) + objs + mm.group(3), cfg, count=1, flags=re.S,
    )
    if n != 1:
        sys.exit("sync_units: couldn't find the game lib in configure.py")
    CONFIGURE.write_text(new_cfg, newline="\n")

    # mwld deadstrips functions nothing in the link references (fn_80041E98, an
    # empty function, vanished and shifted .text by 4). Split objects are exported
    # by dtk, compiled ones aren't, so pin every unit function via config.yml's
    # force_active list. dtk drops force_active from symbols.txt when it rewrites it.
    cfg_yml = CONFIG_YML.read_text()
    cfg_yml = re.sub(r"\n# sync_units: begin\n.*?# sync_units: end\n", "\n", cfg_yml, flags=re.S)
    block = "".join(f"- fn_{u[5:]}\n" for u in matched)
    cfg_yml = cfg_yml.rstrip("\n") + "\n# sync_units: begin\nforce_active:\n" + block + "# sync_units: end\n"
    CONFIG_YML.write_text(cfg_yml, newline="\n")
    unlinked = sum(not linkable(u) for u in matched)
    print(f"{len(matched)} matching units registered ({unlinked} unlinked), "
          f"{len(partial)} non-matching units registered, "
          f"{len(files) - len(matched) - len(partial)} skipped")


if __name__ == "__main__":
    main()
