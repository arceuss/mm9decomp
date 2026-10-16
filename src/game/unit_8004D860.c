#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk8004D860 {
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
    /* 0x34 */ struct Unk8004D860* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0x6C - 0x68];
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ u8 pad70[0x74 - 0x70];
    /* 0x74 */ s32 unk74;
    /* 0x78 */ u8 pad78[0x88 - 0x78];
    /* 0x88 */ u8 unk88[0xAC - 0x88];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
} Unk8004D860;

extern Unk80280390Entry* lbl_80265138[];

extern u8 lbl_80265F78[];

void fn_800E946C(Unk8004D860* obj, u8 id);
void fn_8009996C(void* work, void* data);
void fn_800E9750(Unk8004D860* obj, u16 arg1);
s32 fn_800A39F0(s32 x, s32 y);
s32 fn_800A36F8(s32 x, s32 y);

void fn_8004D860(Unk8004D860* obj) {
    s32 d;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 2);
        obj->unk6C = -0x480;
        obj->unk74 = 0x40;
        fn_8009996C(obj->unk88, lbl_80265F78);
        obj->step++;
    case 1:
        fn_800E9750(obj, 0xFFFF);
        obj->unk64 += obj->unk6C;
        obj->unk6C += obj->unk74;
        d = fn_800A39F0(obj->unk60, obj->unk64 - 0x1D00);
        if (d > 0) {
            obj->unk64 += d;
            obj->unk6C = 0;
        }
        d = fn_800A36F8(obj->unk60, obj->unk64);
        if (d < 0) {
            obj->unk64 += d;
            obj->state = 0;
            obj->step = 0;
            obj->unk16 = 30;
        }
        break;
    }
}
