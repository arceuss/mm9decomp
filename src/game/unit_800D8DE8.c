#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk800D8DE8 {
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
    /* 0x34 */ struct Unk800D8DE8Parent* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0x7F - 0x68];
    /* 0x7F */ u8 unk7F;
    /* 0x80 */ u8 pad80[0xAC - 0x80];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
} Unk800D8DE8;


typedef struct Unk800D8DE8Parent {
    /* 0x0 */ u8 pad0[0x6];
    /* 0x6 */ s16 unk6;
} Unk800D8DE8Parent;

extern s8 lbl_804ED380[8];
extern u8 lbl_804ED378[8];
extern u16 lbl_80280CA8[];

void fn_800E9424(Unk800D8DE8* obj, u16 anim);
void fn_800E946C(Unk800D8DE8* obj, u8 id);
void fn_800E9AA0(Unk800D8DE8* obj, s32 arg1, s32 arg2);
void fn_800E9750(Unk800D8DE8* obj, u16 arg1);
void fn_800E9C90(Unk800D8DE8* obj);
void fn_800E9758(Unk800D8DE8* obj);

void fn_800D8DE8(Unk800D8DE8* obj) {
    Unk800D8DE8Parent* parent = obj->parent;

    if (obj->step == 0) {
        fn_800E9424(obj, 0);
        fn_800E946C(obj, 0xD);
        obj->unk16 = 0;
        obj->unk60 = 0x8000;
        obj->unk64 = 0x8000;
        obj->step++;
    }
    if (parent->unk6 != 0) {
        if (obj->unk16 == 0 && obj->unk7F == 3) {
            obj->unk60 = 0x8000;
            obj->unk64 = 0x8000;
            obj->unk64 += lbl_804ED380[obj->unk15] << 8;
            fn_800E9424(obj, lbl_80280CA8[obj->unk15]);
            fn_800E946C(obj, lbl_804ED378[obj->unk15]);
            if (obj->unk15 == 2) {
                fn_800E9AA0(obj, 0, 0);
            }
            obj->unk16++;
        }
        obj->flagsA |= 1;
        fn_800E9750(obj, 0xFFFF);
        if (obj->unk16 != 0 && obj->unk15 == 2) {
            fn_800E9C90(obj);
        }
    } else {
        obj->flagsA &= ~1;
        fn_800E9758(obj);
    }
}
