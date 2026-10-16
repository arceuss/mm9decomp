#include "types.h"

typedef struct Unk802819B0Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
} Unk802819B0Entry;

typedef struct Unk800D7F58Pos {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Unk800D7F58Pos;

typedef struct Unk800D7F58Parent {
    /* 0x0000 */ u8 pad0[0xFF4];
    /* 0x0FF4 */ u8 low;
    /* 0x0FF5 */ u8 slot;
    /* 0x0FF6 */ u8 padFF6;
    /* 0x0FF7 */ u8 page;
} Unk800D7F58Parent;

typedef struct Unk800D7F58 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 kind;
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x10 - 0xB];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 pad14[0x16 - 0x14];
    /* 0x16 */ u8 slot;
    /* 0x17 */ u8 blink;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[0x34 - 0x1C];
    /* 0x34 */ Unk800D7F58Parent* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0x88 - 0x68];
    /* 0x88 */ u8 page;
} Unk800D7F58;

typedef struct Unk8036CF50 {
    /* 0x0 */ s32 stage;
    /* 0x4 */ u8 pad4[0xEFE0 - 0x4];
} Unk8036CF50;

extern Unk802819B0Entry* lbl_802819B0[];
extern Unk8036CF50 lbl_8036CF50;
extern Unk800D7F58Pos lbl_80280A50[][4];

void fn_800E946C(Unk800D7F58* obj, u8 anim);
void fn_800E9750(Unk800D7F58* obj, u16 arg1);

void fn_800D7F58(Unk800D7F58* obj) {
    Unk800D7F58Parent* parent = obj->parent;
    u8 t;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 0xE);
        obj->x = lbl_80280A50[lbl_8036CF50.stage][parent->slot].x;
        if (parent->low == 0) {
            obj->y = lbl_80280A50[lbl_8036CF50.stage][parent->slot].y;
        } else {
            obj->y = lbl_80280A50[lbl_8036CF50.stage][parent->slot].y + 0x800;
        }
        obj->slot = parent->slot;
        obj->blink = 0;
        obj->page = parent->page;
        obj->step++;
    case 1:
        if (obj->page != parent->page) {
            obj->unk18 = lbl_802819B0[obj->kind]->unk8;
            obj->unk10 = 2;
            obj->state = 0;
            obj->step = 0;
            obj->unk13 = 0;
        }
        t = obj->blink + 1;
        obj->blink = t & 0x1F;
        if ((t >> 4) & 1) {
            obj->flagsA &= ~1;
        } else {
            obj->flagsA |= 1;
        }
        if (obj->slot != parent->slot) {
            if (parent->low == 0) {
                obj->x = lbl_80280A50[lbl_8036CF50.stage][parent->slot].x;
                obj->y = lbl_80280A50[lbl_8036CF50.stage][parent->slot].y;
                obj->slot = parent->slot;
                obj->blink = 0;
            } else {
                obj->x = lbl_80280A50[lbl_8036CF50.stage][parent->slot].x;
                obj->y = lbl_80280A50[lbl_8036CF50.stage][parent->slot].y + 0x800;
                obj->slot = parent->slot;
                obj->blink = 0;
            }
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    }
}
