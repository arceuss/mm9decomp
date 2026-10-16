#include "types.h"

typedef struct Unk800CA19C {
    /* 0x00 */ u16* unk0;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 unk7;
    /* 0x08 */ u8 pad8[0xA - 0x8];
    /* 0x0A */ s16 unkA;
} Unk800CA19C;

void fn_800CA19C(Unk800CA19C* obj, s32 a) {
    obj->unkA -= a;
    while (obj->unkA <= 0) {
        u16* base = obj->unk0;
        u8 i = ++obj->unk5;
        u8 ch;

        ch = *(u8*)((u8*)(base + i) + base[obj->unk4] + 1);
        if ((s8)ch == -1) {
            obj->unkA = 1;
            obj->unk5--;
            obj->unk7 = 3;
        } else if ((s8)ch == -2) {
            u8 v = *(u8*)((u8*)(base + i) + base[obj->unk4]);
            obj->unk5 = v;
            obj->unk7 = 4;
            obj->unkA += *(u8*)((u8*)(base + v) + base[obj->unk4] + 1) << 8;
        } else {
            obj->unkA += ch << 8;
            obj->unk7 = 0;
        }
    }
}
