#include "types.h"

typedef struct UnkBFCDC {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 unkA;
    /* 0x0B */ u8 padB[0x16 - 0xB];
    /* 0x16 */ u8 unk16;
} UnkBFCDC;

void fn_800E9810(void*, s32);
void fn_800E9A84(void*, s32);
void fn_800E9424(void*, s32);
void fn_800E946C(void*, s32);

void fn_800BEE90(UnkBFCDC* rec) {
    rec->unkA |= 1;
    fn_800E9810(rec, 0x141);
    fn_800E9A84(rec, 0x144);
    fn_800E9424(rec, 0x104);
    rec->unk16 = 0;
    fn_800E946C(rec, 0);
}
