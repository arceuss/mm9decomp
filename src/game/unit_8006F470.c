#include "types.h"

typedef struct Unk8006F470 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x11 - 0xB];
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x16 - 0x13];
    /* 0x16 */ u8 timer;
    /* 0x17 */ u8 pad17[0x54 - 0x17];
    /* 0x54 */ struct {
        u32 hi : 21;
        u32 flip : 1;
        u32 low : 10;
    } bits54;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ s32 vx;
    /* 0x6C */ s32 vy;
    /* 0x70 */ u8 pad70[0x74 - 0x70];
    /* 0x74 */ s32 gravity;
    /* 0x78 */ u8 pad78[0x7C - 0x78];
    /* 0x7C */ u8 anim;
} Unk8006F470;

void fn_800E946C(Unk8006F470* obj, s32 anim);
void fn_800E9750(Unk8006F470* obj, u16 arg1);
s32 fn_800A37F4(s32 x, s32 y);
s32 fn_800A3500(s32 x, s32 y);
s32 fn_800A3AE0(s32 x, s32 y);
s32 fn_800A3DBC(s32 x, s32 y);

void fn_8006F470(Unk8006F470* obj) {
    u32 flip;
    s32 dir;
    s32 d;
    u32 f;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 1);
        obj->timer = 1;
        obj->step++;
    case 1:
        if (--obj->timer == 0) {
            obj->step++;
        }
        break;
    case 2:
        obj->vx = 0x140;
        obj->vy = -0x4C0;
        obj->gravity = 0x40;
        obj->step++;
    case 3:
        dir = ((obj->flagsA >> 3) & 2) - 1;
        flip = (obj->flagsA >> 4) & 1;
        obj->x += obj->vx * dir;
        obj->y += obj->vy;
        if (obj->vy < 0) {
            d = fn_800A37F4(obj->x, obj->y - 0xC00);
            if (d > 0) {
                obj->y += d;
                obj->vy = 0;
            }
        }
        if (obj->vy >= 0) {
            if (obj->anim != 2) {
                fn_800E946C(obj, 2);
            }
            d = fn_800A3500(obj->x, obj->y);
            if (d < 0) {
                obj->y += d;
                obj->step++;
            }
        }
        obj->vy += obj->gravity;
        if (obj->vy > 0x700) {
            obj->vy = 0x700;
        }
        if (flip) {
            d = fn_800A3AE0(obj->x + 0x500, obj->y - 0x600);
        } else {
            d = fn_800A3DBC(obj->x - 0x500, obj->y - 0x600);
        }
        if (d * dir < 0) {
            f = (flip + 1) & 1;
            if (f) {
                obj->flagsA |= 0x10;
            } else {
                obj->flagsA &= 0xEF;
            }
            obj->bits54.flip = f;
            obj->x += d;
        }
        break;
    case 4:
        fn_800E946C(obj, 3);
        f = (((obj->flagsA >> 4) & 1) + 1) & 1;
        if (f) {
            obj->flagsA |= 0x10;
        } else {
            obj->flagsA &= 0xEF;
        }
        obj->bits54.flip = f;
        obj->timer = 8;
        obj->step++;
    case 5:
        if (--obj->timer == 0) {
            obj->state = 0;
            obj->step = 0;
        }
        break;
    }
    fn_800E9750(obj, 0xFFFF);
}
