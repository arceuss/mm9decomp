#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk800D3598 {
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
    /* 0x34 */ struct Unk800D3598* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0xA0 - 0x68];
    /* 0xA0 */ u32 flagsA0;
    /* 0xA4 */ u8 padA4[0xAC - 0xA4];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
} Unk800D3598;

extern Unk80280390Entry* lbl_80280390[];

extern u8 lbl_804ED2F4[8];
extern u8 lbl_802802E8[];

void fn_800E946C(Unk800D3598* obj, u8 id);
void fn_800E91F0(Unk800D3598* obj, void* data, s32 arg2);
void fn_800E9750(Unk800D3598* obj, u16 arg1);
void fn_800E9244(Unk800D3598* obj);
void fn_80040AD0(s32 arg0, s32* pos, s32 arg2, s32 arg3);
void fn_800D2FF4(void*);

void fn_800D3598(Unk800D3598* obj) {
    Unk800D3598* parent = obj->parent;
    s32 pos[2];

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, lbl_804ED2F4[obj->unk15]);
        if (obj->unk15 == 0) {
            fn_800E91F0(obj, lbl_802802E8, 1);
            obj->unkAC = fn_800D2FF4;
        }
        obj->step++;
    case 1:
        fn_800E9750(obj, 0xFFFF);
        obj->unk64 = parent->unk64;
        if (obj->unk15 == 0 && (obj->flagsA0 & 1)) {
            pos[0] = obj->unk60;
            pos[1] = obj->unk64 + 0x800;
            fn_80040AD0(2, pos, 0, 0);
            obj->flagsA &= ~1;
            obj->flagsA &= 0xFD;
            fn_800E9244(obj);
            obj->unk18 = lbl_80280390[obj->unk9]->unkC;
            obj->unk10 = 3;
            obj->state = 0;
            obj->step = 0;
            obj->unk13 = 0;
        }
        break;
    }
}
