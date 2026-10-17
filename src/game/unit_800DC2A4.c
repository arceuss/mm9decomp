#include "types.h"

typedef struct Unk802819B0Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
} Unk802819B0Entry;

typedef struct Unk800DC2A4Pos {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Unk800DC2A4Pos;

typedef struct Unk800DC2A4Parent {
    /* 0x000 */ u8 pad0[0xFF4];
    /* 0xFF4 */ u8 unkFF4;
} Unk800DC2A4Parent;

typedef struct Unk800DC2A4 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 padA[0x10 - 0xA];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0x18 - 0x16];
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[0x34 - 0x1C];
    /* 0x34 */ Unk800DC2A4Parent* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ Unk800DC2A4Pos pos;
    /* 0x68 */ u8 pad68[0x7D - 0x68];
    /* 0x7D */ s8 unk7D;
    /* 0x7E */ s8 unk7E;
} Unk800DC2A4;

extern Unk800DC2A4Pos lbl_802810E0[][18];
extern Unk802819B0Entry* lbl_802819B0[];

void fn_800E946C(Unk800DC2A4* obj, u8 arg1);
void fn_800E947C(Unk800DC2A4* obj, u8 arg1, s8 arg2, s8 arg3);
void fn_800E9750(Unk800DC2A4* obj, u16 arg1);

static inline void Mode2(Unk800DC2A4* obj) {
    obj->unk18 = lbl_802819B0[obj->unk9]->unk8;
    obj->unk10 = 2;
    obj->unk11 = 0;
    obj->step = 0;
    obj->unk13 = 0;
}

void fn_800DC2A4(Unk800DC2A4* obj) {
    Unk800DC2A4Parent* parent = obj->parent;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 6);
        obj->pos.x = lbl_802810E0[obj->unk14][obj->unk15].x;
        obj->pos.y = lbl_802810E0[obj->unk14][obj->unk15].y;
        obj->step++;
    case 1:
        if (parent->unkFF4 == 8) {
            obj->step++;
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    case 2:
        fn_800E947C(obj, 7, obj->unk7D, obj->unk7E);
        obj->step++;
    case 3:
        if (parent->unkFF4 == 9) {
            obj->step++;
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    case 4:
        fn_800E947C(obj, 8, obj->unk7D, obj->unk7E);
        obj->step++;
    case 5:
        if (parent->unkFF4 == 10) {
            obj->step++;
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    case 6:
        fn_800E947C(obj, 9, obj->unk7D, obj->unk7E);
        obj->step++;
    case 7:
        if (parent->unkFF4 == 11) {
            obj->step++;
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    case 8:
        fn_800E947C(obj, 10, obj->unk7D, obj->unk7E);
        obj->step++;
    case 9:
        if (parent->unkFF4 == 12) {
            obj->step++;
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    case 10:
        fn_800E947C(obj, 11, obj->unk7D, obj->unk7E);
        obj->step++;
    case 11:
        if (parent->unkFF4 == 13) {
            obj->step++;
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    case 12:
        fn_800E947C(obj, 12, obj->unk7D, obj->unk7E);
        obj->step++;
    case 13:
        if (parent->unkFF4 == 14) {
            obj->step++;
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    case 14:
        fn_800E947C(obj, 13, obj->unk7D, obj->unk7E);
        obj->step++;
    case 15:
        if (parent->unkFF4 == 15) {
            obj->step++;
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    case 16:
        fn_800E947C(obj, 14, obj->unk7D, obj->unk7E);
        obj->step++;
    case 17:
        if (parent->unkFF4 == 16) {
            Mode2(obj);
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    }
}
