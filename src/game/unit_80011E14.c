#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk80011E14 {
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
    /* 0x34 */ struct Unk80011E14* parent;
    /* 0x38 */ u8 pad38[0x50 - 0x38];
    /* 0x50 */ u32 unk50;
    /* 0x54 */ u32 unk54;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0xAC - 0x68];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
    /* 0xCD */ u8 padCD[0xD8 - 0xCD];
    /* 0xD8 */ s32 unkD8;
    /* 0xDC */ s32 unkDC;
    /* 0xE0 */ u8 unkE0;
    /* 0xE1 */ u8 unkE1;
    /* 0xE2 */ u8 unkE2;
    /* 0xE3 */ u8 unkE3;
    /* 0xE4 */ u8 unkE4;
} Unk80011E14;

extern Unk80280390Entry* lbl_802638A0[];

typedef struct Unk803051D8 {
    /* 0x00 */ u8 pad0[0x3];
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 pad4[0x38 - 0x4];
} Unk803051D8;

extern Unk803051D8 lbl_803051D8;
extern const u8 lbl_804EE668[8];

void fn_800E9424(Unk80011E14* obj, u16 anim);
void fn_800E946C(Unk80011E14* obj, u8 id);
void fn_800E91F0(Unk80011E14* obj, void* arg1, s32 arg2);
void fn_80011E10(void*);
void fn_80062CD0(Unk80011E14* obj, s32 x, s32 y, s32 arg3, s32 arg4);
void fn_80011F74(Unk80011E14* obj);

void fn_80011E14(Unk80011E14* obj) {
    u8 zero = 0;

    obj->unk18 = lbl_802638A0[obj->unk9]->unk4;
    obj->unk10 = 1;
    obj->step = zero;
    obj->unk13 = zero;
    obj->state = lbl_804EE668[obj->unk14];
    obj->flagsA |= 3;
    fn_800E9424(obj, 0x34);
    fn_800E946C(obj, 0);
    fn_800E91F0(obj, NULL, 0xF);
    obj->unkAC = fn_80011E10;
    obj->unkD8 = obj->unk60;
    obj->unkDC = obj->unk64;
    obj->unkE0 = 0xFF;
    obj->unkE1 = zero;
    obj->unkE2 = zero;
    obj->unkE3 = zero;
    obj->unkE4 = zero;
    fn_80062CD0(obj, obj->unk60 + (((obj->flagsA >> 3) & 2) - 1) * 0x5000, obj->unk64 - 0x800, 0, 0);
    fn_80062CD0(obj, obj->unk60, obj->unk64, 4, 0);
    fn_80062CD0(obj, obj->unk60, obj->unk64, 4, 1);
    obj->unk54 &= ~0x200;
    obj->unk50 |= 3;
    lbl_803051D8.unk3 |= 8;
    fn_80011F74(obj);
}
