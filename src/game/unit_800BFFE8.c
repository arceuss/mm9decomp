#include "types.h"

typedef struct Unk800BFFE8B {
    /* 0x000 */ u8 pad0[0x10C];
    /* 0x10C */ u8 unk10C;
} Unk800BFFE8B;

typedef struct Unk800BFFE8 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 unkA;
    /* 0x0B */ u8 padB[0x10 - 0xB];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15[0x18 - 0x15];
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[0x34 - 0x1C];
    /* 0x34 */ Unk800BFFE8B* unk34;
    /* 0x38 */ u8 pad38[0xCA - 0x38];
    /* 0xCA */ u8 unkCA;
} Unk800BFFE8;

extern u8 lbl_803051D8[];
extern u8 lbl_804ECF74[4];
extern void (*lbl_804ECF68[2])(Unk800BFFE8*);
extern s32* lbl_8027F228[];

void fn_800E9244(Unk800BFFE8* p);

s32 fn_800BFFE8(Unk800BFFE8* p) {
    if (p->unkCA != p->unk34->unk10C) {
        p->unkA &= ~1;
        p->unkA &= 0xFD;
        fn_800E9244(p);
        p->unk18 = lbl_8027F228[p->unk9][3];
        p->unk10 = 3;
        p->unk11 = 0;
        p->unk12 = 0;
        p->unk13 = 0;
        return 1;
    }
    if (lbl_803051D8[2] & 0x20) {
        p->unk18 = lbl_8027F228[p->unk9][2];
        p->unk10 = 2;
        p->unk11 = 0;
        p->unk12 = 0;
        p->unk13 = 0;
        p->unk18 = lbl_8027F228[p->unk9][4];
        p->unk10 = 4;
        p->unk11 = 0;
        p->unk12 = 0;
        p->unk13 = 0;
        fn_800E9244(p);
        p->unkA &= ~1;
        lbl_804ECF68[lbl_804ECF74[p->unk14]](p);
        return 1;
    }
    return 0;
}
