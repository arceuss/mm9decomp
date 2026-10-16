#include "types.h"

typedef struct Unk800BE4A0Parent {
    /* 0x000 */ u8 pad0[0x128];
    /* 0x128 */ u32 unk128;
    /* 0x12C */ u8 pad12C[0x188 - 0x12C];
    /* 0x188 */ u16 held;
    /* 0x18A */ u8 pad18A[0x18C - 0x18A];
    /* 0x18C */ u16 trig;
} Unk800BE4A0Parent;

typedef struct Unk800BE4A0 {
    /* 0x00 */ u8 pad0[0x11];
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17[0x24 - 0x17];
    /* 0x24 */ u16 sprite;
    /* 0x26 */ u8 pad26[0x34 - 0x26];
    /* 0x34 */ Unk800BE4A0Parent* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ s32 vx;
    /* 0x6C */ s32 vy;
    /* 0x70 */ u8 pad70[0xCC - 0x70];
    /* 0xCC */ u8 delay;
} Unk800BE4A0;

extern u8 lbl_804ECF20[4][2];

void fn_800E9424(Unk800BE4A0* obj, u16 id);
void fn_800E946C(Unk800BE4A0* obj, u8 anim);
void fn_800E9750(Unk800BE4A0* obj, u16 arg1);

void fn_800BE4A0(Unk800BE4A0* obj) {
    Unk800BE4A0Parent* parent = obj->parent;
    u32 v;

    switch (obj->step) {
    case 0:
        v = obj->unk14;
        if (obj->sprite != 0x103) {
            fn_800E9424(obj, 0x103);
        }
        obj->unk16 = 0;
        fn_800E946C(obj, lbl_804ECF20[v][0]);
        obj->delay = 1;
        obj->vy = 0;
        obj->step++;
    case 1:
        parent->unk128 |= 2;
        obj->x += obj->vx;
        if (obj->vy > 0) {
            if ((obj->vy -= 8) < 0) {
                obj->vy = 0;
            }
        } else if (obj->vy < 0) {
            if ((obj->vy += 8) > 0) {
                obj->vy = 0;
            }
        }
        if (parent->held & 1) {
            obj->vy -= 0x20;
        } else if (parent->held & 2) {
            obj->vy += 0x20;
        }
        if (obj->vy > 0x200) {
            obj->vy = 0x200;
        } else if (obj->vy < -0x200) {
            obj->vy = -0x200;
        }
        obj->y += obj->vy;
        if (obj->delay == 0) {
            if (parent->trig & 0x40) {
                obj->state = 1;
                obj->step = 0;
            }
        } else {
            obj->delay--;
        }
        break;
    }
    fn_800E9750(obj, 0xFFFF);
}
