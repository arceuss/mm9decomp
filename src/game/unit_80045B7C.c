#include "types.h"

typedef struct Unk80045B7C {
    /* 0x00 */ u8 pad0[0x12];
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x16 - 0x13];
    /* 0x16 */ u8 timer;
    /* 0x17 */ u8 pad17[0x60 - 0x17];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ s32 vx;
    /* 0x6C */ s32 vy;
} Unk80045B7C;

typedef struct Unk804EE984 {
    /* 0x00 */ u8 pad0[0x60];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
} Unk804EE984;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x21C];
    /* 0x21C */ u8 unk21C[1];
} Unk80304B90;

extern Unk804EE984* lbl_804EE984;
extern Unk80304B90 lbl_80304B90;


void fn_800E946C(Unk80045B7C* obj, s32 anim);
void fn_800E9750(Unk80045B7C* obj, u16 arg1);
u32 fn_80080484(void* cam, s32* pos, s32 arg2);
void fn_80042D30(Unk80045B7C* obj);

#define ABS(x) ((x) < 0 ? -(x) : (x))

void fn_80045B7C(Unk80045B7C* obj) {
    s32 dx;
    s32 dy;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 0);
        obj->vx = 0;
        obj->vy = 0;
        obj->timer = 10;
        obj->step++;
    case 1:
        fn_800E9750(obj, 0xFFFF);
        if (--obj->timer == 0) {
            dx = lbl_804EE984->x - obj->x;
            if (__abs(dx) % 256 == 0 || __abs(dy = (lbl_804EE984->y - 0xC00) - obj->y) % 256 == 0) {
                if (dx > 0) {
                    obj->vx = 0x50;
                } else {
                    obj->vx = -0x50;
                }
                if ((lbl_804EE984->y - 0xC00) - obj->y > 0) {
                    obj->vy = 0x50;
                } else {
                    obj->vy = -0x50;
                }
            } else if (ABS(dx) > ABS(dy)) {
                if (dx > 0) {
                    obj->vx = 0x50;
                } else {
                    obj->vx = -0x50;
                }
                obj->vy = 0;
            } else {
                if (dy > 0) {
                    obj->vy = 0x50;
                } else {
                    obj->vy = -0x50;
                }
                obj->vx = 0;
            }
            obj->timer = 10;
        }
        obj->x += obj->vx;
        obj->y += obj->vy;
        if (fn_80080484(lbl_80304B90.unk21C, &obj->x, 1) > 0x1000) {
            fn_80042D30(obj);
        }
        break;
    }
}
