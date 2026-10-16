#include "types.h"
typedef struct Unk8006CD9C {
    /* 0x00 */ u8 pad00[0x10];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 pad13[3];
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17[0x34 - 0x17];
    /* 0x34 */ struct Unk8006CD9C* unk34;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ s32 unk6C;
} Unk8006CD9C;
extern Unk8006CD9C* lbl_804EE984;
extern u8 lbl_80304B90[];
extern void fn_80042D30(Unk8006CD9C*);
extern void fn_800E946C(Unk8006CD9C*, s32);
extern void fn_800E9750(Unk8006CD9C*, u16);
extern void fn_800B6430(Unk8006CD9C*);
extern void fn_800B60CC(Unk8006CD9C*, s32);
void fn_8006CD9C(Unk8006CD9C* p) {
    Unk8006CD9C* q;
    s32 d;
    if (p->unk34->unk10 >= 2 || p->unk34->unk11 != 2) { fn_80042D30(p); return; }
    switch (p->unk12) {
    case 0:
        fn_800E946C(p, 0x2A);
        p->unk6C = 0x200; p->unk16 = 0; p->unk12++;
    case 1:
        if (p->unk16 == 0) {
            p->unk64 += p->unk6C;
            if (p->unk64 > *(s32*)(lbl_80304B90 + 0x260) + 0x2FFF) {
                p->unk64 = *(s32*)(lbl_80304B90 + 0x260) + 0x2FFF;
                p->unk16++;
            }
        }
        q = lbl_804EE984;
        fn_800B6430(q);
        d = q->unk60 - p->unk60;
        if ((d < 0 ? -d : d) > 0xE00) {
            fn_800B60CC(q, -((((lbl_804EE984->unk60 - p->unk60) >> 31) * 2 + 1) << 8));
        }
        break;
    }
    fn_800E9750(p, 0xFFFF);
}
