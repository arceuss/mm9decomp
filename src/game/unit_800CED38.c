#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk800CED38 {
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
    /* 0x34 */ struct Unk800CED38* parent;
    /* 0x38 */ u8 pad38[0x54 - 0x38];
    /* 0x54 */ u32 flags54_hi : 22;
    /* 0x54 */ u32 flags54_b9 : 1;
    /* 0x54 */ u32 flags54_lo : 9;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0xAC - 0x68];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ u8 unkC8;
    /* 0xC9 */ u8 unkC9;
    /* 0xCA */ u8 unkCA;
} Unk800CED38;

extern Unk80280390Entry* lbl_80280390[];

extern u8 lbl_8027FB20[];
extern void (*lbl_804ED050[2])(Unk800CED38* obj);

void fn_800E91F0(Unk800CED38* obj, void* data, s32 arg2);
void fn_800CED0C(void*);

void fn_800CED38(Unk800CED38* obj) {
    obj->unk18 = lbl_80280390[obj->unk9]->unk4;
    obj->unk10 = 1;
    obj->step = 0;
    obj->unk13 = 0;
    obj->state = 0;
    obj->flagsA |= 2;
    fn_800E91F0(obj, lbl_8027FB20, 1);
    obj->unkAC = fn_800CED0C;
    obj->parent = NULL;
    obj->flags54_b9 = 0;
    obj->unkC9 = 1;
    obj->unkCA = 0;
    lbl_804ED050[obj->state](obj);
}
