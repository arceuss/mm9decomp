#include "types.h"

typedef struct Vec2i {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Vec2i;

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk800619E8 {
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
    /* 0x34 */ struct Unk800619E8* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0xAC - 0x68];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
    /* 0xCD */ u8 padCD[0xD8 - 0xCD];
    /* 0xD8 */ u8 unkD8;
} Unk800619E8;


extern s32 lbl_802678AC[3];
extern s32 lbl_802678B8[3];

void fn_80042D30(Unk800619E8* obj);
void fn_800E946C(Unk800619E8* obj, u8 id);
void fn_800E9244(Unk800619E8* obj);
void fn_800E9750(Unk800619E8* obj, u16 arg1);
void* fn_80040AD0(u8 kind, Vec2i* pos, s32 flipX, s32 flipY);
void fn_800D5234(s32 id);

void fn_800619E8(Unk800619E8* obj) {
    Unk800619E8* parent = obj->parent;
    Vec2i pos;

    if (parent->unk10 == 4) {
        fn_80042D30(obj);
        return;
    }
    obj->unk64 = parent->unk64 + 0x1000;
    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 4);
        fn_800E9244(obj);
        parent->unkD8 = 3;
        obj->unk16 = 0;
        obj->unk17 = 0;
        obj->step++;
    case 1:
        fn_800E9750(obj, 0xFFFF);
        if (obj->unk17 != 3) {
            if (obj->unk16 == 0) {
                pos.x = obj->unk60 - lbl_802678AC[obj->unk17];
                pos.y = obj->unk64 + lbl_802678B8[obj->unk17];
                fn_80040AD0(3, &pos, 0, 0);
                fn_800D5234(0x13);
                obj->unk16 = 0x10;
                obj->unk17++;
            } else {
                obj->unk16--;
            }
        }
        break;
    }
}
