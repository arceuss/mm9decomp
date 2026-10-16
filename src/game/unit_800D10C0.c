#include "types.h"

typedef struct Unk800D10C0 {
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
    /* 0x68 */ s32 offset;
    /* 0x6C */ u8 pad6C[0xC8 - 0x6C];
    /* 0xC8 */ s32 baseX;
    /* 0xCC */ u8 padCC;
    /* 0xCD */ u8 unkCD;
} Unk800D10C0;

void fn_800E9750(Unk800D10C0* obj, u16 arg1);
void fn_800D124C(Unk800D10C0* obj);
void fn_800E946C(Unk800D10C0* obj, s32 arg1);

void fn_800D10C0(Unk800D10C0* obj) {
    switch (obj->step) {
    case 0:
        obj->timer = 90;
        obj->step++;
    case 1:
        if (--obj->timer == 0) {
            obj->step++;
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    case 2:
        obj->timer = 0;
        obj->step++;
    case 3:
        obj->offset = 0x2000 - (++obj->timer << 8);
        if (obj->offset <= 0) {
            obj->offset = 0;
            obj->state = 0;
            obj->step = 0;
        }
        if ((obj->unk14 & 0xF) == 1) {
            obj->x = obj->baseX - obj->offset;
        } else {
            obj->x = obj->baseX + obj->offset;
        }
        fn_800D124C(obj);
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
