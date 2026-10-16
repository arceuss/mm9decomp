#include "types.h"

typedef struct Unk800776DC {
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
    /* 0x1C */ u8 pad1C[0x2A - 0x1C];
    /* 0x2A */ s16 unk2A;
    /* 0x2C */ u8 unk2C;
    /* 0x2D */ u8 pad2D;
    /* 0x2E */ u8 unk2E;
    /* 0x2F */ u8 unk2F;
    /* 0x30 */ u8 pad30[0x34 - 0x30];
    /* 0x34 */ struct Unk800776DC* parent;
    /* 0x38 */ struct Unk800776DC* child;
    /* 0x3C */ u8 pad3C[0x60 - 0x3C];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0x7D - 0x68];
    /* 0x7D */ u8 unk7D;
} Unk800776DC;

extern void** lbl_80270168[];
extern void* lbl_804EE810;

void fn_800E9244(Unk800776DC* obj);
void fn_800E946C(Unk800776DC* obj, s32 anim);
void fn_800E9758(Unk800776DC* obj);
u16 fn_800A32FC(s32 x, s32 y);
Unk800776DC* fn_800E8C44(void* pool);

static inline void SetMode(Unk800776DC* obj, u8 mode) {
    obj->unk18 = lbl_80270168[obj->kind][mode];
    obj->unk10 = mode;
    obj->state = 0;
    obj->step = 0;
    obj->unk13 = 0;
}

static inline Unk800776DC* Spawn(Unk800776DC* parent) {
    Unk800776DC* obj = fn_800E8C44(lbl_804EE810);

    if (obj != NULL) {
        obj->unk2E = 0x10;
        obj->kind = 7;
        obj->unk18 = lbl_80270168[7][0];
        obj->unk2A = 0;
        obj->unk2C = 0;
        obj->unk2F = 0;
        obj->parent = parent;
        obj->x = parent->x;
        obj->y = parent->y - 0x1000;
        obj->unk14 = 0;
    }
    return obj;
}

void fn_800776DC(Unk800776DC* obj) {
    Unk800776DC* parent;
    u16 tile;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 0);
        obj->child = NULL;
        obj->step++;
    case 1:
        fn_800E9758(obj);
        parent = obj->parent;
        if (parent != NULL) {
            obj->unk7D = parent->unk7D;
            if (parent->unk10 >= 2) {
                obj->flagsA &= ~1;
                obj->flagsA &= 0xFD;
                fn_800E9244(obj);
                SetMode(obj, 3);
                break;
            }
        }
        tile = fn_800A32FC(obj->x, obj->y - 0x100);
        if (tile != 0 && (tile & 0xF) != 4) {
            obj->parent->child = NULL;
            obj->flagsA &= ~1;
            obj->flagsA &= 0xFD;
            fn_800E9244(obj);
            SetMode(obj, 3);
            break;
        }
        if (obj->child == NULL) {
            obj->child = Spawn(obj);
        }
        break;
    }
}
