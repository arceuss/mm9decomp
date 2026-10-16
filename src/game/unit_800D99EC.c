#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk800D99EC {
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
    /* 0x34 */ struct Unk800D99ECParent* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0x8A - 0x68];
    /* 0x8A */ u8 unk8A;
    /* 0x8B */ u8 unk8B;
    /* 0x8C */ u8 unk8C;
    /* 0x8D */ u8 unk8D;
    /* 0x8E */ u8 unk8E;
    /* 0x8F */ u8 unk8F;
    /* 0x90 */ u8 unk90;
    /* 0x91 */ u8 unk91;
    /* 0x92 */ u8 pad92[0xAC - 0x92];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
} Unk800D99EC;

extern Unk80280390Entry* lbl_802819B0[];

typedef struct Unk800D99ECParent {
    /* 0x000 */ u8 pad0[0x26D];
    /* 0x26D */ s8 unk26D;
} Unk800D99ECParent;

typedef struct Vec2i {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Vec2i;

extern Vec2i lbl_80280E28[];
extern void (*lbl_80280E7C[])(Unk800D99EC* obj);

void fn_800E9424(Unk800D99EC* obj, u16 anim);
void fn_800E946C(Unk800D99EC* obj, u8 id);

void fn_800D99EC(Unk800D99EC* obj) {
    Unk800D99ECParent* parent;

    obj->flagsA |= 1;
    parent = obj->parent;
    if (obj->unk8C == 0) {
        obj->unk8F = 0;
        fn_800E9424(obj, 0x38);
        fn_800E946C(obj, 0xE);
        obj->unk8A = 0;
        obj->unk8B = 0;
        obj->unk17 = 0;
    } else if (obj->unk8C == 1) {
        obj->unk8F = 0;
        fn_800E9424(obj, 0x4B);
        fn_800E946C(obj, 8);
        obj->unk8D = 0;
        obj->unk91 = 0;
        obj->unk60 = lbl_80280E28[parent->unk26D].x;
        obj->unk64 = lbl_80280E28[parent->unk26D].y;
    } else if (obj->unk8C == 2) {
        obj->unk8F = 0;
        fn_800E9424(obj, 0x4B);
        obj->unk8B = 0;
        fn_800E946C(obj, 0xD);
        obj->unk90 = 0;
        obj->unk91 = 0;
    } else if (obj->unk8C == 3) {
        fn_800E9424(obj, 0x4B);
        obj->unk17 = 0;
        obj->unk8E = 0;
        obj->unk8B = 0;
        if (obj->unk15 == 1) {
            fn_800E946C(obj, 0);
        } else if (obj->unk15 == 2) {
            fn_800E946C(obj, 1);
        } else if (obj->unk15 == 3) {
            fn_800E946C(obj, 3);
        }
    } else if (obj->unk8C == 4) {
        fn_800E9424(obj, 0x4B);
        fn_800E946C(obj, 0x11);
    }
    obj->unk18 = lbl_802819B0[obj->unk9]->unk4;
    obj->unk10 = 1;
    obj->state = 0;
    obj->step = 0;
    obj->unk13 = 0;
    lbl_80280E7C[obj->unk8C](obj);
}
