#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk8001A530 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 flagsB;
    /* 0x0C */ u8 unkC;
    /* 0x0D */ u8 padD[0x10 - 0xD];
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
    /* 0x34 */ struct Unk8001A530* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
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
} Unk8001A530;

extern Unk80280390Entry* lbl_802638A0[];

extern const u8 lbl_804EC7A0[4];
extern u8 lbl_80262AE0[];

void fn_800E9424(Unk8001A530* obj, s32 arg1);
void fn_800E9AA0(Unk8001A530* obj, s32 arg1, s32 arg2);
void fn_800E91F0(Unk8001A530* obj, s32 arg1, s32 arg2);
void fn_8000F134(void* arg0);
void fn_800C7594(s32 arg0);
void fn_8001A4B8(void*);
void fn_8001A638(Unk8001A530* obj);

void fn_8001A530(Unk8001A530* obj) {
    obj->unk18 = lbl_802638A0[obj->unk9]->unk4;
    obj->unk10 = 1;
    obj->step = 0;
    obj->unk13 = 0;
    obj->state = lbl_804EC7A0[obj->unk14];
    obj->flagsA |= 3;
    fn_800E9424(obj, 0x3F);
    if (obj->unk14 == 0) {
        fn_800E9AA0(obj, 0, 0);
        fn_800E91F0(obj, 0, 0);
        fn_8000F134(lbl_80262AE0);
        obj->unkD8 = 0xFF;
        obj->unkD9 = 0;
        obj->unkDA = 0xFF;
        fn_800C7594(9);
    } else {
        fn_800E91F0(obj, 0, 1);
        obj->unkC |= 0x10;
    }
    obj->unkAC = fn_8001A4B8;
    fn_8001A638(obj);
}
