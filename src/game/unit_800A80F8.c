#include "types.h"

typedef struct Unk800A80F8Slot {
    /* 0x0 */ u8 pad0[0xC];
    /* 0xC */ void* data;
} Unk800A80F8Slot;

typedef struct Unk800A80F8 {
    /* 0x000 */ u8 unk0;
    /* 0x001 */ u8 unk1;
    /* 0x002 */ u16 unk2;
    /* 0x004 */ u8 unk4;
    /* 0x005 */ u8 unk5;
    /* 0x006 */ u16 unk6;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 unk9;
    /* 0x00A */ u8 unkA;
    /* 0x00B */ u8 unkB;
    /* 0x00C */ u16 unkC;
    /* 0x00E */ u16 unkE;
    /* 0x010 */ Unk800A80F8Slot slotsA[0x60];
    /* 0x610 */ Unk800A80F8Slot slotsB[0x60];
    /* 0xC10 */ u8 mapA[0x280];
    /* 0xE90 */ u8 mapB[0x280];
} Unk800A80F8;

void fn_800A80F8(Unk800A80F8* p, u16 arg1) {
    s32 i;

    p->unk0 = 0;
    p->unk1 = 0;
    p->unk6 = arg1;
    p->unk2 = 0;
    p->unkC = 0;
    p->unk4 = 0;
    p->unk5 = 0;
    p->unkA = 0;
    p->unkB = 0;
    p->unk8 = 0;
    p->unk9 = 0;
    p->unkE = 0x210;
    for (i = 0; i < 0x280; i++) {
        p->mapA[i] = 0xFF;
        p->mapB[i] = 0xFF;
    }
    for (i = 0x40; i < 0x60; i++) {
        p->slotsA[i].data = NULL;
    }
    for (i = 0x40; i < 0x60; i++) {
        p->slotsB[i].data = NULL;
    }
}
