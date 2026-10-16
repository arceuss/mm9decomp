#include "types.h"

typedef struct UnkBBBFC {
    /* 0x00 */ u8 pad0[0xB];
    /* 0x0B */ u8 unkB;
} UnkBBBFC;

extern u16 lbl_804ECEA0[2];

void fn_800E9810(void*, s32);

void fn_800BBBFC(UnkBBBFC* rec, u16 v) {
    if (v == 0xFF) {
        rec->unkB = rec->unkB & 0xFB;
        return;
    }
    fn_800E9810(rec, lbl_804ECEA0[v]);
}
