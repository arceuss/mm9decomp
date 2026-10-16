#include "types.h"

typedef struct Unk800D0F30 {
    /* 0x00 */ u8 pad0[0x11];
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 timer;
    /* 0x17 */ u8 pad17[0x60 - 0x17];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ s32 speed;
    /* 0x6C */ u8 pad6C[0x70 - 0x6C];
    /* 0x70 */ s32 accel;
    /* 0x74 */ u8 pad74[0xC8 - 0x74];
    /* 0xC8 */ s32 baseX;
    /* 0xCC */ u8 unkCC;
    /* 0xCD */ u8 unkCD;
    /* 0xCE */ u8 padCE[0xD0 - 0xCE];
    /* 0xD0 */ s32 targetX;
} Unk800D0F30;

void fn_800E9750(Unk800D0F30* obj, u16 arg1);
void fn_800D13A8(Unk800D0F30* obj);
void fn_800E946C(Unk800D0F30* obj, s32 arg1);

void fn_800D0F30(Unk800D0F30* obj) {
    switch (obj->step) {
    case 0:
        obj->unkCC = 0;
        obj->accel = 0x10;
        obj->speed = 0x400;
        obj->step++;
    case 1:
        if (obj->unk14 & 0xF) {
            obj->x -= obj->speed;
            obj->speed -= obj->accel;
            if (obj->speed < 0x100) {
                obj->speed = 0x100;
            }
            if (obj->targetX >= obj->x) {
                obj->x = obj->targetX;
                obj->state = 4;
                obj->step = 0;
            }
        } else {
            obj->x += obj->speed;
            obj->speed -= obj->accel;
            if (obj->speed < 0x100) {
                obj->speed = 0x100;
            }
            if (obj->targetX <= obj->x) {
                obj->x = obj->targetX;
                obj->state = 4;
                obj->step = 0;
            }
        }
        fn_800D13A8(obj);
        if (__abs(obj->x - obj->baseX) & 0x800) {
            if (obj->unkCD != 1) {
                fn_800E946C(obj, 1);
                obj->unkCD = 1;
            }
        } else if (obj->unkCD != 0) {
            fn_800E946C(obj, 0);
            obj->unkCD = 0;
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    }
}
