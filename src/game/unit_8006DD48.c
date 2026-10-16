#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk8006DD48 {
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
    /* 0x34 */ struct Unk8006DD48* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0xAC - 0x68];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
    /* 0xCD */ u8 padCD[0xD2 - 0xCD];
    /* 0xD2 */ u8 unkD2;
} Unk8006DD48;


extern u8 lbl_804ECC80[4];
extern u8 lbl_804ECC84[4];
extern void (*lbl_802686B8[])(Unk8006DD48* obj);
extern void (*lbl_802686D0[])(Unk8006DD48* obj);

void fn_80042CF8(Unk8006DD48* obj, s32 arg1);
void fn_800E9424(Unk8006DD48* obj, s32 arg1);
void fn_800E91F0(Unk8006DD48* obj, void* arg1, s32 arg2);
void fn_8006DC74(void*);
u8 fn_8006EAC4(Unk8006DD48* obj);

void fn_8006DD48(Unk8006DD48* obj) {
    fn_80042CF8(obj, 1);
    obj->state = lbl_804ECC80[obj->unk14];
    obj->flagsA |= 2;
    if (obj->unk14 == 0) {
        obj->flagsA &= ~1;
        obj->unkD2 = obj->unk15;
    } else {
        obj->flagsA |= 1;
        obj->unk2F = obj->unkD2;
        fn_800E9424(obj, 0x61);
        fn_800E91F0(obj, NULL, lbl_804ECC84[obj->unk14]);
        obj->unkAC = fn_8006DC74;
    }
    if (obj->unk14 == 0 || !fn_8006EAC4(obj)) {
        lbl_802686B8[obj->state](obj);
        lbl_802686D0[obj->state](obj);
    }
}
