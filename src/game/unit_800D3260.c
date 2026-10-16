#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk800D3260 {
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
    /* 0x34 */ struct Unk800D3260* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0xAC - 0x68];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ u8 unkC8;
    /* 0xC9 */ u8 padC9;
    /* 0xCA */ u16 unkCA;
} Unk800D3260;

extern Unk80280390Entry* lbl_80280390[];

typedef struct Unk800D3260Patch {
    /* 0x0 */ u16 w;
    /* 0x2 */ u16 h;
    /* 0x4 */ u16 tile;
} Unk800D3260Patch;

extern u8 lbl_802802E8[];

s16 fn_8009E850(s32 x, s32 y);
void fn_8009EF24(s32 tx, s32 ty, Unk800D3260Patch* patch);
void fn_800E9244(Unk800D3260* obj);
void fn_800E91F0(Unk800D3260* obj, void* data, s32 arg2);
void fn_80040AD0(s32 arg0, s32* pos, s32 arg2, s32 arg3);
void fn_800D2FF4(void*);

void fn_800D3260(Unk800D3260* obj) {
    Unk800D3260Patch patch;
    s32 pos[2];
    s32 x;
    s32 y;

    switch (obj->step) {
    case 0:
        if (fn_8009E850(obj->unk60, obj->unk64) == 0x31) {
            obj->flagsA &= ~1;
            obj->flagsA &= 0xFD;
            fn_800E9244(obj);
            obj->unk18 = lbl_80280390[obj->unk9]->unkC;
            obj->unk10 = 3;
            obj->state = 0;
            obj->step = 0;
            obj->unk13 = 0;
            break;
        }
        x = obj->unk60;
        y = obj->unk64;
        patch.w = 1;
        patch.h = 1;
        patch.tile = 0x150;
        obj->unkCA = fn_8009E850(x, y);
        fn_8009EF24(x >> 12, y >> 12, &patch);
        obj->flagsA &= ~1;
        fn_800E91F0(obj, lbl_802802E8, 1);
        obj->unkAC = fn_800D2FF4;
        obj->step++;
    case 1:
        if (obj->unkC8 != 0) {
            x = obj->unk60 >> 12;
            y = obj->unk64 >> 12;
            patch.w = 1;
            patch.h = 1;
            patch.tile = obj->unkCA;
            fn_8009EF24(x, y, &patch);
            pos[0] = obj->unk60;
            pos[1] = obj->unk64;
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
