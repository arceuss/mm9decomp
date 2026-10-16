#include "types.h"

typedef struct Unk800CA12C {
    /* 0x00 */ u8* unk0;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 unk7;
    /* 0x08 */ u8 pad8;
    /* 0x09 */ u8 unk9;
    /* 0x0A */ s16 unkA;
} Unk800CA12C;

void fn_800CA12C(Unk800CA12C* obj, u8 a) {
    u8* p;
    s32 i;

    obj->unk4 = a;
    obj->unk5 = 0;
    p = obj->unk0;
    i = a * 2;
    obj->unkA = p[*(u16*)(p + i) + 1] << 8;
    if ((s8)p[*(u16*)(p + i) + 3] < 0) {
        if (obj->unkA <= 0x100) {
            obj->unk7 = 1;
        } else {
            obj->unk7 = 0;
        }
    } else {
        obj->unk7 = 0;
    }
    obj->unk9 = 1;
}
