#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk800227CC {
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
    /* 0x34 */ struct Unk800227CC* parent;
    /* 0x38 */ struct Unk800227CC* child;
    /* 0x3C */ u8 pad3C[0x60 - 0x3C];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0xAC - 0x68];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
    /* 0xCD */ u8 padCD[0xD8 - 0xCD];
    /* 0xD8 */ u8 unkD8;
    /* 0xD9 */ u8 unkD9;
    /* 0xDA */ u8 unkDA;
    /* 0xDB */ u8 padDB;
    /* 0xDC */ s32 unkDC;
    /* 0xE0 */ s32 unkE0;
} Unk800227CC;

void fn_800E9750(Unk800227CC* obj, u16 arg1);

void fn_800227CC(Unk800227CC* obj) {
    Unk800227CC* other;

    switch (obj->step) {
    case 0:
        obj->unkD9 = 0;
        obj->unk16 = 0x3C;
        obj->step++;
    case 1:
        if (obj->unk16 == 0) {
            obj->step++;
        } else {
            obj->unk16--;
        }
        break;
    case 2:
        obj->step++;
    case 3:
        if (obj->unkD9 == 0xC) {
            if (obj->unk14 == 0) {
                other = obj->child;
                if (other->unkD9 == 0xC) {
                    obj->unkDC = obj->unk60;
                    obj->unkE0 = obj->unk64;
                    obj->unk60 = other->unk60;
                    obj->unk64 = other->unk64;
                    obj->unkD8 = 1;
                    if (obj->unkDA == 0) {
                        obj->unkDA = 1;
                    } else {
                        obj->unkDA = 0;
                    }
                    obj->state = 3;
                    obj->step = 0;
                }
            } else {
                other = obj->parent;
                obj->unk60 = other->unkDC;
                obj->unk64 = other->unkE0;
                obj->unkD8 = 0;
                if (obj->unkDA == 0) {
                    obj->unkDA = 1;
                } else {
                    obj->unkDA = 0;
                }
                obj->state = 3;
                obj->step = 0;
            }
        }
        break;
    }
    fn_800E9750(obj, 0xFFFF);
}
