#include "types.h"
typedef struct Unk80073B24 {
    /* 0x00 */ u8 pad00[0x9];
    /* 0x09 */ u8 unk09;
    /* 0x0A */ u8 unk0A;
    /* 0x0B */ u8 pad0B[0x5];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15[0x3];
    /* 0x18 */ void* unk18;
    /* 0x1C */ u8 pad1C[0x63];
    /* 0x7F */ u8 unk7F;
} Unk80073B24;
extern void** lbl_80270168[];
extern void fn_800E946C(Unk80073B24*, s32);
extern void fn_800E9750(Unk80073B24*, u16);
extern void fn_800E9244(Unk80073B24*);
void fn_80073B24(Unk80073B24* p) {
    switch (p->unk12) {
    case 0:
        fn_800E946C(p, 2); fn_800E9244(p); p->unk12++;
    case 1:
        fn_800E9750(p, 0xFFFF);
        if (p->unk7F == 3) {
            p->unk0A &= ~1;
            p->unk18 = lbl_80270168[p->unk09][4];
            p->unk10 = 4; p->unk11 = 0; p->unk12 = 0; p->unk13 = 0;
        }
        break;
    }
}
