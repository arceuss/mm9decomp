#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk800D0564 {
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
    /* 0x34 */ struct Unk800D0564* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0xAC - 0x68];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ u16 unkC8;
} Unk800D0564;

extern Unk80280390Entry* lbl_80280390[];

extern void* lbl_804EE984;

void fn_800D066C(Unk800D0564* obj);
BOOL fn_800B6010(void* work, Unk800D0564* obj);
void fn_800B6484(void* work, s32 y, s32 arg2, s32 arg3);
void fn_800B64F8(void* work, u16 arg1);
void fn_800E946C(Unk800D0564* obj, u8 id);
void fn_800E9750(Unk800D0564* obj, u16 arg1);

void fn_800D0564(Unk800D0564* obj) {
    switch (obj->step) {
    case 0:
        obj->unkC8 = 0;
        obj->step++;
    case 1:
        fn_800D066C(obj);
        if (fn_800B6010(lbl_804EE984, obj)) {
            fn_800B6484(lbl_804EE984, obj->unk64 + 0x800, 0x8FF, 0);
            obj->unkC8 += 0x400;
            fn_800B64F8(lbl_804EE984, obj->unkC8);
        } else {
            obj->unkC8 = 0;
        }
        obj->unk16 = (u8)(obj->unk16 + 1) % 32;
        fn_800E946C(obj, obj->unk16 / 11);
        fn_800E9750(obj, 0xFFFF);
        break;
    }
}
