#include "types.h"

typedef struct Unk800CC868 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 kind;
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x10 - 0xB];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15[0x18 - 0x15];
    /* 0x18 */ void* unk18;
    /* 0x1C */ u8 pad1C[0x60 - 0x1C];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ s32 vx;
    /* 0x6C */ u8 pad6C[0xCA - 0x6C];
    /* 0xCA */ u16 unkCA;
    /* 0xCC */ struct Unk800CC868* target;
    /* 0xD0 */ struct Unk800CC868* unkD0;
} Unk800CC868;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x21C];
    /* 0x21C */ u8 unk21C[1];
} Unk80304B90;

extern Unk80304B90 lbl_80304B90;
extern void** lbl_80280390[];

void fn_800E946C(Unk800CC868* obj, u8 anim);
void fn_800E9750(Unk800CC868* obj, u16 arg1);
void fn_800E9244(Unk800CC868* obj);
u32 fn_80080484(void* cam, s32* pos, s32 arg2);
void fn_800CC9D4(Unk800CC868* obj);

static inline void SetMode(Unk800CC868* obj, u8 mode) {
    obj->unk18 = lbl_80280390[obj->kind][mode];
    obj->unk10 = mode;
    obj->state = 0;
    obj->step = 0;
    obj->unk13 = 0;
}

void fn_800CC868(Unk800CC868* obj) {
    Unk800CC868* t;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 1);
        obj->vx = 0;
        obj->step++;
    case 1:
        fn_800E9750(obj, 0xFFFF);
        t = obj->target;
        if (t != NULL && t->unk10 >= 3) {
            obj->flagsA &= ~1;
            obj->flagsA &= 0xFD;
            fn_800E9244(obj);
            SetMode(obj, 3);
            break;
        }
        if (obj->unk14 != 0) {
            obj->unkCA = t->unkD0->unkCA;
        } else if (fn_80080484(lbl_80304B90.unk21C, &obj->x, 1) >= 0x8000) {
            obj->flagsA &= ~1;
            obj->flagsA &= 0xFD;
            fn_800E9244(obj);
            SetMode(obj, 3);
            break;
        }
        fn_800CC9D4(obj);
        break;
    }
}
