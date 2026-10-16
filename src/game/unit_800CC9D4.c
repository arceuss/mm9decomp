#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk800CC9D4 {
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
    /* 0x34 */ struct Unk800CC9D4* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ u8 pad6C[0xAC - 0x6C];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ u16 padC8;
    /* 0xCA */ u16 unkCA;
    /* 0xCC */ struct Unk800CC9D4* unkCC;
    /* 0xD0 */ u8 padD0[0xD4 - 0xD0];
    /* 0xD4 */ s32 unkD4;
} Unk800CC9D4;

extern Unk80280390Entry* lbl_80280390[];

extern const s16 lbl_802537E8[256];

void fn_800E9244(Unk800CC9D4* obj);

void fn_800CC9D4(Unk800CC9D4* obj) {
    Unk800CC9D4* base;
    s32 a;

    if (obj->unk14 == 0) {
        return;
    }
    base = obj->unkCC;
    if (base == NULL) {
        return;
    }
    if (base->unk10 >= 3) {
        obj->flagsA &= ~1;
        obj->flagsA &= 0xFD;
        fn_800E9244(obj);
        obj->unk18 = lbl_80280390[obj->unk9]->unkC;
        obj->unk10 = 3;
        obj->state = 0;
        obj->step = 0;
        obj->unk13 = 0;
        return;
    }
    a = obj->unkCA + obj->unk68;
    obj->unkCA = a;
    obj->unk60 = base->unk60;
    obj->unk60 += lbl_802537E8[(u8)(((u16)a >> 8) + 0x40)] * __abs(obj->unkD4 - base->unk64) / 256;
    obj->unk64 = base->unk64;
    obj->unk64 += lbl_802537E8[(u8)(a >> 8)] * __abs(obj->unkD4 - base->unk64) / 256;
}
