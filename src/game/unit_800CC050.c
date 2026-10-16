#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
} Unk80280390Entry;

typedef struct Unk800CC050 {
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
    /* 0x15 */ u8 pad15[0x18 - 0x15];
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
    /* 0x34 */ struct Unk800CC050* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ u8 pad6C[0xAC - 0x6C];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ u8 unkC8;
    /* 0xC9 */ u8 padC9;
    /* 0xCA */ s16 unkCA;
    /* 0xCC */ struct Unk800CC050* unkCC;
    /* 0xD0 */ struct Unk800CC050* unkD0;
} Unk800CC050;

extern Unk80280390Entry* lbl_80280390[];

extern void* lbl_804EE908;

Unk800CC050* fn_800E8C44(void* pool);

Unk800CC050* fn_800CC050(Unk800CC050* parent, s32 dy, u8 arg2, u8 arg3) {
    Unk800CC050* obj = fn_800E8C44(lbl_804EE908);

    if (obj != NULL) {
        obj->unk2E = 0x10;
        obj->unk9 = 5;
        obj->unk18 = lbl_80280390[5]->unk0;
        obj->unk2A = 0;
        obj->unk2C = 0;
        obj->unk2F = 0;
        obj->flagsB |= 0x20;
        obj->unk21 = obj->unk20;
        obj->parent = parent;
        obj->unk60 = parent->unk60;
        obj->unk64 = parent->unk64 + dy;
        obj->unk14 = arg2;
        obj->unkC8 = arg3;
        obj->unk68 = 0;
        obj->unkCA = 0x4000;
    }
    return obj;
}
