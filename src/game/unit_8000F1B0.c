#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk8000F1B0 {
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
    /* 0x34 */ struct Unk8000F1B0* parent;
    /* 0x38 */ u8 pad38[0x50 - 0x38];
    /* 0x50 */ u32 unk50;
    /* 0x54 */ u32 unk54;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0x74 - 0x68];
    /* 0x74 */ s32 unk74;
    /* 0x78 */ u8 pad78[0xAC - 0x78];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
    /* 0xCD */ u8 padCD[0xD8 - 0xCD];
    /* 0xD8 */ u8 unkD8;
    /* 0xD9 */ u8 unkD9;
    /* 0xDA */ u8 unkDA;
} Unk8000F1B0;

extern Unk80280390Entry* lbl_802638A0[];

extern const u8 lbl_804EC6B0[4];
extern u8 lbl_804EC6A8[8];
extern void (*lbl_80261E68[])(Unk8000F1B0* obj);
extern void (*lbl_80261E84[])(Unk8000F1B0* obj);

void fn_800E9424(Unk8000F1B0* obj, u16 anim);
void fn_800E91F0(Unk8000F1B0* obj, void* arg1, s32 arg2);
void fn_8000F19C(void*);
void fn_8000F134(void* arg0);
void fn_800C75D0(void);

void fn_8000F1B0(Unk8000F1B0* obj) {
    obj->unk18 = lbl_802638A0[obj->unk9]->unk4;
    obj->unk10 = 1;
    obj->step = 0;
    obj->unk13 = 0;
    obj->state = lbl_804EC6B0[obj->unk14];
    obj->flagsA |= 3;
    fn_800E9424(obj, 0x2E);
    fn_800E91F0(obj, NULL, 0);
    obj->unkAC = fn_8000F19C;
    obj->unk64 = obj->unk64 / 0xE000 * 0xE000 + 0x6800;
    if (obj->unk14 == 3) {
        obj->unk74 = obj->unk64;
        obj->unk64 -= 0x1400;
    }
    obj->unkD8 = 0;
    obj->unkD9 = 0;
    obj->unkDA = 0;
    obj->unk54 &= ~0x200;
    obj->unk50 |= 3;
    fn_8000F134(lbl_804EC6A8);
    if (obj->state != 0 && obj->state != 2 && obj->state != 4) {
        fn_800C75D0();
    }
    lbl_80261E68[obj->state](obj);
    lbl_80261E84[obj->state](obj);
}
