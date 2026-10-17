#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk800DF174 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 flagsB;
    /* 0x0C */ u8 padC[0x10 - 0xC];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 unk17;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[0x20 - 0x1C];
    /* 0x20 */ u8 unk20;
    /* 0x21 */ u8 unk21;
    /* 0x22 */ u8 pad22[0x2A - 0x22];
    /* 0x2A */ s16 unk2A;
    /* 0x2C */ u8 unk2C;
    /* 0x2D */ u8 pad2D;
    /* 0x2E */ u8 unk2E;
    /* 0x2F */ u8 unk2F;
    /* 0x30 */ u8 pad30[0x34 - 0x30];
    /* 0x34 */ struct Unk800DF174Parent* parent;
    /* 0x38 */ u8 pad38[0x54 - 0x38];
    /* 0x54 */ u32 unk54_0 : 21;
    /* 0x54 */ u32 flipX : 1;
    /* 0x54 */ u32 unk54_22 : 10;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0xAC - 0x68];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
} Unk800DF174;

extern Unk80280390Entry* lbl_802819B0[];

typedef struct Unk800DF174Parent {
    /* 0x0000 */ u8 pad0[0xFF4];
    /* 0x0FF4 */ u8 unkFF4;
} Unk800DF174Parent;

typedef struct Vec2i {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Vec2i;

extern Vec2i lbl_802810E0[][18];

void fn_800E946C(Unk800DF174* obj, u8 id);
void fn_800E9750(Unk800DF174* obj, u16 arg1);

static inline void SyncFlip(Unk800DF174* obj) {
    if (obj->flipX) {
        obj->flagsA |= 0x10;
    } else {
        obj->flagsA &= 0xEF;
    }
}

typedef struct Unk8038E738 {
    /* 0x0 */ u8 pad0[0xA];
    /* 0xA */ u16 unkA;
} Unk8038E738;

extern Unk8038E738 lbl_8038E738;

static inline void Wait(Unk800DF174* obj, Unk800DF174Parent* parent, u8 phase) {
    if (parent->unkFF4 == phase) {
        obj->step++;
    }
    fn_800E9750(obj, 0xFFFF);
}

void fn_800DF174(Unk800DF174* obj) {
    Unk800DF174Parent* parent = obj->parent;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 0);
        obj->flipX = 0;
        SyncFlip(obj);
        obj->unk60 = lbl_802810E0[obj->unk14][obj->unk15].x;
        obj->unk64 = lbl_802810E0[obj->unk14][obj->unk15].y;
        obj->step++;
    case 1:
        Wait(obj, parent, 2);
        break;
    case 2:
        fn_800E946C(obj, 1);
        obj->step++;
    case 3:
        Wait(obj, parent, 3);
        break;
    case 4:
        fn_800E946C(obj, 0);
        obj->step++;
    case 5:
        Wait(obj, parent, 4);
        break;
    case 6:
        fn_800E946C(obj, 1);
        obj->step++;
    case 7:
        if (lbl_8038E738.unkA == 0) {
            obj->step++;
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    case 8:
        fn_800E946C(obj, 0);
        obj->step++;
    case 9:
        Wait(obj, parent, 6);
        break;
    case 10:
        obj->flagsA &= ~1;
        obj->step++;
    case 11:
        Wait(obj, parent, 0x10);
        break;
    case 12:
        obj->flagsA |= 1;
        obj->step++;
    case 13:
        Wait(obj, parent, 0x13);
        break;
    case 14:
        obj->unk16 = 0;
        obj->step++;
    case 15:
        if (parent->unkFF4 == 0xFF) {
            obj->unk18 = lbl_802819B0[obj->unk9]->unk8;
            obj->unk10 = 2;
            obj->state = 0;
            obj->step = 0;
            obj->unk13 = 0;
        }
        obj->unk16 = (u8)(obj->unk16 + 1) % 32;
        if (obj->unk16 & 0x10) {
            obj->flipX = 1;
            SyncFlip(obj);
        } else {
            obj->flipX = 0;
            SyncFlip(obj);
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    }
}
