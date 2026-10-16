#include "types.h"

typedef struct Unk800644B4 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x11 - 0xB];
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x16 - 0x13];
    /* 0x16 */ u8 timer;
    /* 0x17 */ u8 count;
    /* 0x18 */ u8 pad18[0x60 - 0x18];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ s32 vx;
    /* 0x6C */ u8 pad6C[0xC8 - 0x6C];
    /* 0xC8 */ s32 kind;
} Unk800644B4;

void fn_80065488(s32 x, s32 y);
void fn_800E946C(Unk800644B4* obj, s32 anim);
void fn_800E9750(Unk800644B4* obj, u16 arg1);

void fn_800644B4(Unk800644B4* obj) {
    switch (obj->step) {
    case 0:
        obj->flagsA &= ~1;
        obj->x = ((obj->x / 0x10000 + 1) << 16) + 0x1000;
        obj->timer = 0;
        obj->count = 0;
        obj->step++;
    case 1:
        if (obj->timer == 0) {
            fn_80065488(0xCF000, obj->y - (obj->count << 12));
            if (++obj->count >= 2) {
                obj->step++;
            }
            obj->timer = 4;
        } else {
            obj->timer--;
        }
        break;
    case 2:
        obj->flagsA |= 1;
        if (obj->kind == 0) {
            fn_800E946C(obj, 3);
        } else {
            fn_800E946C(obj, 6);
        }
        obj->vx = -0x200;
        obj->timer = 4;
        obj->step++;
    case 3:
        fn_800E9750(obj, 0xFFFF);
        if (obj->timer == 0) {
            obj->x += obj->vx;
            if (obj->x <= 0xCE000) {
                obj->x = 0xCE000;
                obj->step++;
            }
        } else {
            obj->timer--;
        }
        break;
    case 4:
        if (obj->kind == 0) {
            fn_800E946C(obj, 0);
        } else {
            fn_800E946C(obj, 5);
        }
        obj->timer = 4;
        obj->count = 2;
        obj->step++;
    case 5:
        fn_800E9750(obj, 0xFFFF);
        if (obj->timer == 0) {
            fn_80065488(0xCF000, obj->y - ((obj->count - 1) << 12));
            if (--obj->count == 0) {
                if (obj->kind == 0) {
                    obj->state = 1;
                } else {
                    obj->state = 3;
                }
                obj->step = 0;
            }
            obj->timer = 4;
        } else {
            obj->timer--;
        }
        break;
    }
}
