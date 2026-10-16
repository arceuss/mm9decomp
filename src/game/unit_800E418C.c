#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk800E418C {
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
    /* 0x34 */ struct Unk800E418CParent* parent;
    /* 0x38 */ u8 pad38[0x54 - 0x38];
    /* 0x54 */ u32 unk54_0 : 21;
    /* 0x54 */ u32 flipX : 1;
    /* 0x54 */ u32 unk54_22 : 10;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0x6C - 0x68];
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ u8 pad70[0x88 - 0x70];
    /* 0x88 */ u8 unk88;
    /* 0x89 */ u8 unk89;
    /* 0x8A */ u8 pad8A[0x90 - 0x8A];
    /* 0x90 */ s32 unk90;
    /* 0x94 */ u8 pad94[0xAC - 0x94];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
} Unk800E418C;


typedef struct Unk800E418CParent {
    /* 0x000 */ u8 pad0[0x5];
    /* 0x005 */ u8 unk5;
    /* 0x006 */ u8 pad6[0x2AC - 0x6];
    /* 0x2AC */ u8 unk2AC;
    /* 0x2AD */ u8 pad2AD;
    /* 0x2AE */ u8 unk2AE;
    /* 0x2AF */ u8 pad2AF[0x2B2 - 0x2AF];
    /* 0x2B2 */ u8 unk2B2;
} Unk800E418CParent;

extern u8 lbl_804ED3D8[8];

void fn_800E946C(Unk800E418C* obj, u8 id);
void fn_800D6184(Unk800E418C* obj);

static inline void SyncFlip(Unk800E418C* obj) {
    if (obj->flipX) {
        obj->flagsA |= 0x10;
    } else {
        obj->flagsA &= 0xEF;
    }
}

static inline void CheckLeave(Unk800E418C* obj) {
    if (obj->unk88 != obj->parent->unk5) {
        fn_800D6184(obj);
    }
}

void fn_800E418C(Unk800E418C* obj) {
    switch (obj->state) {
    case 0:
        fn_800E946C(obj, lbl_804ED3D8[obj->unk15 & 0xF]);
        if (obj->unk15 == 1 || obj->unk15 == 3) {
            obj->flipX = 1;
            SyncFlip(obj);
        }
        obj->unk88 = obj->parent->unk5;
        obj->unk6C = 0;
        obj->unk90 = obj->unk64;
        obj->state++;
        break;
    case 1:
        if ((u32)(obj->unk15 & 0xF) == 7) {
            if (obj->parent->unk2B2 > (((obj->unk15 >> 4) & 0xF) + 1) * 0x19 - 1) {
                fn_800E946C(obj, 1);
                obj->unk6C = -0x200;
                obj->state++;
            }
            CheckLeave(obj);
        }
        break;
    case 2:
        obj->unk64 += obj->unk6C;
        obj->unk6C += 0x40;
        if (obj->unk64 > obj->unk90) {
            fn_800E946C(obj, 2);
            obj->unk64 = obj->unk90;
            obj->state++;
        }
        CheckLeave(obj);
        break;
    case 3:
        if (obj->parent->unk2AE & 0x10) {
            fn_800E946C(obj, 0);
            obj->state++;
        }
        CheckLeave(obj);
        break;
    case 4:
        CheckLeave(obj);
        break;
    }
}
