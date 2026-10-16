#include "types.h"
typedef struct Unk8006181C {
    /* 0x00 */ u8 pad00[0xC];
    /* 0x0C */ u8 unk0C;
    /* 0x0D */ u8 pad0D[3];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 pad13[0x34 - 0x13];
    /* 0x34 */ struct Unk8006181C* unk34;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ u8 pad6C[0x88 - 0x6C];
    /* 0x88 */ u8 unk88[1];
} Unk8006181C;
extern u8 lbl_802677B8[], lbl_80304B90[];
extern void fn_80042D30(Unk8006181C*);
extern void fn_800E946C(Unk8006181C*, s32);
extern void fn_8009996C(void*, void*);
extern void fn_800E9750(Unk8006181C*, u16);
extern u32 fn_80080484(void*, void*, s32);
void fn_8006181C(Unk8006181C* p) {
    if (p->unk34->unk10 >= 2) { fn_80042D30(p); return; }
    switch (p->unk12) {
    case 0:
        fn_800E946C(p, 0x15);
        fn_8009996C(p->unk88, lbl_802677B8);
        p->unk0C |= 0x10;
        p->unk68 = -0x480;
        p->unk12++;
    case 1:
        fn_800E9750(p, 0xFFFF);
        p->unk60 += p->unk68;
        if (fn_80080484(lbl_80304B90 + 0x21C, &p->unk60, 1) > 0x1A00) fn_80042D30(p);
        break;
    }
}
