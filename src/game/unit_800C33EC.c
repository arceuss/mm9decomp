#include "types.h"

typedef struct Vec2s32 {
    s32 x;
    s32 y;
} Vec2s32;

typedef struct Unk800C33EC {
    /* 0x00 */ u8 pad0[0x11];
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x60 - 0x13];
    /* 0x60 */ Vec2s32 pos;
    /* 0x68 */ u8 pad68[0xCC - 0x68];
    /* 0xCC */ u8 unkCC;
    /* 0xCD */ u8 padCD[0xD0 - 0xCD];
    /* 0xD0 */ Vec2s32 unkD0;
} Unk800C33EC;

void fn_800C33EC(Unk800C33EC* obj) {
    if (obj->unkCC != 0) {
        obj->pos = obj->unkD0;
        obj->state = 1;
        obj->step = 0;
    }
}
