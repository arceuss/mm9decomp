#include "types.h"

typedef struct Unk80060040 {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ u8 flagsC;
    /* 0x0D */ u8 padD[0x10 - 0xD];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x16 - 0x13];
    /* 0x16 */ u8 timer;
    /* 0x17 */ u8 pad17[0x34 - 0x17];
    /* 0x34 */ struct Unk80060040* parent;
    /* 0x38 */ u8 pad38[0x54 - 0x38];
    /* 0x54 */ u32 unk54;
    /* 0x58 */ u8 pad58[0x64 - 0x58];
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0x7F - 0x68];
    /* 0x7F */ u8 unk7F;
    /* 0x80 */ u8 pad80[0xD8 - 0x80];
    /* 0xD8 */ u8 unkD8;
} Unk80060040;

void fn_80042D30(Unk80060040* obj);
void fn_800E946C(Unk80060040* obj, s32 anim);
void fn_800E9758(Unk80060040* obj);
void fn_800E9750(Unk80060040* obj, u16 arg1);
void fn_800E9AA0(Unk80060040* obj, s32 arg1, s32 arg2);
void fn_800E9C90(Unk80060040* obj);

void fn_80060040(Unk80060040* obj) {
    Unk80060040* parent = obj->parent;

    if (parent->unk10 == 4) {
        fn_80042D30(obj);
        return;
    }
    obj->y = parent->y + 0x1000;
    if (parent->unkD8 == 3) {
        fn_800E946C(obj, 7);
        fn_800E9758(obj);
        return;
    }
    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 5);
        obj->flagsC |= 0x10;
        obj->unk54 &= ~0x200;
        fn_800E9AA0(obj, 1, 0);
        obj->timer = 0x30;
        obj->step++;
    case 1:
        fn_800E9750(obj, 0xFFFF);
        fn_800E9C90(obj);
        if (obj->timer == 0) {
            obj->step++;
        } else {
            obj->timer--;
        }
        break;
    case 2:
        fn_800E946C(obj, 5);
        obj->step++;
    case 3:
        fn_800E9750(obj, 0xFFFF);
        if (parent->unkD8 == 1) {
            obj->step++;
        }
        break;
    case 4:
        fn_800E946C(obj, 6);
        obj->timer = 0xB4;
        obj->step++;
    case 5:
        fn_800E9750(obj, 0xFFFF);
        if (obj->timer == 0) {
            obj->step++;
        } else {
            obj->timer--;
        }
        break;
    case 6:
        fn_800E946C(obj, 7);
        obj->step++;
    case 7:
        fn_800E9750(obj, 0xFFFF);
        if (obj->unk7F == 3) {
            obj->step++;
        }
        break;
    case 8:
        fn_800E946C(obj, 5);
        obj->timer = 0x14;
        parent->unkD8 = 2;
        obj->step++;
    case 9:
        fn_800E9750(obj, 0xFFFF);
        if (obj->timer == 0) {
            parent->unkD8 = 0;
            obj->step = 2;
        } else {
            obj->timer--;
        }
        break;
    }
}
