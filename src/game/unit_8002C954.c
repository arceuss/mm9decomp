#include "types.h"

typedef struct Unk8002C954 {
    /* 0x000 */ u8 pad0[0x271];
    /* 0x271 */ s8 unk271;
    /* 0x272 */ u8 pad272[0x278 - 0x272];
    /* 0x278 */ u8 unk278;
    /* 0x279 */ u8 unk279;
    /* 0x27A */ u8 unk27A;
    /* 0x27B */ u8 unk27B;
    /* 0x27C */ u8 unk27C;
    /* 0x27D */ u8 unk27D;
    /* 0x27E */ u8 unk27E;
    /* 0x27F */ u8 unk27F;
    /* 0x280 */ u8 unk280;
} Unk8002C954;

extern u8 lbl_803013C0[];

static inline void SetSlot(Unk8002C954* p, u8 i) {
    switch (i) {
    case 0:
        p->unk278 = lbl_803013C0[i + p->unk271];
        break;
    case 1:
        p->unk279 = lbl_803013C0[i + p->unk271];
        break;
    case 2:
        p->unk27A = lbl_803013C0[i + p->unk271];
        break;
    case 3:
        p->unk27B = lbl_803013C0[i + p->unk271];
        break;
    case 4:
        p->unk27C = lbl_803013C0[i + p->unk271];
        break;
    case 5:
        p->unk27D = lbl_803013C0[i + p->unk271];
        break;
    case 6:
        p->unk27E = lbl_803013C0[i + p->unk271];
        break;
    case 7:
        p->unk27F = lbl_803013C0[i + p->unk271];
        break;
    case 8:
        p->unk280 = lbl_803013C0[i + p->unk271];
        break;
    default:
        p->unk278 = lbl_803013C0[i + p->unk271];
        break;
    }
}

void fn_8002C954(Unk8002C954* p) {
    u32 i;

    for (i = 0; i < 9; i++) {
        SetSlot(p, i);
    }
}
