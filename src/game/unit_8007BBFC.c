#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk8007BBFC {
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
    /* 0x34 */ struct Unk8007BBFC* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0xAC - 0x68];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
    /* 0xCD */ u8 padCD[0xD0 - 0xCD];
    /* 0xD0 */ u8 unkD0;
} Unk8007BBFC;

extern Unk80280390Entry* lbl_80270168[18];

typedef struct Unk803051D8 {
    /* 0x00 */ u8 pad0[0x2];
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 pad3[0x38 - 0x3];
} Unk803051D8;

extern Unk803051D8 lbl_803051D8;
extern u8 lbl_80270078[];
extern void (*lbl_8027006C[])(Unk8007BBFC* obj);

void fn_800E9424(Unk8007BBFC* obj, s32 arg1);
void fn_800E91F0(Unk8007BBFC* obj, void* arg1, s32 arg2);
void fn_8007BDF4(void*);
void fn_800E9244(Unk8007BBFC* obj);
u8 fn_8007BE30(Unk8007BBFC* obj);

void fn_8007BBFC(Unk8007BBFC* obj) {
    fn_800E9424(obj, 0x31);
    obj->flagsA |= 1;
    fn_800E91F0(obj, lbl_80270078, 1);
    obj->unkAC = fn_8007BDF4;
    obj->unk18 = lbl_80270168[obj->unk9]->unk4;
    obj->unk10 = 1;
    obj->unk13 = 0;
    obj->state = 0;
    obj->step = 0;
    obj->unkD0 = 0;
    if (lbl_803051D8.unk2 & 0x20) {
        obj->flagsA &= ~1;
        obj->flagsA &= 0xFD;
        fn_800E9244(obj);
        obj->unk18 = lbl_80270168[obj->unk9]->unkC;
        obj->unk10 = 3;
        obj->state = 0;
        obj->step = 0;
        obj->unk13 = 0;
        return;
    }
    if (!fn_8007BE30(obj)) {
        lbl_8027006C[obj->state](obj);
    }
}
