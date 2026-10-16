#include "types.h"
typedef struct Unk8006A384 {
    /* 0x00 */ u8 pad00[0x11];
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 pad13[0xA0 - 0x13];
    /* 0xA0 */ u32 unkA0;
    /* 0xA4 */ u8 padA4[7];
    /* 0xAB */ u8 unkABa:4;
                 u8 unkABb:4;
} Unk8006A384;
extern void fn_80042CF8(Unk8006A384*, s32);
s32 fn_8006A384(Unk8006A384* p) {
    u8 t;
    u32 flags;
    if (p->unk11 != 1 && p->unkABb == 3) { p->unk11 = 1; p->unk12 = 0; return 0; }
    if (p->unk11 != 2 && p->unkABb == 5) { p->unk11 = 2; p->unk12 = 0; return 0; }
    flags = p->unkA0;
    if (flags & 1) {
        t = p->unkABb;
        if (t == 1 || t == 2 || t == 4 || t == 6 || t == 7) {
            fn_80042CF8(p, 2); return 1;
        }
    }
    if (flags & 0x200) { fn_80042CF8(p, 2); return 1; }
    return 0;
}
