#include "types.h"
typedef struct Unk8006AA30 {
    /* 0x00 */ u8 pad00[0x11];
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 pad13[3];
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 unk17;
    /* 0x18 */ u8 pad18[0x34 - 0x18];
    /* 0x34 */ struct Unk8006AA30* unk34;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
} Unk8006AA30;
extern void fn_800E946C(Unk8006AA30*, s32);
extern void fn_800E9750(Unk8006AA30*, u16);
void fn_8006AA30(Unk8006AA30* p) {
    Unk8006AA30* q = p->unk34;
    p->unk60 = q->unk60; p->unk64 = q->unk64 + 0xA00;
    switch (p->unk12) {
    case 0:
        fn_800E946C(p, 0);
        p->unk16 = 60; p->unk12++;
    case 1:
        if (q->unk11 == 0 && q->unk12 == 5) {
            if (p->unk16 == 0) p->unk12++; else p->unk16--;
        }
        break;
    case 2:
        fn_800E946C(p, 1);
        p->unk16 = 16; p->unk17 = 1; p->unk12++;
    case 3:
        if (p->unk16 == 0) {
            if (p->unk17 == 0) { p->unk11 = 0; p->unk12 = 0; }
            else { p->unk17--; p->unk16 = 16; fn_800E946C(p, 1); }
        } else p->unk16--;
        break;
    }
    fn_800E9750(p, 0xFFFF);
}
