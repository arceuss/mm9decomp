#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk800CEC10 {
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
    /* 0x15 */ u8 pad15[0x18 - 0x15];
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
    /* 0x34 */ struct Unk800CEC10* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ u8 pad6C[0x7C - 0x6C];
    /* 0x7C */ u8 unk7C;
    /* 0x7D */ u8 pad7D[0xAC - 0x7D];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 padCC[0xD0 - 0xCC];
    /* 0xD0 */ u16 unkD0;
    /* 0xD2 */ u16 unkD2;
    /* 0xD4 */ s8 unkD4;
} Unk800CEC10;

extern Unk80280390Entry* lbl_80280390[];

extern u8 lbl_804ED048[8];

void fn_80040AD0(s32 arg0, void* pos, s32 arg2, s32 arg3);
void fn_800E946C(Unk800CEC10* obj, u8 id);
void fn_800E9750(Unk800CEC10* obj, u16 arg1);

void fn_800CEC10(Unk800CEC10* obj) {
    s32 dir;
    s32 dist;
    s32 range;
    u8 id;

    switch (obj->step) {
    case 0:
        obj->step++;
    case 1:
        dir = obj->unkD4;
        obj->unk60 += obj->unk68 * dir;
        dist = obj->unk60 - obj->unkC8;
        dist *= dir;
        range = obj->unkD2;
        if (dist >= range) {
            obj->state = 0;
            obj->step = 0;
            fn_80040AD0(2, &obj->unk60, 0, 0);
        } else if (dist - 0x2000 >= 0) {
            id = lbl_804ED048[(dist - 0x2000) / (range / 6)];
            if (obj->unk7C != id) {
                fn_800E946C(obj, id);
            }
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    }
    obj->unkD0--;
}
