#include "types.h"

typedef struct Unk800D2928 {
    /* 0x00 */ u8 pad0[0x11];
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x16 - 0x13];
    /* 0x16 */ u8 timer;
    /* 0x17 */ u8 pad17[0x64 - 0x17];
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0x6C - 0x68];
    /* 0x6C */ s32 vy;
    /* 0x70 */ u8 pad70[0x74 - 0x70];
    /* 0x74 */ s32 posY;
    /* 0x78 */ u8 pad78[0xC8 - 0x78];
    /* 0xC8 */ u8 frame;
    /* 0xC9 */ u8 rate;
    /* 0xCA */ u16 life;
    /* 0xCC */ s32 baseY;
    /* 0xD0 */ s32 range;
} Unk800D2928;

extern u8 lbl_804ED2E0[2];

void fn_800E946C(Unk800D2928* obj, u8 anim);
void fn_800E9750(Unk800D2928* obj, u16 arg1);

#define ABS(x) ((x) < 0 ? -(x) : (x))

void fn_800D2928(Unk800D2928* obj) {
    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 0);
        obj->timer = obj->rate;
        obj->life = 300;
        obj->step++;
    case 1:
        obj->posY += obj->vy;
        obj->vy -= 2;
        if (obj->vy < -0x200) {
            obj->vy = -0x200;
        }
        if (ABS(obj->posY - obj->baseY) > obj->range) {
            obj->posY = obj->baseY - obj->range;
        }
        if (obj->posY > obj->baseY) {
            obj->vy = 0;
            obj->posY = obj->baseY;
            obj->y = obj->baseY;
        } else {
            obj->y = obj->posY;
        }
        if (--obj->life == 0) {
            obj->vy = 0;
            obj->state = 3;
            obj->step = 0;
        }
        if (obj->timer == 0) {
            if (obj->rate >= 2) {
                obj->rate -= 2;
            } else {
                obj->rate = 1;
            }
            obj->timer = obj->rate;
            obj->frame = obj->frame == 0;
            fn_800E946C(obj, lbl_804ED2E0[obj->frame]);
        } else {
            obj->timer--;
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    }
}
