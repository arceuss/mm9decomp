#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk80022914 {
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
    /* 0x34 */ struct Unk80022914* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0xAC - 0x68];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
} Unk80022914;

extern Unk80280390Entry* lbl_802638A0[];

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x125];
    /* 0x125 */ u8 unk125;
    /* 0x126 */ u8 pad126[0x2D8 - 0x126];
    /* 0x2D8 */ u32 unk2D8;
} Unk80304B90;

extern Unk80304B90 lbl_80304B90;

extern void* lbl_804EE984;

void fn_800E9244(Unk80022914* obj);
void fn_80040D50(s32* pos);
void fn_800C7770(void* player);

void fn_80022914(Unk80022914* obj) {
    s32 pos[2];

    switch (obj->step) {
    case 0:
        fn_800E9244(obj);
        obj->flagsA &= ~1;
        pos[0] = obj->unk60;
        pos[1] = obj->unk64 - 0x800;
        fn_80040D50(pos);
        if (!(lbl_80304B90.unk2D8 & 1)) {
            lbl_80304B90.unk2D8 |= 2;
        }
        fn_800C7770(lbl_804EE984);
        obj->step++;
        break;
    case 1:
        lbl_80304B90.unk125 |= 2;
        lbl_80304B90.unk2D8 &= 0xFFFD;
        obj->unk18 = lbl_802638A0[obj->unk9]->unk10;
        obj->unk10 = 4;
        obj->state = 0;
        obj->step = 0;
        obj->unk13 = 0;
        break;
    }
}
