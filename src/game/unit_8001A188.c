#include "types.h"

typedef struct Unk8001A188 {
    /* 0x00 */ u8 pad0[0x11];
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x16 - 0x13];
    /* 0x16 */ u8 timer;
    /* 0x17 */ u8 smoke;
    /* 0x18 */ u8 pad18[0x50 - 0x18];
    /* 0x50 */ u32 unk50;
    /* 0x54 */ u8 pad54[0x60 - 0x54];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ s32 vx;
    /* 0x6C */ u8 pad6C[0x70 - 0x6C];
    /* 0x70 */ s32 targetX;
    /* 0x74 */ u8 pad74[0x7F - 0x74];
    /* 0x7F */ u8 unk7F;
} Unk8001A188;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x25C];
    /* 0x25C */ s32 unk25C;
    /* 0x260 */ u8 pad260[0x300 - 0x260];
} Unk80304B90;

extern Unk80304B90 lbl_80304B90;
extern s32 lbl_80262A48[];
extern u32 lbl_804EE988;

void fn_800E946C(Unk8001A188* obj, u8 anim);
void fn_8007A98C(Unk8001A188* obj, s32 x, s32 y, s32 arg3);
void fn_800E9750(Unk8001A188* obj, u16 arg1);

void fn_8001A188(Unk8001A188* obj) {
    u32 rnd;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 3);
        obj->step++;
    case 1:
        if (obj->unk7F == 3) {
            obj->step++;
        }
        break;
    case 2:
        fn_800E946C(obj, 2);
        obj->unk50 |= 3;
        rnd = lbl_804EE988 * 0x343FD;
        rnd += 0x269EC3;
        lbl_804EE988 = rnd & 0x7FFFFFFF;
        rnd = ((rnd >> 16) & 0x7FFF) % 7 + 1;
        obj->targetX = lbl_80304B90.unk25C - 0x10000 + lbl_80262A48[(u8)rnd] + 0x7000;
        if (obj->x - obj->targetX != 0) {
            obj->vx = (((obj->targetX - obj->x) >> 31) * 2 + 1) << 9;
        } else {
            obj->vx = 0;
        }
        obj->timer = 0x3C;
        obj->smoke = 0;
        obj->step++;
    case 3:
        if (obj->vx == 0) {
            if (obj->timer == 0) {
                obj->state = 0;
                obj->step = 0;
                break;
            }
            obj->timer--;
        } else {
            if (obj->smoke == 0) {
                obj->smoke = 0x10;
                fn_8007A98C(obj, obj->x, obj->y, 1);
            } else {
                obj->smoke--;
            }
            if (obj->vx < 0) {
                if (obj->x < obj->targetX) {
                    obj->x = obj->targetX;
                    obj->vx = 0;
                    fn_8007A98C(obj, obj->targetX, obj->y, 1);
                }
            } else if (obj->x > obj->targetX) {
                obj->x = obj->targetX;
                obj->vx = 0;
                fn_8007A98C(obj, obj->targetX, obj->y, 1);
            }
        }
        obj->x += obj->vx;
        break;
    }
    fn_800E9750(obj, 0xFFFF);
}
