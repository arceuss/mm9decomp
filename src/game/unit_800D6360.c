#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk800D6360 {
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
    /* 0x34 */ struct Unk800D6360Parent* parent;
    /* 0x38 */ u8 pad38[0x50 - 0x38];
    /* 0x50 */ u32 unk50_0 : 30;
    /* 0x50 */ u32 unk50_30 : 2;
    /* 0x54 */ u8 pad54[0x60 - 0x54];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0x7C - 0x68];
    /* 0x7C */ u8 unk7C;
    /* 0x7D */ u8 pad7D[0x88 - 0x7D];
    /* 0x88 */ u8 unk88;
    /* 0x89 */ u8 pad89[0xAC - 0x89];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
} Unk800D6360;


typedef struct Unk800D6360Parent {
    /* 0x0 */ u8 pad0[0x6];
    /* 0x6 */ s16 unk6;
} Unk800D6360Parent;

typedef struct Vec2i {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Vec2i;

extern u8 lbl_80280790[];
extern Vec2i lbl_80280700[];

void fn_800E946C(Unk800D6360* obj, u8 id);
void fn_800E9750(Unk800D6360* obj, u16 arg1);

void fn_800D6360(Unk800D6360* obj) {
    Unk800D6360Parent* parent = obj->parent;
    u8 id;

    if (obj->step == 0) {
        obj->unk50_30 = 1;
        obj->unk88 = 0xFF;
        obj->unk16 = 0;
        obj->step++;
    }
    obj->unk16 = (obj->unk16 + 1) % 16;
    if (obj->unk16 < 8) {
        obj->flagsA |= 1;
    } else {
        obj->flagsA &= ~1;
    }
    if (parent->unk6 < (s16)9) {
        id = 0x14;
    } else {
        id = 0;
    }
    if (id != obj->unk88) {
        fn_800E946C(obj, id);
        obj->unk88 = id;
    }
    obj->unk2F = lbl_80280790[obj->unk7C];
    fn_800E9750(obj, 0xFFFF);
    obj->unk60 = lbl_80280700[parent->unk6].x;
    obj->unk64 = lbl_80280700[parent->unk6].y;
}
