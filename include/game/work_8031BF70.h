#ifndef GAME_WORK_8031BF70_H
#define GAME_WORK_8031BF70_H

#include "types.h"

// Big .bss work area (0x4CFE0 bytes). fn_8009E850/fn_8009E894 index unk8A8 as a
// 2D s16 grid (width unk8A4) with coordinates >> 12, so it looks like stage
// collision/tile data; not named until that's confirmed.
// 0x18-byte record at unk290. fn_800A5148 fills one: position from a base plus
// an offset, half extents, and a second position copied from a record with the
// same id in the list starting at unk290[32] (or the first position if none).
typedef struct Unk8031BF70_290 {
    /* 0x00 */ u16 id;
    /* 0x02 */ u16 unk2;
    /* 0x04 */ u16 unk4;
    /* 0x06 */ u16 unk6;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
} Unk8031BF70_290;

typedef struct Unk8031BF70Vec {
    s32 x;
    s32 y;
} Unk8031BF70Vec;

struct Unk8031BF70_288;
struct Unk8031BF70_20;

// Handler table reached through unk288->unk4; entries take a Unk8031BF70Vec* view origin.
typedef struct Unk8031BF70_288Funcs {
    /* 0x0 */ void (*unk0)(Unk8031BF70Vec* view);
    /* 0x4 */ void (*unk4)(Unk8031BF70Vec* view);
    /* 0x8 */ void* unk8;
    /* 0xC */ void (*unkC)(Unk8031BF70Vec* view);
} Unk8031BF70_288Funcs;

// Pointed to by unk288; only the fields matched code touches.
typedef struct Unk8031BF70_288 {
    /* 0x00 */ u32 unk0; // compared against unk28C
    /* 0x04 */ Unk8031BF70_288Funcs* unk4;
    /* 0x08 */ u8 pad8[0x10 - 0x8];
    /* 0x10 */ u8* unk10; // [2] map width and [3] map height, in screens
    /* 0x14 */ u8 pad14[0x24 - 0x14];
    /* 0x24 */ u32 unk24; // low bits merged into lbl_80301280.unk40->unk0
    /* 0x28 */ u8 pad28[0xF4 - 0x28];
    /* 0xF4 */ u8* unkF4; // byte [0] is a shift, rows start at +4
} Unk8031BF70_288;

// Four 0x94-byte records at unk20, each with optional callbacks.
typedef struct Unk8031BF70_20 {
    /* 0x00 */ void (*unk0)(struct Unk8031BF70_20* rec, Unk8031BF70_288* arg1);
    /* 0x04 */ u8 pad4[0x8 - 0x4];
    /* 0x08 */ void (*unk8)(struct Unk8031BF70_20* rec, Unk8031BF70_288* arg1);
    /* 0x0C */ u8 padC[0x94 - 0xC];
} Unk8031BF70_20;

typedef struct Unk8031BF70 {
    /* 0x00000 */ u8 pad0[0x20];
    /* 0x00020 */ Unk8031BF70_20 unk20[4];
    /* 0x00270 */ u16* unk270; // lookup table indexed by unk8A8 entries
    /* 0x00274 */ u8 pad274[0x280 - 0x274];
    /* 0x00280 */ s32 unk280;
    /* 0x00284 */ s32 unk284;
    /* 0x00288 */ Unk8031BF70_288* unk288;
    /* 0x0028C */ u16 unk28C; // id of the current fn_8009F5B8 result
    /* 0x0028E */ u8 unk28E; // number of valid unk290 records (at most 31)
    /* 0x0028F */ u8 unk28F; // number of records in the second list at unk290[32]
    /* 0x00290 */ Unk8031BF70_290 unk290[64]; // 64 is the most that fits before 0x898
    /* 0x00890 */ u8 pad890[0x898 - 0x890];
    /* 0x00898 */ u16 unk898;
    /* 0x0089A */ u16 unk89A;
    /* 0x0089C */ u16 unk89C;
    /* 0x0089E */ u16 unk89E;
    /* 0x008A0 */ u16 unk8A0;
    /* 0x008A2 */ u8 pad8A2[0x8A4 - 0x8A2];
    /* 0x008A4 */ u16 unk8A4; // grid width
    /* 0x008A6 */ u8 pad8A6[0x8A8 - 0x8A6];
    /* 0x008A8 */ s16 unk8A8[(0x4AEAC - 0x8A8) / 2];
    /* 0x4AEAC */ u16 unk4AEAC; // set to 1 after unk8A8 is rewritten (fn_8009EF24)
    /* 0x4AEAE */ u16 unk4AEAE;
    /* 0x4AEB0 */ s32 unk4AEB0;
    /* 0x4AEB4 */ s32 unk4AEB4;
    /* 0x4AEB8 */ s32 unk4AEB8;
    /* 0x4AEBC */ u8 pad4AEBC[0x4AEC0 - 0x4AEBC];
    /* 0x4AEC0 */ s32 unk4AEC0; // left/top/right/bottom limits, reset to 0,0,0x400000,0x380000
    /* 0x4AEC4 */ s32 unk4AEC4;
    /* 0x4AEC8 */ s32 unk4AEC8;
    /* 0x4AECC */ s32 unk4AECC;
    /* 0x4AED0 */ u8 pad4AED0[0x4CED8 - 0x4AED0];
    /* 0x4CED8 */ s32 unk4CED8; // incremented once per fn_8009E06C call
    /* 0x4CEDC */ s32 unk4CEDC;
    /* 0x4CEE0 */ s32 unk4CEE0;
    /* 0x4CEE4 */ s32 unk4CEE4;
    /* 0x4CEE8 */ s16 unk4CEE8;
    /* 0x4CEEA */ u8 pad4CEEA[0x4CEEC - 0x4CEEA];
    /* 0x4CEEC */ s32 unk4CEEC;
    /* 0x4CEF0 */ u8 pad4CEF0[0x4CFE0 - 0x4CEF0];
} Unk8031BF70;

extern Unk8031BF70 lbl_8031BF70;

#endif
