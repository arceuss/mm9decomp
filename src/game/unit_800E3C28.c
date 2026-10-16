#include "types.h"
#include "game/sound.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk800E3C28 {
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
    /* 0x34 */ struct Unk800E3C28Parent* parent;
    /* 0x38 */ u8 pad38[0x54 - 0x38];
    /* 0x54 */ u32 unk54_0 : 21;
    /* 0x54 */ u32 flipX : 1;
    /* 0x54 */ u32 unk54_22 : 10;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0x7F - 0x68];
    /* 0x7F */ u8 unk7F;
    /* 0x80 */ u8 pad80[0xAC - 0x80];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
} Unk800E3C28;

extern Unk80280390Entry* lbl_802819B0[];

typedef struct Unk800E3C28Parent {
    /* 0x0000 */ u8 pad0[0x5];
    /* 0x0005 */ u8 unk5;
    /* 0x0FF5 */ u8 unkFF5;
} Unk800E3C28Parent;

typedef struct Vec2i {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Vec2i;

extern Vec2i lbl_802810E0[][18];

void fn_800E946C(Unk800E3C28* obj, u8 id);
void fn_800E9750(Unk800E3C28* obj, u16 arg1);

static inline void SyncFlip(Unk800E3C28* obj) {
    if (obj->flipX) {
        obj->flagsA |= 0x10;
    } else {
        obj->flagsA &= 0xEF;
    }
}

extern u8 lbl_804ED3CC[8];
extern u8 lbl_804ED3D4[4];

void fn_800D5234(s32 id);

void fn_800E3C28(Unk800E3C28* obj) {
    Unk800E3C28Parent* parent = obj->parent;
    u8 delay;

    switch (obj->step) {
    case 0:
        if (obj->unk15 == 0) {
            obj->unk16 = 8;
            obj->unk17 = 0;
        } else if (obj->unk15 != 1) {
            delay = lbl_804ED3D4[obj->unk15 - 2];
            obj->flagsA &= ~1;
            obj->unk16 = 0;
            obj->unk17 = delay;
            obj->unk60 = 0x8800;
            obj->unk64 = 0xA000;
        } else {
            fn_800D5234(SE_TELEPHONE);
            obj->unk16 = 0;
        }
        obj->step++;
    case 1:
        if (obj->unk15 == 0) {
            if (obj->unk16 == 0) {
                obj->unk16 = 8;
                if (obj->unk17 == 0) {
                    obj->unk17++;
                    obj->flagsA |= 1;
                } else {
                    obj->unk17--;
                    obj->flagsA &= ~1;
                }
            } else {
                obj->unk16--;
            }
        } else if (obj->unk15 != 1) {
            if (obj->unk7F == 3) {
                obj->flagsA &= ~1;
            }
            if (obj->unk17 == 0) {
                if (obj->unk16 == 0) {
                    obj->unk16 = 0x70;
                    obj->flagsA |= 1;
                    fn_800E946C(obj, obj->unk15);
                    fn_800D5234(SE_EXPLOSION);
                } else {
                    obj->unk16--;
                }
            } else {
                obj->unk17--;
            }
        } else if (obj->unk16 == 0) {
            fn_800D5234(SE_TELEPHONE);
            obj->unk16 = 0x3C;
        } else {
            obj->unk16--;
        }
        if (parent->unk5 >= lbl_804ED3CC[obj->unk15] && parent->unk5 < 0x32) {
            obj->flagsA &= ~1;
            obj->flagsA &= 0xFD;
            obj->unk18 = lbl_802819B0[obj->unk9]->unkC;
            obj->unk10 = 3;
            obj->state = 0;
            obj->step = 0;
            obj->unk13 = 0;
            return;
        }
        break;
    }
    fn_800E9750(obj, 0xFFFF);
}
