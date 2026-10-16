#include "types.h"

typedef struct Unk800BBECC {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x10 - 0xB];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 pad14[0x18 - 0x14];
    /* 0x18 */ s32 unk18;
} Unk800BBECC;

extern s32* lbl_8027F228[];
extern void (*lbl_804ECEB4)(Unk800BBECC*);

void fn_800E9244(Unk800BBECC* p);

void fn_800BBECC(Unk800BBECC* p) {
    p->unk18 = lbl_8027F228[p->unk9][4];
    p->unk10 = 4;
    p->unk11 = 0;
    p->unk12 = 0;
    p->unk13 = 0;
    fn_800E9244(p);
    p->flagsA &= ~1;
    lbl_804ECEB4(p);
}
