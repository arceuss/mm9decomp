#include "types.h"

typedef struct Unk80063B60 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 flagsB;
    /* 0x0C */ u8 padC[0x10 - 0xC];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x20 - 0x13];
    /* 0x20 */ u8 unk20;
    /* 0x21 */ u8 unk21;
    /* 0x22 */ u8 pad22[0x2E - 0x22];
    /* 0x2E */ u8 unk2E;
    /* 0x2F */ u8 pad2F[0x34 - 0x2F];
    /* 0x34 */ struct Unk80063B60* parent;
    /* 0x38 */ u8 pad38[0x50 - 0x38];
    /* 0x50 */ struct {
        u32 hi : 30;
        u32 layer : 2;
    } bits50;
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
    /* 0x7D */ u8 pad7D[0xC8 - 0x7D];
    /* 0xC8 */ s32 kind;
} Unk80063B60;

extern u8 lbl_804ECBDC[4];
extern u8 lbl_804ECBE0[4];

void fn_80042D30(Unk80063B60* obj);
void fn_800E946C(Unk80063B60* obj, u8 anim);
void fn_800E9758(Unk80063B60* obj);
void fn_800E9750(Unk80063B60* obj, u16 arg1);

void fn_80063B60(Unk80063B60* obj) {
    Unk80063B60* parent = obj->parent;
    u32 f;

    if (parent->unk10 == 4) {
        fn_80042D30(obj);
        return;
    }
    switch (obj->step) {
    case 0:
        fn_800E946C(obj, lbl_804ECBDC[obj->kind]);
        obj->flagsB |= 0x20;
        obj->unk21 = parent->unk20;
        if (obj->kind == 0) {
            obj->unk2E = 0x10;
        } else {
            obj->bits50.layer = 3;
            obj->unk2E = 0x12;
        }
        obj->step++;
    case 1:
        obj->x = parent->x;
        obj->y = parent->y;
        if (parent->anim == 4 && obj->anim != lbl_804ECBE0[obj->kind]) {
            fn_800E946C(obj, lbl_804ECBE0[obj->kind]);
        }
        if (obj->anim == lbl_804ECBE0[obj->kind] && parent->anim != 4) {
            fn_800E946C(obj, lbl_804ECBDC[obj->kind]);
        }
        f = (parent->flagsA >> 4) & 1;
        if (f) {
            obj->flagsA |= 0x10;
        } else {
            obj->flagsA &= 0xEF;
        }
        obj->bits54.flip = f;
        if (parent->unk10 >= 2) {
            fn_800E9758(obj);
        } else {
            fn_800E9750(obj, 0xFFFF);
        }
        break;
    }
}
