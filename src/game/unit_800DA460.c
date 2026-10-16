#include "types.h"

typedef struct Unk802819B0Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
} Unk802819B0Entry;

typedef struct Unk800DA460Parent {
    /* 0x0000 */ u8 pad0[0x100A];
    /* 0x100A */ u8 unk100A;
    /* 0x100B */ u8 pad100B;
    /* 0x100C */ s8 unk100C;
    /* 0x100D */ s8 unk100D;
    /* 0x100E */ s8 unk100E;
    /* 0x100F */ s8 unk100F;
    /* 0x1010 */ s8 unk1010;
} Unk800DA460Parent;

typedef struct Unk800DA460 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 kind;
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x10 - 0xB];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 pad14;
    /* 0x15 */ u8 part;
    /* 0x16 */ u8 pad16;
    /* 0x17 */ u8 blink;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[0x34 - 0x1C];
    /* 0x34 */ Unk800DA460Parent* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0x8B - 0x68];
    /* 0x8B */ u8 unk8B;
    /* 0x8C */ u8 pad8C[0x8E - 0x8C];
    /* 0x8E */ u8 unk8E;
    /* 0x8F */ u8 unk8F;
} Unk800DA460;

extern Unk802819B0Entry* lbl_802819B0[];

void fn_800E946C(Unk800DA460* obj, u8 anim);
void fn_800E9750(Unk800DA460* obj, u16 arg1);

void fn_800DA460(Unk800DA460* obj) {
    Unk800DA460Parent* parent = obj->parent;
    s8 v;

    if (parent->unk100A == 1) {
        obj->unk18 = lbl_802819B0[obj->kind]->unk8;
        obj->unk10 = 2;
        obj->state = 0;
        obj->step = 0;
        obj->unk13 = 0;
        return;
    }
    if ((u8)(obj->part + 0xFF) <= 1) {
        if (obj->unk8F == 1) {
            v = parent->unk100F;
            if (obj->unk8E != v) {
                obj->unk8E = v;
                obj->flagsA |= 1;
                obj->blink = 0;
            } else {
                obj->blink = (obj->blink + 1) & 0x1F;
                if (obj->part == 1) {
                    if (parent->unk100D != 0) {
                        if (obj->blink >> 4) {
                            obj->flagsA &= ~1;
                        } else {
                            obj->flagsA |= 1;
                        }
                    } else {
                        obj->flagsA &= ~1;
                    }
                } else if (obj->part == 2) {
                    if (parent->unk100E != 0) {
                        if (obj->blink >> 4) {
                            obj->flagsA &= ~1;
                        } else {
                            obj->flagsA |= 1;
                        }
                    } else {
                        obj->flagsA &= ~1;
                    }
                }
            }
        }
    } else if (obj->part == 3 && obj->unk8F == 1) {
        v = parent->unk1010;
        if (v == 0) {
            if (obj->unk8B != v) {
                obj->unk8B = v;
                fn_800E946C(obj, 3);
            }
            obj->x = 0x6400;
            obj->y = (parent->unk100C << 12) + 0x4400;
        } else {
            if (obj->unk8B != v) {
                obj->unk8B = v;
                fn_800E946C(obj, 0xA);
            }
            obj->x = 0xDD00;
            obj->y = 0xBC00;
        }
    }
    fn_800E9750(obj, 0xFFFF);
}
