#include "types.h"

typedef struct Unk800A8A7C {
    /* 0x00 */ u32 size;
    /* 0x04 */ u32 unk4;
    /* 0x08 */ u8 pad8[0xA - 0x8];
    /* 0x0A */ u16 flags_hi : 12;
    /* 0x0A */ u16 flag3 : 1;
    /* 0x0A */ u16 flags_mid : 2;
    /* 0x0A */ u16 flag0 : 1;
    /* 0x0C */ u8 padC[0x14 - 0xC];
} Unk800A8A7C;

u16 fn_800A8A7C(Unk800A8A7C* p) {
    u16 max = 0;
    s32 n;
    u16 v;

    if (p->flag0) {
        n = p->size / 20;
    } else {
        n = p->size / 12;
    }
    if (p->flag3) {
        for (; n != 0; n--, p++) {
            v = p->unk4 >> 19;
            if (v > max) {
                max = v;
            }
        }
    } else {
        for (; n != 0; n--, p++) {
            v = p->unk4 >> 18;
            if (v > max) {
                max = v;
            }
        }
    }
    return max;
}
