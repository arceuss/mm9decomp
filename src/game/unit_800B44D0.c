#include "types.h"

typedef struct Unk8027EB60Entry {
    /* 0x00 */ u8 pad0[0x1C];
    /* 0x1C */ s32 unk1C;
} Unk8027EB60Entry;

typedef struct Vec2i {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Vec2i;

typedef struct Unk800B44D0 {
    /* 0x000 */ u8 pad0[0x9];
    /* 0x009 */ u8 unk9;
    /* 0x00A */ u8 flagsA;
    /* 0x00B */ u8 padB[0x14 - 0xB];
    /* 0x014 */ u8 unk14;
    /* 0x015 */ u8 pad15[0x60 - 0x15];
    /* 0x060 */ Vec2i pos;
    /* 0x068 */ u8 pad68[0xC8 - 0x68];
    /* 0x0C8 */ u8 unkC8[0x104 - 0xC8];
    /* 0x104 */ u32 unk104;
    /* 0x108 */ u8 pad108[0x188 - 0x108];
    /* 0x188 */ u16 unk188;
    /* 0x18A */ u8 pad18A[0x18C - 0x18A];
    /* 0x18C */ u16 unk18C;
    /* 0x18E */ u8 pad18E[0x19C - 0x18E];
    /* 0x19C */ u8 unk19C[8];
} Unk800B44D0;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x2A0];
    /* 0x2A0 */ u16 unk2A0[4];
    /* 0x2A8 */ u8 pad2A8[0x300 - 0x2A8];
} Unk80304B90;

extern Unk80304B90 lbl_80304B90;
extern Unk8027EB60Entry* lbl_8027EB60[];

s32 fn_800B79D4(Unk800B44D0* p, s32 arg1, s32 arg2);
BOOL fn_800B9094(Vec2i* pos, void* box, void* bounds, s32 height, u32 facing);

BOOL fn_800B44D0(Unk800B44D0* p) {
    BOOL ok;
    Vec2i pos;

    if (p->unk104 & 0x1000) {
        return FALSE;
    }
    if (((1 << p->unk9) & 4) && !(lbl_80304B90.unk2A0[p->unk14] & 0x8000) && (p->unk188 & 2) && (p->unk18C & 0x20)) {
        ok = TRUE;
    } else {
        ok = FALSE;
    }
    if (ok) {
        pos = p->pos;
        if (fn_800B9094(&pos, p->unkC8, p->unk19C, fn_800B79D4(p, lbl_8027EB60[p->unk9]->unk1C, 0), (p->flagsA >> 4) & 1)) {
            return TRUE;
        }
    }
    return FALSE;
}
