#include "types.h"

typedef struct Unk800E83A4 {
    /* 0x0 */ u32 offset;
    /* 0x4 */ u32 info;
    /* 0x8 */ u8 pad8[0xA - 0x8];
    /* 0xA */ u16 flags;
} Unk800E83A4;

typedef struct Unk8043CA80 {
    /* 0x000 */ u8 pad0[0x258];
    /* 0x258 */ u8* bank0;
    /* 0x25C */ u8* bank1;
} Unk8043CA80;

extern Unk8043CA80 lbl_8043CA80;

void fn_800E83A4(Unk800E83A4* img, u32 dst) {
    u32 n = img->info >> 13;
    u8* base;
    u8* src;
    u8* out;
    u32 i;

    if (n == 0) {
        return;
    }
    if (dst < 0x400000) {
        base = lbl_8043CA80.bank0;
        dst += (img->info & 0x3FF) * ((img->flags >> 2) & 0x7F8);
    } else {
        base = lbl_8043CA80.bank1;
        dst += (((img->info >> 10) & 7) + 1) * ((img->info & 0x3FF) << 5);
    }
    if ((img->flags >> 14) & 1) {
        return;
    }
    src = (u8*)img + img->offset;
    out = base + (dst & 0xFFFFF);
    for (i = 0; i < n; i++) {
        out[i] = ((src[i] >> 4) & 0xF) | ((src[i] & 0xF) << 4);
    }
}
