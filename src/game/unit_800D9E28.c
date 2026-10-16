#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk800D9E28 {
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
    /* 0x34 */ struct Unk800D9E28Parent* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0x8D - 0x68];
    /* 0x8D */ u8 unk8D;
    /* 0x8E */ u8 pad8E[0x90 - 0x8E];
    /* 0x90 */ u8 unk90;
    /* 0x91 */ u8 unk91;
    /* 0x92 */ u8 pad92[0xAC - 0x92];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
} Unk800D9E28;

extern Unk80280390Entry* lbl_802819B0[];

typedef struct Unk800D9E28Parent {
    /* 0x000 */ u8 pad0[0x26F];
    /* 0x26F */ s8 unk26F;
    /* 0x270 */ u8 unk270;
    /* 0x271 */ u8 pad271[0x276 - 0x271];
    /* 0x276 */ u8 unk276;
} Unk800D9E28Parent;

typedef struct Vec2i {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Vec2i;

extern Vec2i lbl_80280E48[];
extern u8 lbl_804ED3A8[8];

void fn_800E946C(Unk800D9E28* obj, u8 id);
void fn_800E947C(Unk800D9E28* obj, u8 id, s8 arg2, s8 arg3);
void fn_800E9750(Unk800D9E28* obj, u16 arg1);

void fn_800D9E28(Unk800D9E28* obj) {
    Unk800D9E28Parent* parent = obj->parent;
    u8 lit;

    if (parent->unk276 == 1) {
        obj->unk18 = lbl_802819B0[obj->unk9]->unk8;
        obj->unk10 = 2;
        obj->state = 0;
        obj->step = 0;
        obj->unk13 = 0;
        return;
    }
    lit = lbl_804ED3A8[parent->unk26F];
    if (obj->unk8D != lit) {
        if (lit == 0) {
            fn_800E946C(obj, 8);
        } else {
            lit = 1;
            fn_800E946C(obj, 0xB);
        }
        obj->unk8D = lit;
    }
    obj->unk60 = lbl_80280E48[obj->parent->unk26F].x;
    obj->unk64 = lbl_80280E48[obj->parent->unk26F].y;
    if (parent->unk270 == 0) {
        if (obj->unk91 == 1) {
            if (obj->unk90 == 0) {
                fn_800E947C(obj, 8, 0, 8);
            } else if (obj->unk90 == 1) {
                fn_800E947C(obj, 0xB, 0, 8);
            }
            obj->unk91 = 0;
        }
        fn_800E9750(obj, 0xFFFF);
    } else if (parent->unk26F != 3) {
        fn_800E947C(obj, 8, 1, 0);
        obj->unk90 = 0;
        obj->unk91 = 1;
        fn_800E9750(obj, 0xFFFF);
    } else {
        fn_800E947C(obj, 0xB, 1, 0);
        obj->unk90 = 1;
        obj->unk91 = 1;
        fn_800E9750(obj, 0xFFFF);
    }
}
