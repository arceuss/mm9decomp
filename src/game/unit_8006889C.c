#include "types.h"

typedef struct Vec2i {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Vec2i;

typedef struct Unk8006889C {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x12 - 0xB];
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
} Unk8006889C;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x21C];
    /* 0x21C */ u8 unk21C[1];
} Unk80304B90;

extern Unk80304B90 lbl_80304B90;

void fn_800E9244(Unk8006889C* obj);
u32 fn_80080484(void* cam, s32* pos, s32 arg2);
void fn_80042CF8(Unk8006889C* obj, s32 arg1);
void fn_80040AD0(s32 arg0, Vec2i* pos, s32 arg2, s32 arg3);
void fn_800E9758(Unk8006889C* obj);

void fn_8006889C(Unk8006889C* obj) {
    Vec2i pos;
    u8 f;

    switch (obj->step) {
    case 0:
        fn_800E9244(obj);
        obj->gravity = -0x20;
        obj->vy = 0;
        obj->timer = 0x10;
        obj->step++;
    case 1:
        obj->y += obj->vy;
        if (fn_80080484(lbl_80304B90.unk21C, &obj->x, 1) > 0x1000) {
            fn_80042CF8(obj, 2);
            pos.x = obj->x;
            pos.y = obj->y;
            fn_80040AD0(2, &pos, 0, 0);
            fn_800E9244(obj);
            obj->flagsA &= ~1;
            fn_80042CF8(obj, 4);
            break;
        }
        obj->vy += obj->gravity;
        if (obj->vy < -0x700) {
            obj->vy = -0x700;
        }
        if (--obj->timer == 0) {
            f = !((obj->flagsA >> 4) & 1);
            if (f) {
                obj->flagsA |= 0x10;
            } else {
                obj->flagsA &= 0xEF;
            }
            obj->bits54.flip = f;
            obj->timer = 0x10;
        }
        fn_800E9758(obj);
        break;
    }
}
