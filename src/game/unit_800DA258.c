#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk800DA258 {
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
    /* 0x34 */ struct Unk800DA258Parent* parent;
    /* 0x38 */ u8 pad38[0x54 - 0x38];
    /* 0x54 */ u32 unk54_0 : 21;
    /* 0x54 */ u32 flipX : 1;
    /* 0x54 */ u32 unk54_22 : 10;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0x8B - 0x68];
    /* 0x8B */ u8 unk8B;
    /* 0x8C */ u8 pad8C[0x8E - 0x8C];
    /* 0x8E */ u8 unk8E;
    /* 0x8F */ u8 unk8F;
    /* 0x90 */ u8 pad90[0xAC - 0x90];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
} Unk800DA258;

extern Unk80280390Entry* lbl_802819B0[];

typedef struct Unk800DA258Parent {
    /* 0x000 */ u8 pad0[0x26E];
    /* 0x26E */ s8 unk26E;
    /* 0x26F */ s8 unk26F;
    /* 0x270 */ s8 unk270;
    /* 0x271 */ s8 unk271;
    /* 0x272 */ s8 unk272;
    /* 0x273 */ s8 unk273;
    /* 0x274 */ u8 pad274[0x288 - 0x274];
    /* 0x288 */ u8 unk288;
} Unk800DA258Parent;

void fn_800E946C(Unk800DA258* obj, u8 id);
void fn_800E9750(Unk800DA258* obj, u16 arg1);

static inline void Blink(Unk800DA258* obj, s8 on) {
    if (on) {
        if (obj->unk17 >> 4) {
            obj->flagsA &= ~1;
        } else {
            obj->flagsA |= 1;
        }
    } else {
        obj->flagsA &= ~1;
    }
}

void fn_800DA258(Unk800DA258* obj) {
    Unk800DA258Parent* parent;

    parent = obj->parent;
    if (parent->unk288 == 1) {
        obj->unk18 = lbl_802819B0[obj->unk9]->unk8;
        obj->unk10 = 2;
        obj->state = 0;
        obj->step = 0;
        obj->unk13 = 0;
        return;
    }
    if ((u8)(obj->unk15 + 0xFF) <= 1) {
        if (obj->unk8F == 0) {
            if (obj->unk8E != parent->unk271) {
                obj->unk8E = parent->unk271;
                obj->flagsA |= 1;
                obj->unk17 = 0;
            } else {
                obj->unk17 = (obj->unk17 + 1) & 0x1F;
                if (obj->unk15 == 1) {
                    Blink(obj, parent->unk26F);
                } else if (obj->unk15 == 2) {
                    Blink(obj, parent->unk270);
                }
            }
        }
    } else if (obj->unk15 == 3 && obj->unk8F == 0) {
        if (parent->unk273 == 0) {
            if (obj->unk8B != parent->unk273) {
                obj->unk8B = parent->unk273;
                fn_800E946C(obj, 3);
            }
            obj->unk60 = 0x6400;
            obj->unk64 = (parent->unk26E << 12) + 0x4400;
        } else {
            if (obj->unk8B != parent->unk273) {
                obj->unk8B = parent->unk273;
                fn_800E946C(obj, 0xA);
            }
            obj->unk60 = 0xDD00;
            obj->unk64 = 0xBC00;
        }
    }
    fn_800E9750(obj, 0xFFFF);
}
