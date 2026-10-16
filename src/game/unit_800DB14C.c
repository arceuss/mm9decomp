#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk800DB14C {
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
    /* 0x34 */ struct Unk800DB14CParent* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0x88 - 0x68];
    /* 0x88 */ u8 unk88;
    /* 0x89 */ u8 unk89;
    /* 0x8A */ u8 pad8A[0xAC - 0x8A];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
} Unk800DB14C;

extern Unk80280390Entry* lbl_802819B0[];

typedef struct Unk800DB14CParent {
    /* 0x000 */ u8 pad0[0x2AC];
    /* 0x2AC */ u8 unk2AC;
    /* 0x2AD */ u8 unk2AD;
} Unk800DB14CParent;

void fn_8003C6E4(s32* pos, s32 arg1, s32 arg2);
void fn_800E946C(Unk800DB14C* obj, u8 id);

void fn_800DB14C(Unk800DB14C* obj) {
    switch (obj->state) {
    case 0:
        if (obj->unk15 == 2) {
            obj->unk88 = 12;
            fn_8003C6E4(&obj->unk60, 2, obj->parent->unk2AC);
        } else {
            obj->unk88 = 16;
            fn_8003C6E4(&obj->unk60, 3, 0);
        }
        obj->unk89 = obj->parent->unk2AC;
        fn_800E946C(obj, obj->unk88);
        obj->state++;
        break;
    case 1:
        if (obj->unk15 != obj->parent->unk2AD) {
            obj->flagsA &= ~1;
        } else {
            obj->flagsA |= 1;
            fn_8003C6E4(&obj->unk60, obj->parent->unk2AD, obj->parent->unk2AC);
        }
        break;
    }
}
