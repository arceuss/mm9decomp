#include "types.h"

typedef struct Unk800E9244 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0xA0 - 0xB];
    /* 0xA0 */ s32 unkA0;
    /* 0xA4 */ s32 unkA4;
    /* 0xA8 */ u8 unkA8;
} Unk800E9244;

void fn_800E9244(Unk800E9244* obj) {
    obj->unkA0 = 0;
    obj->unkA4 = 0;
    obj->unkA8 = 0;
    obj->flagsA &= 0xFB;
}
