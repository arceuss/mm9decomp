#include "types.h"

typedef struct Unk8006F2E0 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x11 - 0xB];
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x16 - 0x13];
    /* 0x16 */ u8 timer;
    /* 0x17 */ u8 pad17[0x60 - 0x17];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ s32 vx;
    /* 0x6C */ s32 vy;
    /* 0x70 */ u8 pad70[0x74 - 0x70];
    /* 0x74 */ s32 gravity;
} Unk8006F2E0;

void fn_800E946C(Unk8006F2E0* obj, s32 arg1);
s32 fn_800A3AE0(s32 x, s32 y);
s32 fn_800A3DBC(s32 x, s32 y);
s32 fn_800A3500(s32 x, s32 y);
void fn_800E9750(Unk8006F2E0* obj, u16 arg1);

void fn_8006F2E0(Unk8006F2E0* obj) {
    s32 dir;
    s32 push;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 2);
        obj->vx = 0x180;
        obj->vy = 0;
        obj->gravity = 0x40;
        obj->step++;
    case 1:
        obj->x += obj->vx * (dir = ((obj->flagsA >> 3) & 2) - 1);
        if ((obj->flagsA >> 4) & 1) {
            push = fn_800A3AE0(obj->x + 0x500, obj->y - 0x600);
        } else {
            push = fn_800A3DBC(obj->x - 0x500, obj->y - 0x600);
        }
        if (push * dir < 0) {
            obj->x += push;
        }
        obj->y += obj->vy;
        push = fn_800A3500(obj->x, obj->y);
        if (push < 0) {
            obj->y += push;
            obj->step++;
        }
        obj->vy += obj->gravity;
        if (obj->vy > 0x700) {
            obj->vy = 0x700;
        }
        break;
    case 2:
        fn_800E946C(obj, 3);
        obj->timer = 8;
        obj->step++;
    case 3:
        if (--obj->timer == 0) {
            obj->state = 0;
            obj->step = 0;
        }
        break;
    }
    fn_800E9750(obj, 0xFFFF);
}
