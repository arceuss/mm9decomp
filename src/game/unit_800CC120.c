#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
} Unk80280390Entry;

typedef struct Unk800CC120 {
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
    /* 0x34 */ struct Unk800CC120* parent;
    /* 0x38 */ s32 unk38;
    /* 0x3C */ u8 pad3C[0x60 - 0x3C];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ u8 pad6C[0xAC - 0x6C];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ u8 unkC8;
    /* 0xC9 */ u8 padC9;
    /* 0xCA */ s16 unkCA;
    /* 0xCC */ struct Unk800CC120* unkCC;
    /* 0xD0 */ struct Unk800CC120* unkD0;
} Unk800CC120;

extern Unk80280390Entry* lbl_80280390[];

Unk800CC120* fn_800CC050(Unk800CC120* parent, s32 dy, u8 arg2, u8 arg3);

void fn_800CC120(Unk800CC120* obj) {
    Unk800CC120* link;

    obj->unkCC = NULL;
    obj->unk38 = 0;
    obj->unkC8 = 0;
    link = fn_800CC050(obj, 0x1500, 2, 1);
    if (link != NULL) {
        link->unkCC = obj;
        link = fn_800CC050(link, 0x1500, 2, 2);
    }
    if (link != NULL) {
        link->unkCC = obj;
        link = fn_800CC050(link, 0x1500, 2, 3);
    }
    if (link != NULL) {
        link->unkCC = obj;
        link = fn_800CC050(link, 0xF00, 1, 4);
    }
    if (link != NULL) {
        link->unkCC = obj;
        obj->unkD0 = link;
    }
}
