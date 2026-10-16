#include "types.h"

typedef struct Unk800D21FC {
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
    /* 0x1C */ u8 pad1C[0x34 - 0x1C];
    /* 0x34 */ struct Unk800D21FC* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0xC8 - 0x68];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 padCC[0xD8 - 0xCC];
    /* 0xD8 */ s32 unkD8;
} Unk800D21FC;

typedef struct Unk803051D8 {
    /* 0x00 */ u8 pad0[0x2];
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 pad3[0x38 - 0x3];
} Unk803051D8;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x21C];
    /* 0x21C */ u8 unk21C[1];
} Unk80304B90;

extern Unk803051D8 lbl_803051D8;
extern Unk80304B90 lbl_80304B90;
extern void** lbl_80280390[];
extern void (*lbl_804ED2D0[2])(Unk800D21FC* obj);

void fn_800E9244(Unk800D21FC* obj);
u32 fn_80080484(void* cam, s32* pos, s32 arg2);

static inline void SetMode(Unk800D21FC* obj, u8 mode) {
    obj->unk18 = lbl_80280390[obj->kind][mode];
    obj->unk10 = mode;
    obj->state = 0;
    obj->step = 0;
    obj->unk13 = 0;
}

void fn_800D21FC(Unk800D21FC* obj) {
    Unk800D21FC* parent = obj->parent;

    if (lbl_803051D8.unk2 & 0x20) {
        obj->flagsA &= ~1;
        obj->flagsA &= 0xFD;
        fn_800E9244(obj);
        SetMode(obj, 3);
        return;
    }
    fn_80080484(lbl_80304B90.unk21C, &obj->x, 1);
    if (fn_80080484(lbl_80304B90.unk21C, &obj->x, 1) > 0x4000) {
        obj->flagsA &= ~1;
        obj->flagsA &= 0xFD;
        fn_800E9244(obj);
        SetMode(obj, 3);
        return;
    }
    if (obj->unk14 == 0) {
        obj->unkC8 = parent->unkD8;
        if (parent->unk10 >= 2) {
            SetMode(obj, 2);
            return;
        }
    } else {
        if (parent->unk10 >= 2) {
            SetMode(obj, 2);
            return;
        }
        obj->unkC8 = parent->unkC8;
    }
    lbl_804ED2D0[obj->state](obj);
}
