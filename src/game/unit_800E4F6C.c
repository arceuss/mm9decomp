#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk800E4F6C {
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
    /* 0x30 */ u8 pad30[0x32 - 0x30];
    /* 0x32 */ u16 unk32;
    /* 0x34 */ struct Unk800E4F6C* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ u8 pad6C[0xAC - 0x6C];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
} Unk800E4F6C;

extern Unk80280390Entry* lbl_802819B0[];

extern u8 lbl_80281990[];
extern u8 lbl_802819A0[];

void fn_800E9424(Unk800E4F6C* obj, s32 id);
void fn_800E9474(Unk800E4F6C* obj, u8 id);
void fn_800E9750(Unk800E4F6C* obj, u16 arg1);

void fn_800E4F6C(Unk800E4F6C* obj) {
    s32 limit;

    switch (obj->step) {
    case 0:
        fn_800E9424(obj, 0x5D);
        fn_800E9474(obj, lbl_80281990[obj->unk15]);
        obj->unk60 = 0xCC00;
        obj->unk64 = 0x6C00;
        obj->unk68 = -0x400;
        obj->step++;
    case 1:
        obj->unk60 += obj->unk68 * obj->unk32 / 256;
        limit = lbl_802819A0[obj->unk15] << 8;
        if (obj->unk60 < limit) {
            obj->unk60 = limit;
            obj->step++;
        }
        break;
    }
    fn_800E9750(obj, obj->unk32);
}
