#include "types.h"

typedef struct Vec2i {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Vec2i;

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk80056068 {
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
    /* 0x34 */ struct Unk80056068* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ s32 unk70;
    /* 0x74 */ s32 unk74;
    /* 0x78 */ u8 pad78[0x88 - 0x78];
    /* 0x88 */ u8 unk88[0xAC - 0x88];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
} Unk80056068;


typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x21C];
    /* 0x21C */ u8 unk21C[0x300 - 0x21C];
} Unk80304B90;

extern Unk80304B90 lbl_80304B90;
extern u8 lbl_802667D0[];

void fn_800E946C(Unk80056068* obj, u8 id);
void fn_800E91F0(Unk80056068* obj, void* arg1, s32 arg2);
void fn_80054FB8(void*);
void* fn_80040AD0(u8 kind, Vec2i* pos, s32 flipX, s32 flipY);
u8 fn_800406E4(s32 kind, Vec2i* pos);
void fn_800E9750(Unk80056068* obj, u16 arg1);
u32 fn_80080484(void* arg0, s32* pos, s32 arg2);
void fn_80042CF8(Unk80056068* obj, s32 arg1);

void fn_80056068(Unk80056068* obj) {
    Vec2i pos;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 3);
        fn_800E91F0(obj, lbl_802667D0, 1);
        obj->unkAC = fn_80054FB8;
        pos.x = obj->unk60;
        pos.y = obj->unk64 + 0x800;
        fn_80040AD0(2, &pos, 0, 0);
        fn_800406E4(0, &pos);
        obj->unk6C = 0;
        obj->unk74 = -8;
        obj->step++;
    case 1:
        fn_800E9750(obj, 0xFFFF);
        obj->unk64 += obj->unk6C;
        obj->unk6C += obj->unk74;
        if (fn_80080484(lbl_80304B90.unk21C, &obj->unk60, 1) >= 0x1800) {
            fn_80042CF8(obj, 4);
        }
        break;
    }
}
