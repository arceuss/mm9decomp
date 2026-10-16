#include "types.h"

typedef struct Unk800CB900 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 kind;
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x10 - 0xB];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 pad14[0x18 - 0x14];
    /* 0x18 */ void* unk18;
    /* 0x1C */ u8 pad1C[0x34 - 0x1C];
    /* 0x34 */ struct Unk800CB900* parent;
    /* 0x38 */ void* child;
    /* 0x3C */ u8 pad3C[0x60 - 0x3C];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0xC8 - 0x68];
    /* 0xC8 */ u8 unkC8;
} Unk800CB900;

extern void** lbl_80280390[];

void fn_800E946C(Unk800CB900* obj, u8 anim);
void* fn_80077510(Unk800CB900* obj, s32 arg1);
void fn_800E9750(Unk800CB900* obj, u16 arg1);
void fn_800E9244(Unk800CB900* obj);
u16 fn_800A32FC(s32 x, s32 y);

static inline void SetMode(Unk800CB900* obj, u8 mode) {
    obj->unk18 = lbl_80280390[obj->kind][mode];
    obj->unk10 = mode;
    obj->state = 0;
    obj->step = 0;
    obj->unk13 = 0;
}

void fn_800CB900(Unk800CB900* obj) {
    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 0);
        obj->child = fn_80077510(obj, 0);
        obj->step++;
    case 1:
        fn_800E9750(obj, 0xFFFF);
        if (obj->parent->unk10 >= 2) {
            obj->flagsA &= ~1;
            obj->flagsA &= 0xFD;
            fn_800E9244(obj);
            SetMode(obj, 3);
        } else if (obj->parent->unkC8 == 0) {
            obj->flagsA &= ~1;
            obj->flagsA &= 0xFD;
            fn_800E9244(obj);
            SetMode(obj, 3);
        } else if (fn_800A32FC(obj->x, obj->y - 0x100) == 0 && obj->child == NULL) {
            obj->child = fn_80077510(obj, 0);
        }
        break;
    }
}
