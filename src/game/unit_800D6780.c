#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk800D6780 {
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
    /* 0x34 */ struct Unk800D6780Parent* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0xAC - 0x68];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
} Unk800D6780;

extern Unk80280390Entry* lbl_802819B0[];

typedef struct Unk800D6780Parent {
    /* 0x0000 */ u8 pad0[0x227D];
    /* 0x227D */ u8 unk227D;
} Unk800D6780Parent;

extern s32 lbl_8036CF50[0xEFE0 / 4];
extern u8 lbl_802807D8[][6];

void fn_800E946C(Unk800D6780* obj, u8 id);
void fn_800E9750(Unk800D6780* obj, u16 arg1);

void fn_800D6780(Unk800D6780* obj) {
    Unk800D6780Parent* parent = obj->parent;
    u8 id;

    if (obj->step == 0) {
        if (parent->unk227D == 1) {
            id = lbl_802807D8[0][lbl_8036CF50[0]];
        } else if (parent->unk227D == 2) {
            id = lbl_802807D8[1][lbl_8036CF50[0]];
        } else {
            return;
        }
        fn_800E946C(obj, id);
        obj->flagsA |= 1;
        obj->unk60 = 0x8000;
        obj->unk64 = 0x8000;
        obj->step++;
    }
    fn_800E9750(obj, 0xFFFF);
}
