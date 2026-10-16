#include "types.h"
typedef struct Unk800620FC {
    /* 0x00 */ u8 pad00[0x11];
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 pad13[0xA0 - 0x13];
    /* 0xA0 */ u32 unkA0;
    /* 0xA4 */ u8 padA4[7];
    /* 0xAB */ u8 unkABa:4;
                 u8 unkABb:4;
} Unk800620FC;
extern void fn_80042CF8(Unk800620FC*, s32);
s32 fn_800620FC(Unk800620FC* p) {
    if (p->unk11 != 1 && p->unkABb == 3) {
        p->unk11 = 1; p->unk12 = 0;
    } else if (p->unk11 != 2 && p->unkABb == 5) {
        p->unk11 = 2; p->unk12 = 0;
    } else if (p->unkA0 & 0x200) {
        fn_80042CF8(p, 2);
        p->unk11 = 0; p->unk12 = 0;
        return 1;
    }
    return 0;
}
