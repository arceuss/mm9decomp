#include "types.h"

typedef struct Unk800D0C8C {
    /* 0x00 */ u8 pad0[0x11];
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15[0x60 - 0x15];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ s32 speed;
    /* 0x6C */ u8 pad6C[0x70 - 0x6C];
    /* 0x70 */ s32 accel;
    /* 0x74 */ u8 pad74[0xC8 - 0x74];
    /* 0xC8 */ s32 baseX;
    /* 0xCC */ u8 unkCC;
    /* 0xCD */ u8 unkCD;
} Unk800D0C8C;

void fn_800E9750(Unk800D0C8C* obj, u16 arg1);
void fn_800D124C(Unk800D0C8C* obj);
void fn_800E946C(Unk800D0C8C* obj, s32 arg1);
void fn_800D5234(s32 se);

void fn_800D0C8C(Unk800D0C8C* obj) {
    switch (obj->step) {
    case 0:
        obj->unkCC = 0;
        obj->accel = 0x20;
        obj->speed = 0x500;
        fn_800D5234(0x36);
        obj->step++;
    case 1:
        if (__abs(obj->x - obj->baseX) & 0x800) {
            if (obj->unkCD != 1) {
                fn_800E946C(obj, 1);
                obj->unkCD = 1;
            }
        } else if (obj->unkCD != 0) {
            fn_800E946C(obj, 0);
            obj->unkCD = 0;
        }
        if (obj->unk14 & 0xF) {
            obj->x += obj->speed;
            obj->speed -= obj->accel;
            if (obj->speed < 0x80) {
                obj->speed = 0x80;
            }
            if (obj->baseX + 0x5400 <= obj->x) {
                fn_800E946C(obj, 2);
            }
            if (obj->baseX + 0x5C00 <= obj->x) {
                obj->x = obj->baseX + 0x5C00;
                obj->state = 2;
                obj->step = 0;
            }
        } else {
            obj->x -= obj->speed;
            obj->speed -= obj->accel;
            if (obj->speed < 0x80) {
                obj->speed = 0x80;
            }
            if (obj->baseX - 0x5400 >= obj->x) {
                fn_800E946C(obj, 2);
            }
            if (obj->baseX - 0x5C00 >= obj->x) {
                obj->x = obj->baseX - 0x5C00;
                obj->state = 2;
                obj->step = 0;
            }
        }
        fn_800D124C(obj);
        fn_800E9750(obj, 0xFFFF);
        break;
    }
}
