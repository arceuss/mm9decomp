#include "types.h"
typedef struct Unk8005EF9C {
    /* 0x00 */ u8 pad00[0x11];
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15[0x60 - 0x15];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ u8 pad64[0xA0 - 0x64];
    /* 0xA0 */ u32 unkA0;
    /* 0xA4 */ u8 padA4[7];
    /* 0xAB */ u8 unkABa:4;
                 u8 unkABb:4;
} Unk8005EF9C;
extern u8 lbl_803051D8[], lbl_80304B90[];
extern s32 fn_80080484(void*, void*, s32);
extern void fn_80042CF8(Unk8005EF9C*, s32);
s32 fn_8005EF9C(Unk8005EF9C* p) {
    if (p->unk14 == 0 && (lbl_803051D8[2] & 0x10) && fn_80080484(lbl_80304B90 + 0x21C, &p->unk60, 1) == 0) {
        if (p->unk11 != 0 || p->unk12 >= 2) {
            fn_80042CF8(p, 2); p->unk11 = 4; return 1;
        }
    }
    if (p->unk11 != 1 && p->unkABb == 3) { p->unk11 = 1; p->unk12 = 0; return 0; }
    if (p->unk11 != 2 && p->unkABb == 5) { p->unk11 = 2; p->unk12 = 0; return 0; }
    if (p->unkABb == 8) { fn_80042CF8(p, 2); p->unk11 = 2; return 1; }
    if ((p->unkA0 & 0x200) && p->unkABb == 2) { fn_80042CF8(p, 2); p->unk11 = 3; return 1; }
    if (p->unkA0 & 0x200) { fn_80042CF8(p, 2); p->unk11 = 0; p->unk12 = 0; return 1; }
    return 0;
}
