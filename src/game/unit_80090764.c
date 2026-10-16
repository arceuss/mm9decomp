#include "types.h"

typedef struct Unk90764 {
    /* 0x0000 */ u8 pad0[2];
    /* 0x0002 */ u8 unk02;
    /* 0x0003 */ u8 unk03;
    /* 0x0004 */ u8 pad04[0xFF6 - 0x4];
    /* 0x0FF6 */ u8 unkFF6;
    /* 0x0FF7 */ u8 padFF7[0xFFB - 0xFF7];
    /* 0x0FFB */ u8 unkFFB;
} Unk90764;

typedef struct Unk80319DA0 {
    /* 0x000 */ u8 pad0[0x860];
    /* 0x860 */ u32 unk860;
    /* 0x864 */ u16 unk864;
} Unk80319DA0;

extern Unk80319DA0 lbl_80319DA0;

void fn_800D5234(s32);

void fn_80090764(Unk90764* p) {
    if ((lbl_80319DA0.unk860 & 0x10) || (lbl_80319DA0.unk860 & 0x40)) {
        fn_800D5234(1);
        if (p->unkFF6 == 0) {
            p->unkFFB = 2;
            p->unk02 = 6;
            p->unk03 = 0;
        } else {
            p->unk03++;
        }
    } else if (lbl_80319DA0.unk864 & 4) {
        fn_800D5234(0);
        p->unkFF6 = p->unkFF6 != 1;
    } else if (lbl_80319DA0.unk864 & 8) {
        fn_800D5234(0);
        p->unkFF6 = p->unkFF6 != 1;
    }
}
