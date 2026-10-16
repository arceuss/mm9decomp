#include "types.h"

typedef struct Unk8007AC44 {
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
    /* 0x34 */ struct Unk8007AC44* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ s32 vx;
    /* 0x6C */ s32 vy;
    /* 0x70 */ u8 pad70[0x74 - 0x70];
    /* 0x74 */ s32 gravity;
} Unk8007AC44;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x21C];
    /* 0x21C */ u8 unk21C[1];
} Unk80304B90;

extern Unk80304B90 lbl_80304B90;
extern void** lbl_80270168[];

void fn_800E9244(Unk8007AC44* obj);
void fn_800E946C(Unk8007AC44* obj, s32 anim);
void fn_800E9750(Unk8007AC44* obj, u16 arg1);
u32 fn_80080484(void* cam, s32* pos, s32 arg2);

static inline void SetMode(Unk8007AC44* obj, u8 mode) {
    obj->unk18 = lbl_80270168[obj->kind][mode];
    obj->unk10 = mode;
    obj->state = 0;
    obj->step = 0;
    obj->unk13 = 0;
}

void fn_8007AC44(Unk8007AC44* obj) {
    if (obj->parent->unk10 >= 2) {
        obj->flagsA &= ~1;
        obj->flagsA &= 0xFD;
        fn_800E9244(obj);
        SetMode(obj, 3);
        return;
    }
    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 0);
        obj->vy = 0;
        obj->gravity = 0x20;
        obj->step++;
    case 1:
        obj->y += obj->vy;
        obj->vy += obj->gravity;
        if (obj->vy > 0x600) {
            obj->vy = 0x600;
        }
        if (fn_80080484(lbl_80304B90.unk21C, &obj->x, 1) >= 0x2000) {
            obj->flagsA &= ~1;
            obj->flagsA &= 0xFD;
            fn_800E9244(obj);
            SetMode(obj, 3);
            return;
        }
        break;
    }
    fn_800E9750(obj, 0xFFFF);
}
