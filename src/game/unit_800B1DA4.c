#include "types.h"

typedef struct Unk800B1DA4 {
    /* 0x000 */ u8 pad0[0x9];
    /* 0x009 */ u8 unk9;
    /* 0x00A */ u8 padA[0x10F - 0xA];
    /* 0x10F */ u8 unk10F;
    /* 0x110 */ u8 unk110;
} Unk800B1DA4;

extern s32 lbl_8027E658[][3][4];

s32 fn_800B1DA4(Unk800B1DA4* work) {
    s32 type = work->unk9 == 2;

    if (work->unk10F - 0x20 < 0) {
        return lbl_8027E658[type][0][0];
    }
    return lbl_8027E658[type][(work->unk10F - 0x1F) / 32][work->unk110 / 2];
}
