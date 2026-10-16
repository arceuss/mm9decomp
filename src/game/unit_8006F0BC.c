#include "types.h"

typedef struct Unk8006F0BC {
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
    /* 0x6C */ u8 pad6C[0x84 - 0x6C];
    /* 0x84 */ s32 unk84;
} Unk8006F0BC;

typedef struct Unk804EE984 {
    /* 0x00 */ u8 pad0[0x60];
    /* 0x60 */ s32 x;
} Unk804EE984;

extern Unk804EE984* lbl_804EE984;
extern u8 lbl_804ECC90[8];

void fn_800E946C(Unk8006F0BC* obj, s32 anim);
void fn_800E9750(Unk8006F0BC* obj, u16 arg1);
s32 fn_800A3500(s32 x, s32 y);
s32 fn_800A3AE0(s32 x, s32 y);
s32 fn_800A3DBC(s32 x, s32 y);
u16 fn_8009E894(s32 x, s32 y);
void fn_8007C6A8(Unk8006F0BC* obj, s32* pos, s32* vel);
void fn_800D5234(s32 id);

void fn_8006F0BC(Unk8006F0BC* obj) {
    s32 dir;
    u32 flip;
    s32 d;
    u32 f;
    s32 pos[2];
    s32 vel[2];
    s32 zero;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 0);
        obj->vx = 0x180;
        obj->unk84 = 0;
        obj->timer = 0;
        obj->step++;
    case 1:
        dir = ((obj->flagsA >> 3) & 2) - 1;
        flip = (obj->flagsA >> 4) & 1;
        obj->x += obj->vx * dir;
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
            dir = (f == 1) * 2 - 1;
        }
        if (fn_800A3500(obj->x, obj->y + 1) >= 0) {
            obj->state = 1;
            obj->step = 0;
            break;
        }
        if ((u32)(obj->x + dir * 0xC00 - lbl_804EE984->x + 0xC00) < 0x1800) {
            obj->state = 2;
            obj->step = 0;
        }
        if (fn_8009E894(obj->x, obj->y + 1) & 0x800) {
            if (lbl_804ECC90[obj->timer] <= ++obj->unk84) {
                zero = 0;
                pos[0] = obj->x;
                pos[1] = obj->y - 0xE00;
                vel[0] = zero;
                vel[1] = -0x240;
                fn_8007C6A8(obj, pos, vel);
                obj->unk84 = zero;
                obj->timer = (obj->timer + 1) & 1;
                fn_800D5234(0x4C);
            }
        } else {
            obj->unk84 = 0;
        }
        break;
    }
    fn_800E9750(obj, 0xFFFF);
}
