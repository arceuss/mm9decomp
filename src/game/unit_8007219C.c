#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk8007219C {
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
    /* 0x34 */ struct Unk8007219C* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ s32 unk70;
    /* 0x74 */ s32 unk74;
    /* 0x78 */ u8 pad78[0xAC - 0x78];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ u32 unkC8;
    /* 0xCC */ u8 unkCC;
    /* 0xCD */ u8 padCD[0xEC - 0xCD];
    /* 0xEC */ u8 unkEC;
    /* 0xED */ u8 unkED;
    /* 0xEE */ u8 unkEE;
    /* 0xEF */ u8 unkEF;
    /* 0xF0 */ u8 padF0[0xF4 - 0xF0];
    /* 0xF4 */ u8 unkF4;
    /* 0xF5 */ u8 unkF5;
    /* 0xF6 */ u8 unkF6;
    /* 0xF7 */ u8 unkF7;
} Unk8007219C;


void fn_8007219C(Unk8007219C* obj) {
    switch (obj->step) {
    case 0:
        obj->step++;
        obj->unk16 = 80;
        obj->unk68 = (obj->unk74 - obj->unk60) / 80;
    case 1:
        obj->unk60 += obj->unk68;
        if (obj->unk16 == 0) {
            obj->step++;
        } else {
            obj->unk16--;
        }
        break;
    case 2:
        obj->unk16 = 30;
        obj->step++;
    case 3:
        if (obj->unk16 == 0) {
            switch (obj->unkC8) {
            case 0:
                obj->parent->unkEC = 0;
                obj->parent->unkF4 = 0;
                break;
            case 1:
                obj->parent->unkED = 0;
                obj->parent->unkF5 = 0;
                break;
            case 2:
                obj->parent->unkEE = 0;
                obj->parent->unkF6 = 0;
                break;
            case 3:
                obj->parent->unkEF = 0;
                obj->parent->unkF7 = 0;
                break;
            }
            obj->state = 0;
            obj->step = 0;
        } else {
            obj->unk16--;
        }
        break;
    }
}
