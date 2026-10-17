#include "types.h"

typedef struct Unk80050730 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x10 - 0xB];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x54 - 0x13];
    /* 0x54 */ struct {
        u32 hi : 21;
        u32 flip : 1;
        u32 low : 10;
    } bits54;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ s32 vx;
    /* 0x6C */ u8 pad6C[0x70 - 0x6C];
    /* 0x70 */ s32 unk70;
} Unk80050730;

extern Unk80050730* lbl_804EE984;

void fn_800E946C(Unk80050730* obj, u8 anim);
void fn_800E9750(Unk80050730* obj, u16 arg1);
s32 fn_800A39F0(s32 x, s32 y);
s32 fn_800A3FAC(s32 x, s32 y);
s32 fn_800A3CD4(s32 x, s32 y);

void fn_80050730(Unk80050730* obj) {
    u32 f;
    s32 d;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 1);
        obj->vx = -0x80;
        obj->unk70 = obj->x;
        f = (u32)(-obj->vx & ~obj->vx) >> 31;
        if (f) {
            obj->flagsA |= 0x10;
        } else {
            obj->flagsA &= 0xEF;
        }
        obj->bits54.flip = f;
        obj->step++;
    case 1:
        fn_800E9750(obj, 0xFFFF);
        obj->x += obj->vx;
        if (__abs(lbl_804EE984->x - obj->x) <= 0x2000) {
            obj->state = 1;
            obj->step = 0;
            break;
        }
        if (obj->vx < 0) {
            if (fn_800A39F0(obj->x - 0xF00, obj->y - 0x800) == 0) {
                obj->vx = -obj->vx;
                f = (u32)(-obj->vx & ~obj->vx) >> 31;
                if (f) {
                    obj->flagsA |= 0x10;
                } else {
                    obj->flagsA &= 0xEF;
                }
                obj->bits54.flip = f;
                break;
            }
            d = fn_800A3FAC(obj->x - 0xF00, obj->y);
            if (d > 0) {
                obj->x += d;
                obj->vx = -obj->vx;
                f = (u32)(-obj->vx & ~obj->vx) >> 31;
                if (f) {
                    obj->flagsA |= 0x10;
                } else {
                    obj->flagsA &= 0xEF;
                }
                obj->bits54.flip = f;
                break;
            }
            if (obj->unk70 - 0x2000 > obj->x) {
                obj->x = obj->unk70 - 0x2000;
                obj->vx = -obj->vx;
                f = (u32)(-obj->vx & ~obj->vx) >> 31;
                if (f) {
                    obj->flagsA |= 0x10;
                } else {
                    obj->flagsA &= 0xEF;
                }
                obj->bits54.flip = f;
            }
            break;
        }
        if (fn_800A39F0(obj->x + 0xF00, obj->y - 0x800) == 0) {
            obj->vx = -obj->vx;
            f = (u32)(-obj->vx & ~obj->vx) >> 31;
            if (f) {
                obj->flagsA |= 0x10;
            } else {
                obj->flagsA &= 0xEF;
            }
            obj->bits54.flip = f;
            break;
        }
        d = fn_800A3CD4(obj->x + 0xF00, obj->y);
        if (d < 0) {
            obj->x += d;
            obj->vx = -obj->vx;
            f = (u32)(-obj->vx & ~obj->vx) >> 31;
            if (f) {
                obj->flagsA |= 0x10;
            } else {
                obj->flagsA &= 0xEF;
            }
            obj->bits54.flip = f;
            break;
        }
        if (obj->unk70 + 0x2000 < obj->x) {
            obj->x = obj->unk70 + 0x2000;
            obj->vx = -obj->vx;
            f = (u32)(-obj->vx & ~obj->vx) >> 31;
            if (f) {
                obj->flagsA |= 0x10;
            } else {
                obj->flagsA &= 0xEF;
            }
            obj->bits54.flip = f;
        }
        break;
    }
}
