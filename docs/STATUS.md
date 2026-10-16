# Status

Live numbers: `ninja progress` or the dashboard (`python tools/webui.py`). This file records the state at the end of the last working session and what's known about the binary.

## Binary

| | |
|---|---|
| File | `game/base/mm9-game.dol`, from content 1 of the US WAD (title `WR9E`) |
| SHA-1 | `8a7c0c2daa65fb3dcd5176922335cf3b999cd940` |
| SHA-256 | `c339f975843ebef5730d778b42c5aa4c3b250e91ce841332958e3f532777a985` |
| Entry | `0x8000403C` (`__start`) |
| `main` | `0x8009DB00` |

| Section | Address | Size | File offset |
|---|---|---|---|
| .init | 0x80004000 | 0x2690 | 0x100 |
| extab | 0x800066A0 | 0x44D4 | 0x249E40 |
| extabindex | 0x8000AB80 | 0x1400 | 0x24E320 |
| .text | 0x8000BF80 | 0x247694 | 0x27A0 |
| .ctors | 0x80253620 | 0x58 | 0x24F720 |
| .dtors | 0x80253680 | 0xC | 0x24F780 |
| .rodata | 0x802536C0 | 0xE4A0 | 0x24F7A0 |
| .data | 0x80261B60 | 0x5C128 | 0x25DC40 |
| .bss | 0x802BDCC0 | 0x22E9A0 | - |
| .sdata | 0x804EC660 | 0x1FFC | 0x2B9D80 |
| .sbss | 0x804EE660 | 0xE28 | - |
| .sdata2 | 0x804EF4A0 | 0xDA8 | 0x2BBD80 |
| .sbss2 | 0x804F0260 | 0x14 | - |

`_SDA_BASE_` 0x804F4660, `_SDA2_BASE_` 0x804F74A0.

## Code layout

| Range | Contents |
|---|---|
| 0x8000BF80..~0x800D4000 | game code, plain C. No vtables, no exception tables, almost no floats. Per-object-type files end in update/draw pairs (see MATCHING.md). |
| ~0x800D4000..0x800EB1CC | C++-ish game layer: nw4r `LinkList.h` inlines, static constructor at 0x800D4F24, object pools (`fn_800E8C44`), main-loop helpers |
| ~0x80168BCC.. | MetroTRK, MSL C/C++ (extab-covered 0x8017D4D0..0x8018224C), PPCEABI runtime |
| ~0x80183000..0x80253614 | NW4R SND (May 2008), HBM, EC/DWC/NHTTP/SSL network libraries (extab-covered from 0x80234C10) |

Found so far: the game's frame loop is `fn_8008C004` (dispatches `lbl_80273618[lbl_803140C0.state]` every frame) and `fn_8009DC28` is part of game initialisation.

Object code is organised per type: a spawner (`fn_800E8C44(pool)` plus the common init stores), a mode setter that loads `table[type]->modeN` into `+0x18`, an update that dispatches a state table, hit callbacks reading `hit->obj`/`hit->other->obj`, and one or more death handlers that spawn an explosion (`fn_80040AD0`) and switch to mode 4. Each boss/enemy group has its own type table (`lbl_802638A0`, `lbl_80265138`, `lbl_80270168`, `lbl_80280390`, ...).

## Matching

At the end of session 2 (see `ninja progress` for the current state):

| | |
|---|---|
| Game functions (0x8000BF80..0x800EB1CC) | 2941, 913996 bytes |
| Functions in `src/game/` with exact match | 1760 registered (1757 linked, 3 jump-table units matched but unlinked) |
| Linked into the DOL | all of them except jump-table units whose table sits at a 4-mod-8 address |
| Rebuilt DOL | byte-identical (`ninja` SHA-1 check passes) |
| Translation units fully matched | none yet: units are single functions, original TU boundaries aren't recovered |
| Library code | not started; everything outside the game range links from split original objects |

All non-game code and every unmatched game function still comes from the original bytes (dtk split objects). That's the binary baseline, not decompilation progress. Most matched functions are small (spawners, mode setters, hit callbacks, death handlers); large state handlers are mostly still open.

## Known gaps

- TU boundaries are unknown. Merging units into real files is needed before `.data`/`.rodata`/`.sdata` owned by game files can be matched and before static functions can be written as statics.
- Blocked on TU reconstruction: per-boss update functions that address several static state tables from one base register, functions passing string literals, and functions using `.sdata2`/`.rodata` float or table initializers (local `@N` symbols). See MATCHING.md.
- Jump-table units at 4-mod-8 table addresses stay unlinked (`NonMatching` in configure.py, matched in the report).
- Compiler build: the Wii 4.2 builds 140 and 142 (and `Wii/0x4201_127`) produce identical code for all ~990 units tested; GameCube 4.2 builds don't. The exact Wii build is still open. See COMPILER.md.
- Register-allocation near misses: `fn_8008BF48`, `fn_8009B6FC`, `fn_800A5148` (99.8%), `fn_800856C4` and `fn_80054B40` are a few instructions short. Every compiling near miss is in `src/game/` as a `NonMatching` unit and counts toward the fuzzy number.
