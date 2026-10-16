#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk800D23D8 {
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
    /* 0x34 */ struct Unk800D23D8* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ u8 pad6C[0x74 - 0x6C];
    /* 0x74 */ s32 unk74;
    /* 0x78 */ u8 pad78[0xAC - 0x78];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
    /* 0xCD */ u8 padCD[0xD8 - 0xCD];
    /* 0xD8 */ s32 unkD8;
    /* 0xDC */ u8 padDC[0xEC - 0xDC];
    /* 0xEC */ u8 unkEC[4];
    /* 0xF0 */ u8 padF0[0xF4 - 0xF0];
    /* 0xF4 */ u8 unkF4[4];
} Unk800D23D8;

extern Unk80280390Entry* lbl_80280390[];

void fn_80040AD0(s32 arg0, s32* pos, s32 arg2, s32 arg3);
void fn_800D5234(s32 id);
void fn_800E9244(Unk800D23D8* obj);

void fn_800D23D8(Unk800D23D8* obj) {
    s32 pos[2];

    switch (obj->step) {
    case 0:
        obj->unk16 = obj->unk14 * 8 + 0x15;
        obj->step++;
    case 1:
        if (obj->unk16 == 0) {
            pos[0] = obj->unk60;
            pos[1] = obj->unk64;
            fn_80040AD0(2, pos, 0, 0);
            fn_800D5234(0x13);
            fn_800E9244(obj);
            obj->flagsA &= ~1;
            obj->unk18 = lbl_80280390[obj->unk9]->unk10;
            obj->unk10 = 4;
            obj->state = 0;
            obj->step = 0;
            obj->unk13 = 0;
        } else {
            obj->unk16--;
        }
        break;
    }
}
