#include "types.h"
typedef struct Unk800538EC {
    /* 0x00 */ u8 pad00[0x11];
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 pad14[2];
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 unk17;
    /* 0x18 */ u8 pad18[0x60 - 0x18];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0x7D - 0x68];
    /* 0x7D */ u8 unk7D;
    /* 0x7E */ u8 unk7E;
    /* 0x7F */ u8 unk7F;
    /* 0x80 */ u8 pad80[8];
    /* 0x88 */ u8 unk88[1];
} Unk800538EC;
extern Unk800538EC* lbl_804EE984;
extern u8 lbl_804ECAA0[4], lbl_804ECAA4[4], lbl_804ECAA8[4], lbl_804ECAAC[4], lbl_804ECAB0[8];
extern u8 lbl_80266588[], lbl_802665B8[];
extern void fn_800E946C(Unk800538EC*, s32);
extern void fn_800E9750(Unk800538EC*, u16);
extern void fn_8009996C(void*, void*);
extern void fn_800768B4(s32*, s32, s32);
void fn_800538EC(Unk800538EC* p) {
    s32 v[2];
    switch (p->unk12) {
    case 0:
        p->unk17 = (lbl_804EE984->unk60 - p->unk60) > 0;
        fn_800E946C(p, lbl_804ECAA0[p->unk17]);
        p->unk16 = 30; p->unk13 = 0; p->unk12++;
    case 1:
        fn_800E9750(p, 0xFFFF);
        if (p->unk7D >= 2 && p->unk13 == 0) {
            fn_8009996C(p->unk88, lbl_802665B8); p->unk13++;
        }
        if (p->unk16 == 0) p->unk12++; else p->unk16--;
        break;
    case 2:
        fn_800E946C(p, lbl_804ECAB0[p->unk17]);
        p->unk16 = 8; p->unk12++;
    case 3:
        fn_800E9750(p, 0xFFFF);
        if (p->unk16 == 0) p->unk12++; else p->unk16--;
        break;
    case 4:
        fn_800E946C(p, lbl_804ECAA4[p->unk17]);
        v[0] = p->unk60 + (((p->unk17 == 1) * 2 - 1) << 11);
        v[1] = p->unk64 - 0x1000;
        fn_800768B4(v, 0x2A0, lbl_804ECAAC[p->unk17]);
        p->unk16 = 36; p->unk12++;
    case 5:
        fn_800E9750(p, 0xFFFF);
        if (--p->unk16 == 0) p->unk12++;
        break;
    case 6:
        fn_800E946C(p, lbl_804ECAA8[p->unk17]);
        p->unk16 = 0; p->unk12++;
    case 7:
        fn_800E9750(p, 0xFFFF);
        if (p->unk7D == 1 && p->unk16 == 0) {
            fn_8009996C(p->unk88, lbl_80266588); p->unk16++;
        }
        if (p->unk7F == 3) { p->unk11 = 0; p->unk12 = 0; }
        break;
    }
}
