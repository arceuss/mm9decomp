#include "types.h"
typedef struct Unk80068F7C {
    /* 0x00 */ u8 pad00[0x11];
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 unk17;
    /* 0x18 */ u8 pad18[0x38 - 0x18];
    /* 0x38 */ struct Unk80068F7C* unk38;
    /* 0x3C */ u8 pad3C[0x60 - 0x3C];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ u8 pad64[0x7D - 0x64];
    /* 0x7D */ u8 unk7D;
    /* 0x7E */ u8 pad7E[0x88 - 0x7E];
    /* 0x88 */ u8 unk88[1];
} Unk80068F7C;
extern u8 lbl_804ECC34[4], lbl_804ECC38[4], lbl_804ECC3C[4], lbl_804ECC40[4];
extern u8 lbl_80267F58[], lbl_80267F88[];
extern s32 lbl_80304B90[];
extern void fn_800E946C(Unk80068F7C*, s32);
extern void fn_8009996C(void*, void*);
extern void fn_800E9750(Unk80068F7C*, u16);
void fn_80068F7C(Unk80068F7C* p) {
    switch (p->unk12) {
    case 0:
        fn_800E946C(p, lbl_804ECC38[p->unk14]);
        fn_8009996C(p->unk88, lbl_80267F58);
        p->unk16 = 8;
        p->unk12++;
    case 1:
        if (p->unk16 == 0) p->unk12++; else p->unk16--;
        break;
    case 2:
        fn_800E946C(p, lbl_804ECC3C[p->unk14]);
        p->unk16 = 20;
        p->unk17 = 0;
        p->unk12++;
    case 3:
        if (p->unk17 == 0 && p->unk7D == 1) {
            fn_8009996C(p->unk88, lbl_80267F88);
            p->unk17++;
        }
        if (p->unk16 == 0) p->unk12++; else p->unk16--;
        break;
    case 4:
        fn_800E946C(p, lbl_804ECC40[p->unk14]);
        p->unk16 = 8;
        p->unk12++;
    case 5:
        if (p->unk16 == 0) p->unk12++; else p->unk16--;
        break;
    case 6:
        fn_800E946C(p, lbl_804ECC34[p->unk14]);
        fn_8009996C(p->unk88, lbl_80267F58);
        p->unk12++;
    case 7:
        if (p->unk38->unk60 < lbl_80304B90[0x25C / 4] - 0x4400) {
            p->unk11 = 1;
            p->unk12 = 0;
        }
        break;
    }
    fn_800E9750(p, 0xFFFF);
}
