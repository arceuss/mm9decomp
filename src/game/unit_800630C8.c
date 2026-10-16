#include "types.h"

typedef struct Unk800630C8 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 flagsB;
    /* 0x0C */ u8 padC[0x10 - 0xC];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 pad14[0x16 - 0x14];
    /* 0x16 */ u8 timer;
    /* 0x17 */ u8 unk17;
    /* 0x18 */ u8 pad18[0x20 - 0x18];
    /* 0x20 */ u8 unk20;
    /* 0x21 */ u8 unk21;
    /* 0x22 */ u8 pad22[0x34 - 0x22];
    /* 0x34 */ struct Unk800630C8* parent;
    /* 0x38 */ u8 pad38[0x54 - 0x38];
    /* 0x54 */ struct {
        u32 hi : 21;
        u32 flip : 1;
        u32 low : 10;
    } bits54;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0x7C - 0x68];
    /* 0x7C */ u8 anim;
    /* 0x7D */ u8 pad7D[0xA0 - 0x7D];
    /* 0xA0 */ u32 hitFlags;
    /* 0xA4 */ u8 padA4[0xE2 - 0xA4];
    /* 0xE2 */ u8 unkE2;
    /* 0xE3 */ u8 unkE3;
} Unk800630C8;

void fn_80042D30(Unk800630C8* obj);
void fn_800E946C(Unk800630C8* obj, s32 anim);
void fn_800E9AA0(Unk800630C8* obj, s32 arg1, s32 arg2);
void fn_800E9750(Unk800630C8* obj, u16 arg1);
void fn_800E9C90(Unk800630C8* obj);

void fn_800630C8(Unk800630C8* obj) {
    Unk800630C8* parent = obj->parent;
    u32 f;

    if (parent->unk10 == 4) {
        fn_80042D30(obj);
        return;
    }
    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 1);
        fn_800E9AA0(obj, 0, 0);
        obj->flagsB |= 0x20;
        obj->unk21 = parent->unk20;
        obj->timer = 0;
        obj->unk17 = 0;
        obj->step++;
    case 1:
        parent = obj->parent;
        if (parent->unkE2 != 0 && obj->unk17 == 0) {
            fn_800E9AA0(obj, 1, 0);
            obj->unk17++;
        }
        if (parent->anim == 4 && obj->anim != 0xD) {
            fn_800E946C(obj, 0xD);
        }
        if (parent->hitFlags & 1) {
            fn_800E946C(obj, 2);
            obj->timer = 8;
        }
        if (obj->anim == 2) {
            if (obj->timer == 0) {
                fn_800E946C(obj, 1);
            } else {
                obj->timer--;
            }
        }
        if (obj->anim == 0xD && parent->anim != 4) {
            fn_800E946C(obj, 1);
        }
        if (parent->unkE3 != 0 && parent->anim != 4) {
            fn_800E946C(obj, 0xC);
        }
        obj->x = parent->x + (((parent->flagsA >> 3) & 2) - 1) * 0x5000;
        obj->y = parent->y - 0x800;
        if (parent->unk10 >= 2) {
            obj->step++;
        }
        break;
    case 2:
        fn_800E946C(obj, 2);
        obj->unk13 = 0;
        obj->timer = 0x10;
        obj->step++;
    case 3:
        obj->x = parent->x + (((parent->flagsA >> 3) & 2) - 1) * 0x5000;
        obj->y = parent->y - 0x800;
        if (obj->timer == 0) {
            if (obj->unk13 == 0) {
                obj->unk13++;
                fn_800E9AA0(obj, 2, 0);
            }
        } else {
            obj->timer--;
        }
        break;
    }
    f = (parent->flagsA >> 4) & 1;
    if (f) {
        obj->flagsA |= 0x10;
    } else {
        obj->flagsA &= 0xEF;
    }
    obj->bits54.flip = f;
    fn_800E9750(obj, 0xFFFF);
    fn_800E9C90(obj);
}
