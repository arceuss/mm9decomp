# Matching workflow

## Build and compare

```
python configure.py          # writes build.ninja + objdiff.json, downloads dtk/objdiff/binutils/sjiswrap
ninja                        # split the DOL, compile, link, SHA-1 check, objdiff report
ninja progress               # print progress again
python tools/webui.py        # dashboard on http://127.0.0.1:8099/
```

`ninja` fails at the `CHECK` step if the linked DOL isn't byte-identical to `game/base/mm9-game.dol` (SHA-1 `8a7c0c2daa65fb3dcd5176922335cf3b999cd940`). Every source unit marked `Matching` is linked into that DOL, so a passing check proves all linked units together.

objdiff GUI: open the project root; it reads `objdiff.json`.

## One function at a time

1. Pick a `fn_XXXXXXXX` from `config/WR9E/symbols.txt`; its disassembly is in `build/WR9E/asm/*.s`.
2. Write `src/game/unit_XXXXXXXX.c` containing only that function. Reference data as `extern lbl_...`, declare callees locally or via `include/game/*.h`.
3. `python tools/funcdiff.py src/game/unit_XXXXXXXX.c fn_XXXXXXXX` compiles with the exact game flags (read from `build.ninja`) and runs two checks: an objdiff diff against the original, and a link check that applies the object's relocations with the original symbol addresses and compares the bytes with the DOL (capstone shows any differing instructions). Exit 0 only when both pass. Needs `pip install capstone pyelftools`.
4. `python tools/sync_units.py` re-checks every `src/game/unit_*.c`, then regenerates the game blocks in `config/WR9E/splits.txt` and `configure.py` from the files that match.
5. `python configure.py && ninja` links them and runs the SHA-1 check.

`funcdiff.py --mw-version Wii/1.0RC1 ...` compiles with another installed compiler instead of the game's, for compiler comparisons.

If `ninja` fails with "a file with a user-mapped section open" while workers are running funcdiff, objdiff had a split object mapped during the re-split. Run `ninja` again.

## Near misses

Park a non-matching best attempt as `build/<you>/nonmatching/unit_XXXXXXXX.c`; the dashboard lists them with their match %. `python tools/permute.py --all [--write]` retries every parked attempt with declaration reorders and adjacent simple-statement swaps (the decomp-permuter idea, limited to rewrites that keep the source plausible) and writes matches to `src/game/` with `--write`. Read what it changed: swapping two stores through possibly-aliasing pointers isn't always behaviour-preserving.

Files that compile but don't match yet stay in `src/game/` and `sync_units.py` registers them as `Object(NonMatching, ...)`, the same way ogws does it: dtk links the original split object in their place, so the DOL check is unaffected, and objdiff scores them for the fuzzy progress number that shows up on bytematch.dev. Files that don't compile are skipped. When an attempt in `build/<you>/nonmatching/` beats the one in `src/game/`, copy it over.

## Twins

`python tools/twins.py` matches functions whose dtk disassembly is identical to an already matched one once symbol names are abstracted. It copies the twin's source with the names swapped, keeps it only if `funcdiff.py` passes, and leaves registration to `sync_units.py`. Run it after every batch of new matches: the game has a lot of copy-pasted per-object code (the first run turned 148 matches into 262). The idea comes from decomp.wtf's "autopilot".

`python tools/twins.py --imm` also accepts twins that differ in trailing immediates (`li`, `addi`, `cmpwi`, ..., never `d(rA)` offsets). Each differing value is swapped for a literal of the same value inside the twin's function body only, so struct offsets in the local types stay put. Every candidate twin with the same shape is tried until one passes `funcdiff.py`. The autoloop runs this mode.

## Why single-function units

The original translation-unit boundaries aren't recovered yet. A unit per function is the smallest split that links in place without guessing TU contents. Units are named after their address so they can be merged once real TUs are known. Merging is required before static functions, file-local tables and string pools can be reconstructed as the original source had them.

TU boundary evidence collected so far:
- Many object types end with the same pair: a draw function `if (obj->flags14 & 1) fn_800C7608(obj);` and an update `table[obj->state](obj);` with a per-type state table in `.sdata` or `.data`. Those tables are per-file statics in all likelihood, so each pair marks the tail of one object TU. See `include/game/stateobj.h`.
- Game code has no alignment padding between functions, so `.text` gaps can't be used to find boundaries (see COMPILER.md).

## Rules that bit us

- **Small data:** mwcc uses `@sda21` only for externs whose size is known and <= 8 bytes. Declare one-entry state tables as `extern StateObjFunc lbl_804EC724[1];`, not `[]`. Arrays the original reaches via `lis/addi` must stay unsized or larger than 8.
- **Function-pointer table calls through `bctr`:** dtk's analyzer took some of them for jump tables and failed on the second split pass. The fix was setting the table symbol's real size in `symbols.txt` (lbl_80263F18 and eight others). If a split fails with "Invalid jump table entry", do the same.
- **Tail calls:** `if (cond) fn(obj);` as the last statement compiles to `beqlr; b fn; blr` (the dead `blr` is real compiler output).
- **List walk:** the game's linked-list iterator is `while ((n = l->cur = l->cur->next) != &l->head)`; writing `l->cur` without the temporary changes register allocation.
- **Switch jump tables:** mwcc puts the table in the unit's own `.data` as a local `@N`. `sync_units.py` gives the unit the `jumptable_` range from `symbols.txt`, and `funcdiff.py`'s link check verifies the table bytes too (objdiff only disagrees on the symbol name until the unit owns the table). mwcc aligns `.data` to 8, so a table at an address that's 4 mod 8 would get padding in front; those units are registered `NonMatching` (matched, not linked) until their original TU's data is rebuilt around them.
- **Deadstripping:** mwld drops compiled functions that nothing in the link references (an empty `blr` function at 0x80041E98 vanished and shifted `.text`). `sync_units.py` lists every unit function under `force_active` in `config/WR9E/config.yml`; dtk drops `force_active` from `symbols.txt` when it rewrites it, so it can't live there.
- **Phantom `blr` functions:** a function that has a plain `return` and ends in a tail dispatch (`... bctr`) gets its exit `blr` emitted after the `bctr`. dtk split that dead `blr` off as a separate 4-byte `fn_` symbol, so the real function looked one instruction short and no source shape could match it. The fix is in `symbols.txt`: grow the predecessor by 4 and delete the 4-byte symbol (done for fn_800D6C24, fn_800D73D4, fn_800D7E98, fn_800D9114, fn_800DBE6C). Other candidates: 4-byte `blr` symbols right after a function that ends in a tail call and has an earlier `blr` (fn_80041D28/fn_80041E98, fn_80042048/fn_80042140, plus fn_8018A45C, fn_801C9F2C, fn_801C9F54, fn_80236964 outside the game range).
- **Const tables:** when the target loads a table entry *before* stores that precede the read in any sensible source (typically `obj->state = table[obj->unk14];` right after the mode-set stores), the table is `extern const`. mwcc hoists loads from const objects over stores that might alias; a plain `extern` load stays in source order.
- **`__abs`:** `srawi rT,rX,31; xor; subf` is the `__abs(x)` builtin.
- **Struct copies:** an 8-byte position copied as `lwz 4; lwz 0; stw 0; stw 4` (high word loaded first) is a struct assignment (`a->pos = b->pos;`), not two field assignments.
- **Declaration order:** mwcc's register coloring depends on the order locals are declared. A pure register swap between two locals is usually fixed by reordering declarations, not statements.
- **Inlines block CSE:** loads and address math inside an inlined `static inline` aren't merged with the caller's. A target that recomputes a global's address or re-reads a field it already has is calling an inline there (the three `Free()` calls in fn_80026EDC, the save-flag test/set helpers in fn_800E5274 and siblings).
- **`char` vs `u8`:** `lbz` + `cmpwi` against a constant is a plain `char` field; `u8` compiles to `cmplwi`. `clrlwi 28; cmplwi` is an unsigned 4-bit bitfield.
- **Negation and abs:** `x * -1` gives `slwi 1; subf`, `-x` gives `neg`. Two unmerged abs range checks are the ternary `(d < 0 ? -d : d)`; `__abs` gets range-merged.
- **Forwarded parameters:** a register the function never writes but passes to a callee is one of its own parameters, so both signatures grow an argument.
- **Fill loops:** the game's memset-alikes index with `*(u16*)((u32)dst + i)`; `dst[i]`, `(u8*)dst + i` and `i + dst` all allocate or order differently.
- **Static table anchors:** the per-boss update functions load several state tables as offsets from one `lis/addi` base (`addi r4, r31, 0x4c`). That's mwcc addressing file-local static arrays relative to the first one in the TU. It can't be reproduced from a single-function unit with `extern` tables (a struct of tables generates `lwz rX, off(base)` instead), so those functions wait for TU reconstruction.
- **String literals:** `-str reuse` puts literals in `.data` as local `@N` symbols; a single-function unit can't own them, so functions passing string literals wait for TU reconstruction too.

## What counts

Only functions where the compiled bytes match exactly (relocation targets compared by symbol) count. Inline asm, `.s` files and copied bytes don't count. Equivalent but different code doesn't count.
