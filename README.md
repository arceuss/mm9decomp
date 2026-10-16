# Mega Man 9 (WiiWare) matching decompilation

Work-in-progress matching decomp of Mega Man 9, US WiiWare release (`WR9E`). The goal is C source that the original CodeWarrior compiler turns back into the exact same DOL.

Current state: 1760 of 2941 game functions match exactly and link into a byte-identical DOL. Details in [`docs/STATUS.md`](docs/STATUS.md).

Built on [decomp-toolkit](https://github.com/encounter/decomp-toolkit), [dtk-template](https://github.com/encounter/dtk-template) and [objdiff](https://github.com/encounter/objdiff).

## What you need

- `game/base/mm9-game.dol`, SHA-1 `8a7c0c2daa65fb3dcd5176922335cf3b999cd940` (main DOL from the WAD's content 1). Not included.
- CodeWarrior installs in `compilers/GC/<ver>/` and `compilers/Wii/<ver>/`. The build uses `compilers/Wii/1.0`. Not included.
- Python 3, ninja. `configure.py` downloads dtk, objdiff-cli, binutils and sjiswrap into `build/tools`.
- Windows. Elsewhere, pass `--wrapper` (wibo/wine) to `configure.py`.

## Build

```
python configure.py
ninja
```

`ninja` splits the DOL, compiles everything under `src/` that's marked `Matching`, links, and checks the result against the original SHA-1. A green `mm9-game.dol: OK` means the rebuilt DOL is byte-identical.

The baseline links from split original objects for everything not yet decompiled, so the DOL check passes from the start. That's binary reproduction, not decompilation progress; progress is the share of code built from `src/`.

## Progress

```
ninja progress
python tools/webui.py      # dashboard at http://127.0.0.1:8099/
```

The dashboard shows game-code progress, a per-function map (one clickable cell per function, optionally scaled by size), a filterable function list, near misses with their best match %, per-function diffs with source, and worker logs from `build/opencode/`. Its build button runs `tools/twins.py`, `tools/sync_units.py`, `configure.py` and `ninja`. Compiling near misses live in `src/game/` as `NonMatching` units, so the report's fuzzy % counts partial work.

Tracked on [bytematch.dev](https://bytematch.dev/), which reads the `WR9E_report` artifact from CI on `main`. CI (`.github/workflows/build.yml`) builds and checks the DOL inside a private container that holds the retail DOL and the Wii/1.0 compiler, so the report updates on every push.

## Layout

| Path | |
|---|---|
| `config/WR9E/` | dtk config, `symbols.txt`, `splits.txt`, expected SHA-1 |
| `src/game/` | matched game functions, one `unit_<addr>.c` per function for now |
| `src/revolution/` | Revolution SDK sources imported from doldecomp/ogws (CC0); see `docs/SDK.md` |
| `include/` | `types.h`, shared partial structs in `include/game/`, minimal SDK headers |
| `tools/funcdiff.py` | compile one file, diff a function with objdiff and a capstone-backed link check |
| `tools/sync_units.py` | register every exactly-matching unit with the build |
| `tools/twins.py` | match copies of already matched functions |
| `tools/permute.py` | retry parked near misses with declaration/statement reorders |
| `tools/webui.py` | progress dashboard |
| `docs/` | `STATUS.md`, `COMPILER.md`, `MATCHING.md`, `SYMBOLS.md`, `SDK.md` (library ranges, progress categories, library source); `docs/dtk/` is dtk-template's reference |

## Limitations

- Original translation units aren't recovered yet, so source is split per function. See `docs/MATCHING.md`.
- No symbols or map exist for the game code; names are addresses until proven otherwise.
- Almost all library code (NW4R, the RVL SDK, MSL, MetroTRK, HOME Button, network) is still original objects. Progress is reported per library; some ranges are still `Unclassified`. See `docs/SDK.md`.
