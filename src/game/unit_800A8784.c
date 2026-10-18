#include "types.h"

typedef struct Unk800A8784SlotA {
    /* 0x0 */ u8 pad0[0x8];
    /* 0x8 */ struct {
        u8 hi : 2;
        u8 b5 : 1;
        u8 lo : 5;
    } f;
    /* 0x9 */ u8 pad9[0x10 - 0x9];
} Unk800A8784SlotA;

typedef struct Unk800A8784SlotB {
    /* 0x0 */ u8 pad0[0x4];
    /* 0x4 */ struct {
        u8 hi : 3;
        u8 b4 : 1;
        u8 lo : 4;
    } f;
    /* 0x5 */ u8 pad5[0x10 - 0x5];
} Unk800A8784SlotB;

typedef struct Unk800A8784 {
    /* 0x000 */ u8 pad0[0x2];
    /* 0x002 */ u16 unk2;
    /* 0x004 */ u8 unk4;
    /* 0x005 */ u8 unk5;
    /* 0x006 */ u8 pad6[0xA - 0x6];
    /* 0x00A */ u8 unkA;
    /* 0x00B */ u8 unkB;
    /* 0x00C */ u16 unkC;
    /* 0x00E */ u16 unkE;
    /* 0x010 */ Unk800A8784SlotA slotsA[0x60];
    /* 0x610 */ Unk800A8784SlotB slotsB[0x60];
    /* 0xC10 */ u8 idxA[0x280];
    /* 0xE90 */ u8 idxB[0x280];
} Unk800A8784;

void fn_800A8784(Unk800A8784* obj) {
    s32 i;

    obj->unkC = obj->unk2;
    obj->unkA = obj->unk4;
    obj->unkB = obj->unk5;
    for (i = 0x210; i < 0x280; i++) {
        obj->idxA[i] = 0xFF;
        obj->idxB[i] = 0xFF;
    }
    obj->unkE = 0x210;
    for (i = 0x40; i < 0x60; i++) {
        obj->slotsA[i].f.b5 = 0;
    }
    for (i = 0x40; i < 0x60; i++) {
        obj->slotsB[i].f.b4 = 0;
    }
}
