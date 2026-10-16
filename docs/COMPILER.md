# Compiler identification

## Result

| | |
|---|---|
| Game compiler | `compilers/Wii/1.0/mwcceppc.exe`, CodeWarrior PPC EABI **4.2 build 142** (runtime built Aug 26 2008). 4.2 build 140 (Wii/1.0RC1) produces identical code for everything matched so far; see "Wii 4.2 builds" below |
| Game flags | `cflags_game` in `configure.py`: template base flags + `-use_lmw_stmw on -func_align 4` |
| Linker | `compilers/Wii/1.0/mwldeppc.exe`, rebuilds the DOL byte-identical |
| Language | game code is C (or C-style C++); a C++ layer near 0x800D4xxx uses nw4r inlines |

Base flags: `-nodefaults -proc gekko -align powerpc -enum int -fp hardware -Cpp_exceptions off -O4,p -inline auto -pragma "cats off" -pragma "warn_notinlined off" -maxerrors 1 -nosyspath -RTTI off -fp_contract on -str reuse -enc SJIS`.

## Installed toolchains

`mwcceppc.exe -version` for every install (more were added during the first session; `Wii/1.0a` is byte-identical to `Wii/1.0`):

| Dir | mwcc version | Runtime built |
|---|---|---|
| GC/1.0 | 2.3.3 build 144 | Apr 13 2000 |
| GC/1.1, GC/1.1p1 | 2.3.3 build 159 | Feb 7 2001 |
| GC/1.2.5 | 2.3.3 build 163 | Apr 23 2001 |
| GC/1.2.5e | 2.3.3 build 163 (patched, profile hack, see its README) | Apr 23 2001 |
| GC/1.2.5n | 2.3.3 build 163 (patched, addi scheduling fix, see its README) | Apr 23 2001 |
| GC/1.3 | 2.4.2 build 53 | Jan 10 2002 |
| GC/1.3.2, GC/1.3.2r | 2.4.2 build 81 | May 7 2002 |
| GC/2.0, GC/2.0p1 | 2.4.7 build 92 | Sep 16 2002 |
| GC/2.5 | 2.4.7 build 105 | Feb 20 2003 |
| GC/2.6 | 2.4.7 build 107 | Jul 14 2003 |
| GC/2.7 | 2.4.7 build 108 | Jul 22 2004 |
| GC/3.0a3, GC/3.0a3p1 | 4.1 build 51213 | Dec 13 2005 |
| GC/3.0a3.2 | 4.1 build 60126 | Jan 26 2006 |
| GC/3.0a3.3 | 4.1 build 60209 | Feb 12 2006 |
| GC/3.0a3.4 | 4.2 build 60308 | Mar 8 2006 |
| GC/3.0a5 | 4.2 build 60422 | Apr 23 2006 |
| GC/3.0, GC/3.0a5.2 | 4.1 build 60831 | Aug 31 2006 |
| Wii/1.0RC1 | 4.2 build 140 | May 28 2008 |
| Wii/1.0, Wii/1.0a | 4.2 build 142 | Aug 26 2008 |
| Wii/0x4201_127 | reports 4.2 build 142, different binary | Aug 26 2008 |
| Wii/1.1 | 4.3 build 151 | Apr 2 2009 |
| Wii/1.3 | 4.3 build 172 | Apr 23 2010 |
| Wii/1.5 | 4.3 build 188 | Oct 13 2010 |
| Wii/1.6 | 4.3 build 202 | Mar 8 2011 |
| Wii/1.7 | 4.3 build 213 | Sep 5 2011 |

Each directory has `mwcceppc.exe`, `mwldeppc.exe`, `mwasmeppc.exe` and the FlexLM stub DLLs. No MSL/Runtime libraries are installed; none are needed for a split-object build.

## Evidence

### Binary metadata
- The RVL SDK libraries carry `(0x4199_60831)` in their `OSRegisterVersion` strings, i.e. they were built with 4.1 build 60831 (GC/3.0). That is the SDK's compiler, not necessarily the game's.
- Newest library build dates in the DOL: NW4R SND May 15 2008, DWC May 9 2008, EC May 8 2008. MM9 shipped Sep 22 2008 (US).
- The DOL has no `.comment` section and no map, so the version can't be read directly.

### Codegen matrix
Seven game functions were reconstructed and compiled with every installed compiler (game flags, `-use_lmw_stmw on`). Exact matches with relocation fields masked:

| Function | GC 1.0-1.2.5n | GC 1.3.2-2.7 | GC 3.0a3/3.0 | Wii 1.0/1.1/1.3/1.7 |
|---|---|---|---|---|
| fn_8003BE3C | match | match | match | match |
| fn_80046114 | 16 diffs | 7 diffs | 3 diffs | match |
| fn_8004DCBC | 10 diffs | match | match | match |
| fn_80063FA0 | 16 diffs | 17 diffs | match | match |
| fn_80072A20 | 11 diffs | 2 diffs | 2 diffs | match |
| fn_800BBB90 | 12 diffs | 2 diffs | 2 diffs | match |
| fn_800BBE60 | 14-25 diffs | match | match | match |

The GC 3.0 vs Wii difference is scheduling: in the list walk of fn_800BBB90/fn_80072A20 the original stores `l->cur` before the `cmplw`; 4.1 emits the compare first. 4.2+ matches.

### Wii 1.0 vs 1.1/1.3/1.7
A 26-function stress file (division by constants, switches, float<->int, struct copy, loops, s16 math, bool chains, `long long`, shifts, fmadd) produced identical code from all four Wii compilers, as did the seven matrix functions. The choice of Wii/1.0 rests on dates: 1.1, 1.3 and 1.7 were built in 2009-2011, after the game shipped.

### Wii 4.2 builds
Every `src/game/unit_*.c` (990 files) and every parked near miss (63) was run through `funcdiff.py --mw-version` with five 4.2-line compilers:

| Compiler | src/game exact | parked exact |
|---|---|---|
| Wii/1.0 (4.2.142) | 982 / 990 | 1 / 63 |
| Wii/1.0RC1 (4.2.140) | 982 / 990 | 1 / 63 |
| Wii/0x4201_127 | 982 / 990 | 1 / 63 |
| GC/3.0a5 (4.2.60422) | 774 / 990 | 1 / 63 |
| GC/3.0a3.4 (4.2.60308) | 774 / 990 | 1 / 63 |

The three Wii 4.2 builds agree on every file; the GameCube 4.2 builds lose 208 matches. (The 8 non-matching `src/game` files were workers' in-progress files at sweep time; the one parked file that matches is a jump-table unit parked before the checker understood jump tables.) So the game was built with a Wii 4.2 compiler, build 140 or 142, and the codegen observed so far doesn't separate them. Both builds postdate the newest library in the DOL (NW4R SND, May 15 2008) and predate the release, so dates don't decide it either. The build stays on Wii/1.0. Sweep script: `build/mine/compiler_sweep.py` (scratch under `build/`, not tracked).

### Flags
- `-O4,p` required: `-O4,s` 5/7, `-O3`/`-O2` 0/7.
- `-schedule off` 0/7; `-opt nopeephole` 1/7; `-inline off` still 7/7, so the inline setting is unconfirmed (kept `auto` from the template; it only matters for same-TU callees, which single-function units don't have).
- `-use_lmw_stmw on`: fn_80063FA0 saves r25-r31 with `stmw`/`lmw`; without the flag mwcc calls `_savegpr_25`. Functions saving three registers still use separate `stw`, consistent with the flag.
- `-func_align 4`: mwcc 4.2 defaults `.text` alignment to 16. Every split that started at a non-16 address shifted the DOL by 0x20 until this was added. There is no inter-function padding anywhere in 0x8000BF80..0x800D5000, so 4-byte alignment for every game TU is consistent with the binary.
- `-Cpp_exceptions off`: the 426 extabindex entries cover 0x8017D4D0..0x8018224C (MSL C++) and 0x80234C10 onward (EC/DWC-era C++ libraries); no game function has an exception table.
- `-enc SJIS` replaces `-multibyte` for Wii compilers; no SJIS literal has been hit yet.

### Linker
The DOL links byte-identically with both GC/1.3.2 and Wii/1.0 `mwldeppc`. Wii/1.0 needs `__init_cpp_exceptions.cpp`'s `.ctors`/`.dtors` renamed to `.ctors$10`, `.dtors$10`, `.dtors$15` (see `config/WR9E/splits.txt`), otherwise it rejects the runtime objects ("both need to be updated to latest version") or reorders `.ctors`.

## Reproducing the matrix

```
python tools/funcdiff.py src/game/unit_80046114.c fn_80046114
```
uses the configured game flags. For other compilers, compile by hand:
```
compilers/GC/3.0/mwcceppc.exe -nodefaults -proc gekko -align powerpc -enum int -fp hardware -O4,p -inline auto -use_lmw_stmw on -i include -c src/game/unit_80072A20.c -o build/cw.o
build/binutils/powerpc-eabi-objdump.exe -dr build/cw.o
```
(`build/binutils` comes from `python tools/download_tool.py binutils build/binutils --tag 2.42-2`.)
