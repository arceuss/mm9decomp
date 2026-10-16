#include "types.h"

typedef struct Unk8038DC58 {
    /* 0x00 */ u8 pad0[0x13];
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0x26 - 0x16];
    /* 0x26 */ u8 count;
    /* 0x27 */ u8 pad27[0x128 - 0x27];
} Unk8038DC58;

typedef struct Unk8027F3D8 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 maxCount;
    /* 0x0B */ u8 padB[0x2C - 0xB];
} Unk8027F3D8;

extern Unk8038DC58 lbl_8038DC58;
extern Unk8027F3D8 lbl_8027F3D8;

void fn_800C675C(s32 arg0);

static inline s32 Inc(s32 c, s32 max) {
    if (c < max - 1) {
        return c + 1;
    }
    return max;
}

void fn_800C7AA0(u8* arg0, u32 kind) {
    s32 n;

    switch (kind) {
    case 0:
        if (*arg0 + 1 >= 9) {
            lbl_8038DC58.unk15 |= 2;
        }
        lbl_8038DC58.unk13 |= 0x40;
        break;
    case 1:
        lbl_8038DC58.unk13 |= 0x80;
        break;
    case 2:
        lbl_8038DC58.unk14 |= 1;
        break;
    case 3:
        lbl_8038DC58.unk14 |= 2;
        break;
    case 4:
        lbl_8038DC58.unk14 |= 4;
        break;
    case 5:
        lbl_8038DC58.unk14 |= 8;
        break;
    case 6:
        lbl_8038DC58.unk14 |= 0x10;
        break;
    case 7:
        lbl_8038DC58.unk14 |= 0x20;
        break;
    case 8:
        lbl_8038DC58.unk14 |= 0x40;
        break;
    case 9:
        lbl_8038DC58.unk14 |= 0x80;
        break;
    case 10:
        lbl_8038DC58.unk15 |= 1;
        break;
    }
    lbl_8038DC58.count = Inc(lbl_8038DC58.count, lbl_8027F3D8.maxCount);
    fn_800C675C(8);
}
