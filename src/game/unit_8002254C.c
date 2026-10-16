#include "types.h"

typedef struct Unk8002254C {
    /* 0x00 */ u8 pad0[0x11];
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x34 - 0x13];
    /* 0x34 */ struct Unk8002254C* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ s32 vx;
    /* 0x6C */ u8 pad6C[0xD8 - 0x6C];
    /* 0xD8 */ u8 unkD8;
    /* 0xD9 */ u8 padD9;
    /* 0xDA */ u8 unkDA;
} Unk8002254C;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x25C];
    /* 0x25C */ s32 unk25C;
    /* 0x260 */ s32 unk260;
} Unk80304B90;

extern Unk80304B90 lbl_80304B90;

void fn_800E946C(Unk8002254C* obj, s32 arg1);
void fn_800E91F0(Unk8002254C* obj, void* data, s32 arg2);
void fn_8006CA38(Unk8002254C* obj, s32 x, s32 y, s32 arg3, s32 arg4, u8 idx);
void fn_800E9750(Unk8002254C* obj, u16 arg1);

void fn_8002254C(Unk8002254C* obj) {
    Unk8002254C* parent = obj->parent;
    u32 i;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 0x11);
        fn_800E91F0(obj, NULL, 1);
        obj->unkDA = 1;
        obj->unkD8 = 1;
        for (i = 0; i < 12; i++) {
            fn_8006CA38(obj, obj->x, obj->y, 1, 1, i);
        }
        obj->x = lbl_80304B90.unk25C + 0x9DFF;
        obj->y = lbl_80304B90.unk260 - 0x3801;
        obj->step++;
    case 1:
        if (parent->step >= 2) {
            obj->step++;
        }
        break;
    case 2:
        obj->vx = -0x180;
        obj->step++;
    case 3:
        obj->x += obj->vx;
        if (obj->x < lbl_80304B90.unk25C + 0x5FFF) {
            obj->x = lbl_80304B90.unk25C + 0x5FFF;
            obj->step++;
        }
        break;
    case 4:
        obj->step++;
    case 5:
        if (parent->state == 2) {
            obj->state = 2;
            obj->step = 0;
        }
        break;
    }
    fn_800E9750(obj, 0xFFFF);
}
