#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk80043414 {
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
    /* 0x34 */ struct Unk80043414* parent;
    /* 0x38 */ u8 pad38[0x54 - 0x38];
    /* 0x54 */ u32 unk54_0 : 21;
    /* 0x54 */ u32 flipX : 1;
    /* 0x54 */ u32 unk54_22 : 10;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0x84 - 0x68];
    /* 0x84 */ s32 unk84;
    /* 0x88 */ u8 unk88[0xAC - 0x88];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
    /* 0xCD */ u8 padCD[0xD0 - 0xCD];
    /* 0xD0 */ s16 unkD0;
} Unk80043414;


extern Unk80043414* lbl_804EE984;
extern u8 lbl_804ECA4C[4];
extern void* lbl_804ECA50[2];

void fn_800E946C(Unk80043414* obj, u8 id);
void fn_8009996C(void* sprite, void* anim);
void fn_800E9750(Unk80043414* obj, u16 arg1);

static inline void Face(Unk80043414* obj, s32 dx) {
    u8 face = dx > 0;

    if (face) {
        obj->flagsA |= 0x10;
    } else {
        obj->flagsA &= 0xEF;
    }
    obj->flipX = face;
    obj->state = 1;
    obj->step = 0;
}

void fn_80043414(Unk80043414* obj) {
    s32 timer;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, lbl_804ECA4C[obj->unk14]);
        fn_8009996C(obj->unk88, lbl_804ECA50[obj->unk14]);
        obj->unk16 = 0x40;
        obj->step++;
    case 1:
        timer = obj->unk16;
        if (timer > 0) {
            obj->unk16 = --timer;
        }
        if (timer == 0) {
            if ((u32)(lbl_804EE984->unk60 - obj->unk60 + 0x4000) < 0x8000) {
                if (obj->unk14 == 1) {
                    if ((u32)(lbl_804EE984->unk64 - obj->unk64 + 0x4000) < 0x8000) {
                        Face(obj, lbl_804EE984->unk60 - obj->unk60);
                    }
                } else {
                    Face(obj, lbl_804EE984->unk60 - obj->unk60);
                }
            }
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    }
}
