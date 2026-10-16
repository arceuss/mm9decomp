#include "types.h"

typedef struct Unk8002044C {
    /* 0x00 */ u8 pad0[0x12];
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x16 - 0x13];
    /* 0x16 */ u8 timer;
    /* 0x17 */ u8 pad17[0x60 - 0x17];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ s32 vx;
    /* 0x6C */ s32 vy;
} Unk8002044C;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x25C];
    /* 0x25C */ s32 unk25C;
} Unk80304B90;

extern Unk80304B90 lbl_80304B90;

void fn_800E946C(Unk8002044C* obj, s32 arg1);
s32 fn_800A4098(s32 x, s32 y);
void fn_800E9750(Unk8002044C* obj, u16 arg1);

void fn_8002044C(Unk8002044C* obj) {
    s32 y;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 1);
        obj->vy = -0x100;
        obj->step++;
    case 1:
        y = obj->y + obj->vy;
        obj->y = y;
        if (y < fn_800A4098(obj->x, y) - 0x1800) {
            obj->y = fn_800A4098(obj->x, y) - 0x1800;
            obj->step++;
        }
        break;
    case 2:
        obj->timer = 0x12;
        obj->step++;
    case 3:
        if (obj->timer == 0) {
            obj->step++;
        } else {
            obj->timer--;
        }
        break;
    case 4:
        obj->vx = 0x80;
        obj->step++;
    case 5:
        obj->x += obj->vx;
        if (obj->vx < 0) {
            if (obj->x < lbl_80304B90.unk25C) {
                obj->vx = 0x80;
            }
        } else if (obj->x > lbl_80304B90.unk25C + 0x3400) {
            obj->vx = -0x80;
        }
        break;
    }
    fn_800E9750(obj, 0xFFFF);
}
