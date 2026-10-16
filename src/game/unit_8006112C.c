#include "types.h"

typedef struct Vec2i {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Vec2i;

typedef struct Unk8006112C {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x10 - 0xB];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x16 - 0x13];
    /* 0x16 */ u8 timer;
    /* 0x17 */ u8 pad17[0x34 - 0x17];
    /* 0x34 */ struct Unk8006112C* parent;
    /* 0x38 */ u8 pad38[0x54 - 0x38];
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
    /* 0x70 */ s32 ax;
    /* 0x74 */ s32 gravity;
} Unk8006112C;

typedef struct Unk804EE984 {
    /* 0x00 */ u8 pad0[0x60];
    /* 0x60 */ s32 x;
} Unk804EE984;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x21C];
    /* 0x21C */ u8 unk21C[1];
} Unk80304B90;

extern Unk804EE984* lbl_804EE984;
extern Unk80304B90 lbl_80304B90;

void fn_80040AD0(s32 arg0, Vec2i* pos, s32 arg2, s32 arg3);
void fn_80042D30(Unk8006112C* obj);
void fn_800E946C(Unk8006112C* obj, s32 anim);
void fn_800E9758(Unk8006112C* obj);
void fn_800E9750(Unk8006112C* obj, u16 arg1);
s32 fn_800A36F8(s32 x, s32 y);
u32 fn_80080484(void* cam, s32* pos, s32 arg2);

void fn_8006112C(Unk8006112C* obj) {
    Unk8006112C* parent = obj->parent;
    Vec2i pos;
    u32 f;
    s32 d;

    if (parent->unk10 >= 2) {
        pos.x = obj->x;
        pos.y = obj->y;
        fn_80040AD0(2, &pos, 0, 0);
        fn_80042D30(obj);
        return;
    }
    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 0x14);
        obj->vy = 0;
        obj->gravity = 0x40;
        f = lbl_804EE984->x - obj->x > 0;
        if (f) {
            obj->flagsA |= 0x10;
        } else {
            obj->flagsA &= 0xEF;
        }
        obj->bits54.flip = f;
        obj->timer = 1;
        obj->step++;
    case 1:
        fn_800E9758(obj);
        obj->y += obj->vy;
        obj->vy += obj->gravity;
        d = fn_800A36F8(obj->x, obj->y + 0x600);
        if (d != 0) {
            obj->y += d;
            if (obj->timer == 1) {
                obj->vy = -0x200;
            } else {
                obj->step++;
                break;
            }
            obj->timer--;
        }
        break;
    case 2:
        d = ((obj->flagsA >> 3) & 2) - 1;
        obj->step++;
        obj->vx = d << 8;
        obj->ax = d * 0x12;
    case 3:
        fn_800E9750(obj, 0xFFFF);
        obj->x += obj->vx;
        obj->vx += obj->ax;
        if (obj->ax < 0) {
            if (obj->vx < -0x580) {
                obj->vx = -0x580;
            }
        } else if (obj->vx > 0x580) {
            obj->vx = 0x580;
        }
        if (fn_80080484(lbl_80304B90.unk21C, &obj->x, 1) > 0x1400) {
            fn_80042D30(obj);
        }
        break;
    }
}
