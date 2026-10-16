#include "types.h"

typedef struct Unk800BFEB4 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 unkA;
    /* 0x0B */ u8 padB[0x10 - 0xB];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 pad14[0x16 - 0x14];
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[0x24 - 0x1C];
    /* 0x24 */ u16 unk24;
    /* 0x26 */ u8 pad26[0x38 - 0x26];
    /* 0x38 */ struct Unk800BFEB4* unk38;
    /* 0x3C */ u8 pad3C[0x60 - 0x3C];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0x70 - 0x68];
    /* 0x70 */ s32 unk70;
    /* 0x74 */ s32 unk74;
} Unk800BFEB4;

extern s32* lbl_8027F228[];

void fn_800E9424(Unk800BFEB4* p, s32 a1);
void fn_800E946C(Unk800BFEB4* p, s32 a1);
void fn_800E9244(Unk800BFEB4* p);
void fn_800E9750(Unk800BFEB4* p, u16 a1);

void fn_800BFEB4(Unk800BFEB4* p) {
    Unk800BFEB4* q = p->unk38;

    switch (p->unk12) {
    case 0:
        if (p->unk24 != 0x105) {
            fn_800E9424(p, 0x105);
        }
        p->unk16 = 0;
        fn_800E946C(p, 0);
        p->unk12 = p->unk12 + 1;
        /* FALLTHROUGH */
    case 1:
        if (q->unk10 >= 2) {
            p->unkA &= ~1;
            p->unkA &= 0xFD;
            fn_800E9244(p);
            p->unk18 = lbl_8027F228[p->unk9][3];
            p->unk10 = 3;
            p->unk11 = 0;
            p->unk12 = 0;
            p->unk13 = 0;
            break;
        }
        /* FALLTHROUGH */
    default:
        p->unk60 = q->unk60 + p->unk70;
        p->unk64 = q->unk64 + p->unk74;
        fn_800E9750(p, 0xFFFF);
        break;
    }
}
