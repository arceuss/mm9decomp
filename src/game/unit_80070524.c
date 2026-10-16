#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk80070524 {
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
    /* 0x34 */ struct Unk80070524* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0x7D - 0x68];
    /* 0x7D */ u8 unk7D;
    /* 0x7E */ u8 pad7E;
    /* 0x7F */ u8 unk7F;
    /* 0x80 */ u8 pad80[0x88 - 0x80];
    /* 0x88 */ u8 unk88[0xAC - 0x88];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
    /* 0xCD */ u8 padCD[0xD0 - 0xCD];
    /* 0xD0 */ s16 unkD0;
} Unk80070524;

extern Unk80280390Entry* lbl_80265138[];

extern void* lbl_802689D8[4];
extern s16 lbl_804ECCA0[4];

void fn_800E946C(Unk80070524* obj, u8 id);
void fn_8009996C(void* work, void* data);
void fn_800E9750(Unk80070524* obj, u16 arg1);

void fn_80070524(Unk80070524* obj) {
    u32 frame;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 4);
        fn_8009996C(obj->unk88, lbl_802689D8[0]);
        obj->step++;
    case 1:
        fn_800E9750(obj, 0xFFFF);
        if (obj->unk7F == 3) {
            obj->state = 0;
            obj->step = 0;
        }
        frame = obj->unk7D;
        fn_8009996C(obj->unk88, lbl_802689D8[frame]);
        obj->unkD0 = lbl_804ECCA0[frame];
        break;
    }
}
