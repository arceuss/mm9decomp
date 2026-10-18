# Libraries and progress categories

Everything outside the game range (0x8000BF80..0x800EB1CC) is library code: the
Revolution SDK, NW4R, MSL and the PPCEABI runtime, MetroTRK, the HOME Button
library and the network middleware. This page records where each library sits in
the DOL, how sure we are about it, and how library source gets verified and linked.

## Progress categories

`configure.py` defines one progress category per owner. Every `.text` byte of the
DOL sits in exactly one category: the category totals add up to the `All` line of
`ninja progress` (2399356 code bytes, 8277 functions at the time of writing).

| Category | id | Covers |
|---|---|---|
| Game Code | `game` | 0x8000BF80..0x800EB1CC |
| Revolution SDK | `revolution` | 0x800EB1CC..0x80168BCC, NCD/SO pockets in the network area |
| NintendoWare (NW4R) | `nw4r` | 0x8018320C..0x801B6180 |
| C/C++ Runtime | `runtime` | `.init` runtime code, MSL 0x8016DA58..0x8018231C, PPCEABI 0x8018231C..0x80182C10 |
| MetroTRK | `metrotrk` | `.init` vector table, 0x80168BCC..0x8016DA58 |
| HOME Button | `homebutton` | 0x801B6180..0x801D3B1C |
| Network Libraries | `network` | DWC/GameSpy, NHTTP/NWC24, SSL/EC ranges listed below |
| Unclassified | `unclassified` | ranges whose owner isn't proven yet |

Unmatched code only counts toward a category if it sits in an object that
`configure.py` lists. Two kinds of source-less split exist for that:

- `game/unsplit_XXXXXXXX.c`: game `.text` that no `src/game` unit covers yet.
  `tools/sync_units.py` regenerates them with the unit list, so they always fill
  the gaps between units exactly.
- `<library>/unsplit_XXXXXXXX.c`: coarse library ranges, maintained by hand in
  `config/WR9E/splits.txt` after the game block (sync_units leaves that part and
  every non-game lib in `configure.py` alone).

Both are `.text` only and link the original bytes. The coarse library splits are an
accounting device, not translation units: when real library source arrives, carve
its TU out of the coarse split (OSArena below is the example).

Data isn't categorized yet. Library `.data`/`.rodata`/`.bss` stays in dtk's auto
splits, so category data totals only cover the objects that own data (game jump
tables, OSArena's statics). The `All` data line still covers everything.

Before this change `Game Code` only counted registered units and read ~88%. With the
gap splits it covers all 2934 game functions, so the number dropped to the real
figure (28% at the time of the switch). Nothing got unmatched.

## Range evidence

Boundaries are function starts from `symbols.txt`. Evidence comes from named
symbols, version strings, string references, call-graph edges and function pointers
in each library's data.

| Range | Category | Evidence |
|---|---|---|
| `.init` 0x80004000..0x80004338 | runtime | `__start`, `__init_registers`, `__init_data`, `__init_hardware`, `__flush_cache` |
| `.init` 0x80004338..0x8000626C | metrotrk | `gTRKInterruptVectorTable` .. `gTRKInterruptVectorTableEnd` |
| `.init` 0x8000626C..0x800065EC | runtime | `memcpy`, `__fill_mem`, `memset` (`__mem.c`). The linker tables `_rom_copy_info`/`_bss_init_info` after it stay unsplit. |
| 0x800EB1CC..0x80167E3C | revolution | named EXI/SI/OS/DVD/VI/PAD/GX/IPC/NAND/SC/ESP symbols; BTE (`BTM_`, `L2CAP`, `SDP`, `bta_`), WPAD/WUD and USB strings |
| 0x80167E3C..0x80168BCC | revolution | called from BTE/WPAD and from `gdev_cc_*`; the latter are the NdevExi2AD debugger driver, which ogws files under the RVL SDK |
| 0x80168BCC..0x8016DA58 | metrotrk | `gdev_cc_initialize`, `TRK*` symbols; 0x8016D98C..0x8016DA54 are MetroTRK's MSL support stubs (called from `_fseek`) |
| 0x8016DA58..0x8018231C | runtime | MSL C (`_fseek`, `__pformatter`, `sprintf`, `strcpy`, `wcstombs`) and MSL C++ (extab-covered 0x8017D4D0..0x8018224C) |
| 0x8018231C..0x80182C10 | runtime | `__init_cpp_exceptions`, `__va_arg`, `__register_global_object`, `__save_fpr`, `__div2u`, `__mod2u` plus four small helpers called from all over |
| 0x80182C10..0x8018320C | unclassified | a 0x4A8 helper called from NW4R and static initializers; owner not proven |
| 0x8018320C..0x801B6180 | nw4r | `snd_*.cpp`, `ut_*.cpp`, `db_*.cpp` assertion file names, `NW4R:` assertion strings |
| 0x801B6180..0x801D3B1C | homebutton | functions referenced from HBM data (vtables next to `nw4hbm::lyt::*` RTTI, `<< RVL_SDK - HBM`), `HomeButtonSe.wt`; 0x801B6180 is the first function called only from HBM code |
| 0x801D3B1C..0x801E2EEC | unclassified | AX synth/sequence code driven by the HBM sound player, then the RVL CNT library (`<< RVL_SDK - CNT` at 0x801E24EC, CNT calls from the game). Mixed owners. |
| 0x801E2EEC..0x8022290C | network | DWC init (`<< RVL_SDK - DWC`), GameSpy GP/QR2/NN strings, `nintendowifi.net` hosts |
| 0x8022290C..0x80225738 | unclassified | between the last DWC and first NCD evidence |
| 0x80225738..0x80226424 | revolution | `NCDGetCurrentIfConfig`, `ncdsystem.c`, `SOStartup` errors |
| 0x80226424..0x80227270 | unclassified | between SO and NHTTP evidence |
| 0x80227270..0x8022F87C | network | NHTTP (`<< RVL_SDK - NHTTP`, `HTTP/`), NWC24 (`NWC24*`, `/dev/net/kd`) |
| 0x8022F87C..0x8022FB4C | unclassified | between NWC24 and SO evidence |
| 0x8022FB4C..0x802306C0 | revolution | SO (`/dev/net/ip/top`) |
| 0x802306C0..0x80232024 | unclassified | between SO and SSL evidence |
| 0x80232024..0x80253614 | network | SSL (`/dev/net/ssl`), EC/ECDK (`EC_*`, `ec::*`, ECommerce SOAP URLs) |

String evidence here comes from a lis/addi scan, which has false hits (a few `NW4R`
strings showed up inside BTE functions). Those were checked against the call graph
before trusting them.

## Library source

Library sources live under `src/<library>/` mirroring the reference project's
layout, with minimal headers under `include/`. Only reconstructed, freely licensed
sources are imported; nothing leaked.

| File | Source | License | Status |
|---|---|---|---|
| `src/revolution/OS/OSArena.c` | doldecomp/ogws `src/revolution/OS/OSArena.c` @ 4f8b3383, unchanged | CC0-1.0 | Matching, linked from source |
| `include/revolution/OS.h`, `include/revolution/OS/OSArena.h`, `include/macros.h` | trimmed from the same ogws revision | CC0-1.0 | headers |
| `src/revolution/OS/OSMessage.c` | doldecomp/ogws `src/revolution/OS/OSMessage.c` @ 4f8b3383, unchanged | CC0-1.0 | Matching, linked from source. `.text` 0x800F563C..0x800F5910, no data; byte-identical with GC/3.0a5 + `cflags_rvl` |
| `include/revolution/OS/OSMessage.h`, `OSThread.h`, `OSInterrupt.h` | trimmed from the same ogws revision | CC0-1.0 | headers |
| `src/revolution/OS/OSMutex.c` | doldecomp/ogws `src/revolution/OS/OSMutex.c` @ 4f8b3383, plus `OSInitCond`/`OSWaitCond`/`OSSignalCond` written for this SDK build (ogws doesn't have them) | CC0-1.0 (ogws part) | Matching, linked from source. `.text` 0x800F6124..0x800F650C |
| `include/revolution/OS/OSMutex.h`, `OSThread` struct in `OSThread.h` | trimmed from the same ogws revision; `OSContext` kept opaque | CC0-1.0 | headers |

### OSArena

`revolution/OS/OSArena.c` covers `.text` 0x800EFF7C..0x800F0010 (13 functions),
`.sdata` 0x804ED450..0x804ED458 (`__OSArenaLo`, `s_mem2ArenaLo`) and `.sbss`
0x804EEA20..0x804EEA28 (`__OSArenaHi`, `s_mem2ArenaHi`). Function order and
statics match ogws exactly. The three unnamed functions at 0x800EFFBC,
0x800EFFD4 and 0x800EFFDC were named `OSSetArenaHi`, `OSSetArenaLo` and
`OSAllocFromMEM1ArenaLo` in `symbols.txt` after they byte-matched.

Built with the `RVL_SDK` lib: GC/3.0a5 and ogws's `cflags_rvl`
(`cflags_base` + `-fp_contract off -ipa file`). GC/3.0, GC/3.0a3 and Wii/1.0 produce
the same bytes for this file, so OSArena doesn't pin down the SDK compiler. The SDK's
version strings carry `0x4199_60831` (HBM and NHTTP: `0x4199_60726`); test the
compiler again on a TU with real codegen choices.

Verification, all from `C:\mm9decomp` after `python configure.py && ninja`:

```
python tools/funcdiff.py --lib RVL_SDK src/revolution/OS/OSArena.c \
    OSGetMEM1ArenaHi OSGetMEM2ArenaHi OSGetArenaHi OSGetMEM1ArenaLo OSGetMEM2ArenaLo \
    OSGetArenaLo OSSetMEM1ArenaHi OSSetMEM2ArenaHi OSSetArenaHi OSSetMEM1ArenaLo \
    OSSetMEM2ArenaLo OSSetArenaLo OSAllocFromMEM1ArenaLo
```

exits 0: objdiff 100% against dtk's original `obj/revolution/OS/OSArena.o`, every
relocation applied with original addresses equals the DOL, and the data check finds
all four statics at their original addresses and sizes with the original initial
bytes. The objdiff report marks the unit complete (148/148 code bytes, 16/16 data
bytes), `build.ninja` links `build/WR9E/src/revolution/OS/OSArena.o`, and the DOL
SHA-1 still matches.

## Adding the next library TU

1. Find the TU's exact `.text`/data ranges in `symbols.txt`, and every static it
   owns. Carve a named split for it out of the coarse `unsplit_*` split in
   `splits.txt` (shrink or split the coarse entry so nothing overlaps).
2. Add the source under `src/<library>/` with a provenance comment, and an
   `Object(NonMatching, ...)` in the right lib in `configure.py`. Run
   `python configure.py && ninja` once so dtk writes the original object and
   `build.ninja` gets a compile edge.
3. `python tools/funcdiff.py --lib <LIB> <source> <functions...>`. Use
   `--mw-version` and `--extra-cflags` for compiler/flag experiments; they don't
   touch the build. Rename `fn_*` symbols to their real names only after they match.
4. Only when every function and static passes, switch the object to `Matching`,
   rebuild and check the SHA-1. Functions that link-check but aren't referenced by
   anything may need `force_active`; `tools/sync_units.py` owns that block in
   `config.yml`, so pin library functions there through sync_units if it comes up.

Partial results stay `NonMatching`. A file where 5 of 30 functions match is a
research result, not a linkable TU.
