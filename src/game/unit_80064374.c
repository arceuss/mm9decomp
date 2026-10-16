#include "types.h"
typedef struct Unk80064374 {
    /* 0x00 */ u8 pad00[9];
    /* 0x09 */ u8 unk09;
    /* 0x0A */ u8 pad0A[7];
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 pad13[3];
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17[5];
    /* 0x1C */ struct Unk80064374* unk1C;
    /* 0x20 */ u8 pad20[0x34 - 0x20];
    /* 0x34 */ struct Unk80064374* unk34;
    /* 0x38 */ u8 pad38[0x7F - 0x38];
    /* 0x7F */ u8 unk7F;
    /* 0x80 */ u8 pad80[0xC8 - 0x80];
    /* 0xC8 */ s32 unkC8;
} Unk80064374;
extern u8 lbl_80304B90[];
extern void fn_800E946C(Unk80064374*, s32);
extern void fn_800E9750(Unk80064374*, u16);
void fn_80064374(Unk80064374* p) {
    Unk80064374* q = p->unk34;
    switch (p->unk12) {
    case 0:
        fn_800E946C(p, 1);
        p->unk16 = p->unkC8 * 10;
        p->unk12++;
    case 1:
        if (q->unk1C->unk09 & 1) {
            if (p->unk16 == 0) p->unk12++; else p->unk16--;
        }
        fn_800E9750(p, 0xFFFF);
        break;
    case 2:
        fn_800E946C(p, 2);
        p->unk16 = 120;
        p->unk12++;
    case 3:
        fn_800E9750(p, 0xFFFF);
        if (p->unk16 == 0) {
            if (p->unk7F == 3 && !(lbl_80304B90[0x125] & 1)) {
                p->unk11 = 1; p->unk12 = 0;
            }
        } else p->unk16--;
        break;
    }
}
