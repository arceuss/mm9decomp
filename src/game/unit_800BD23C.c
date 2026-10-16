#include "types.h"

typedef struct Unk800BD23C {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x10 - 0xB];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0x18 - 0x16];
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[0x34 - 0x1C];
    /* 0x34 */ u8* unk34;
    /* 0x38 */ u8 pad38[0xC8 - 0x38];
    /* 0xC8 */ u8 unkC8;
} Unk800BD23C;

extern s32* lbl_8027F228[];

void fn_800E9244(Unk800BD23C* p);

void fn_800BD23C(Unk800BD23C* p) {
    s32 v;
    s32 off;
    u8* t;
    u8* s;

    p->unk18 = lbl_8027F228[p->unk9][4];
    p->unk10 = 4;
    p->unk11 = 0;
    p->unk12 = 0;
    p->unk13 = 0;
    fn_800E9244(p);
    p->flagsA &= ~1;
    s = p->unk34 + 0x1F8;
    v = s[0] - p->unkC8;
    if (v < 0) {
        v = 0;
    }
    s[0] = v;
    off = p->unk15;
    s[2] &= ~(1 << off);
    t = s + off;
    t[4] = 0xFF;
    t[8] = 0xFF;
}
