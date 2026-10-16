#include "types.h"
typedef struct Unk8006AE48 {
    /* 0x00 */ u8 pad00[0xA];
    /* 0x0A */ u8 unk0A;
    /* 0x0B */ u8 pad0B[5];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 pad13[3];
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17[0x34 - 0x17];
    /* 0x34 */ struct Unk8006AE48* unk34;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0x7C - 0x68];
    /* 0x7C */ u8 unk7C;
} Unk8006AE48;
extern void fn_80042D30(Unk8006AE48*);
extern void fn_800E946C(Unk8006AE48*, s32);
extern void fn_800E9750(Unk8006AE48*, u16);
void fn_8006AE48(Unk8006AE48* p) {
    Unk8006AE48* q = p->unk34;
    if (q->unk10 >= 2) { fn_80042D30(p); return; }
    switch (p->unk12) {
    case 0:
        p->unk0A &= ~1; p->unk16 = 0; p->unk12++;
    case 1:
        p->unk60 = q->unk60; p->unk64 = q->unk64 + 0xC00;
        if (q->unk7C == 0 || q->unk7C == 2) {
            if (p->unk16 != 0) { p->unk0A &= ~1; p->unk16 = 0; }
        } else if (p->unk16 == 0) {
            p->unk0A |= 1; fn_800E946C(p, 7); p->unk16++;
        }
        break;
    }
    fn_800E9750(p, 0xFFFF);
}
