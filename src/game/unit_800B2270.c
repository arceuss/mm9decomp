#include "types.h"

typedef struct Unk800B2270 {
    /* 0x000 */ u8 pad0[0x10F];
    /* 0x10F */ u8 unk10F;
    /* 0x110 */ u8 unk110;
} Unk800B2270;

extern s32 lbl_8027E6C8[];

s32 fn_800B2270(Unk800B2270* work) {
    if (work->unk10F - 0x20 < 0) {
        return 3;
    }
    return lbl_8027E6C8[work->unk110 / 2];
}
