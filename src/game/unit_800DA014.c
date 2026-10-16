#include "types.h"

typedef struct Unk802819B0Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
} Unk802819B0Entry;

typedef struct Unk800DA014Parent {
    /* 0x000 */ u8 pad0[0x272];
    /* 0x272 */ s8 col;
    /* 0x273 */ s8 row;
    /* 0x274 */ s8 mode;
    /* 0x275 */ u8 pad275[0x287 - 0x275];
    /* 0x287 */ u8 unk287;
} Unk800DA014Parent;

typedef struct Unk800DA014 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 kind;
    /* 0x0A */ u8 padA[0x10 - 0xA];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 pad14[0x18 - 0x14];
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[0x34 - 0x1C];
    /* 0x34 */ Unk800DA014Parent* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0x8B - 0x68];
    /* 0x8B */ u8 mode;
} Unk800DA014;

extern Unk802819B0Entry* lbl_802819B0[];

void fn_800E946C(Unk800DA014* obj, u8 anim);
void fn_800E9750(Unk800DA014* obj, u16 arg1);

static inline void SyncAnim(Unk800DA014* obj, Unk800DA014Parent* parent, u8 anim) {
    if (obj->mode != parent->mode) {
        obj->mode = parent->mode;
        fn_800E946C(obj, anim);
    }
}

void fn_800DA014(Unk800DA014* obj) {
    Unk800DA014Parent* parent = obj->parent;

    if (parent->unk287 == 1) {
        obj->unk18 = lbl_802819B0[obj->kind]->unk8;
        obj->unk10 = 2;
        obj->state = 0;
        obj->step = 0;
        obj->unk13 = 0;
        return;
    }
    if (parent->mode == 0) {
        obj->x = (parent->col << 12) + 0x1400;
        obj->y = (parent->row << 12) + 0x5400;
        SyncAnim(obj, parent, 0xD);
    } else if (parent->mode == 1) {
        obj->x = 0xDC00;
        obj->y = 0x5C00;
        SyncAnim(obj, parent, 0xE);
    } else if (parent->mode == 2) {
        obj->x = 0xDC00;
        obj->y = 0x8400;
        SyncAnim(obj, parent, 0xE);
    } else if (parent->mode == 3) {
        obj->x = 0xDC00;
        obj->y = 0xBC00;
        SyncAnim(obj, parent, 0xE);
    } else if (parent->mode == 5) {
        obj->x = 0x8C00;
        obj->y = (parent->row << 12) + 0x5400;
        SyncAnim(obj, parent, 0x13);
    } else if (parent->mode == 6) {
        obj->x = 0xAC00;
        obj->y = (parent->row << 12) + 0x5400;
        SyncAnim(obj, parent, 0x13);
    }
    fn_800E9750(obj, 0xFFFF);
}
