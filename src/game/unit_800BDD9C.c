#include "types.h"

typedef struct Unk800BDD9CSub {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ s16 unk10;
    /* 0x12 */ s16 unk12;
} Unk800BDD9CSub;

typedef struct Unk800BDD9CVec {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
} Unk800BDD9CVec;

typedef struct Unk800BDD9C {
    /* 0x00 */ u8 pad0[0x8];
    /* 0x08 */ s8 unk8;
    /* 0x09 */ u8 pad9;
    /* 0x0A */ u8 unkA;
    /* 0x0B */ u8 padB;
    /* 0x0C */ u8 unkC;
    /* 0x0D */ u8 padD[0x10 - 0xD];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 pad11[0x14 - 0x11];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15[0x88 - 0x15];
    /* 0x88 */ Unk800BDD9CSub* unk88;
    /* 0x8C */ u8 pad8C[0x90 - 0x8C];
    /* 0x90 */ s32* unk90;
} Unk800BDD9C;

extern u8 lbl_80304B90[];

s32 fn_80080484(void* a0, void* a1, s32 a2);

s32 fn_800BDD9C(Unk800BDD9C* a0, Unk800BDD9CVec* a1) {
    Unk800BDD9CSub* s;
    s32 x;
    s32* q;
    s32 y;
    s32 v;

    if ((a0->unkA & 1) == 0) {
        return 0;
    }
    if ((a0->unkA & 4) == 0) {
        return 0;
    }
    if (a0->unkC & 0x10) {
        return 0;
    }
    if (a0->unk10 >= 2) {
        return 0;
    }
    if (a0->unk8 == 0xA && ((1 << a0->unk14) & 0x19F) == 0) {
        return 0;
    }
    q = a0->unk90;
    x = q[0];
    y = q[1];
    a1->unk4 = y;
    a1->unk0 = x;
    s = a0->unk88;
    if (s != NULL) {
        v = s->unk10;
        if (a0->unkA & 0x10) {
            v = -v;
        }
        a1->unk0 += v;
        v = s->unk12;
        if (a0->unkA & 0x20) {
            v = -v;
        }
        a1->unk4 += v;
    }
    if ((u32)fn_80080484(lbl_80304B90 + 0x21C, a1, 1) > 0x800) {
        return 0;
    }
    return 1;
}
