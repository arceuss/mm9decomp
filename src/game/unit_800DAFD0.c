#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk800DAFD0 {
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
    /* 0x34 */ struct Unk800DAFD0Parent* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0x7D - 0x68];
    /* 0x7D */ s8 unk7D;
    /* 0x7E */ s8 unk7E;
    /* 0x7F */ u8 pad7F[0x88 - 0x7F];
    /* 0x88 */ u8 unk88;
    /* 0x89 */ u8 unk89;
    /* 0x8A */ u8 pad8A[0xAC - 0x8A];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
} Unk800DAFD0;


typedef struct Unk800DAFD0Parent {
    /* 0x000 */ u8 pad0[0x2AC];
    /* 0x2AC */ u8 unk2AC;
    /* 0x2AD */ u8 unk2AD;
    /* 0x2AE */ u16 unk2AE;
} Unk800DAFD0Parent;

void fn_800E946C(Unk800DAFD0* obj, u8 id);
void fn_800E947C(Unk800DAFD0* obj, u8 id, s8 arg2, s8 arg3);
void fn_8003C6E4(s32* pos, u8 arg1, u8 arg2);

void fn_800DAFD0(Unk800DAFD0* obj) {
    s8 a;
    s8 b;

    switch (obj->state) {
    case 0:
        if (obj->unk15 == 0) {
            obj->unk88 = 0xF;
            fn_8003C6E4(&obj->unk60, 0, obj->parent->unk2AC);
        } else {
            if (obj->parent->unk2AE & 4) {
                obj->unk88 = 0xB;
            } else {
                obj->unk88 = 4;
            }
            fn_8003C6E4(&obj->unk60, 1, 0);
        }
        obj->unk89 = obj->parent->unk2AC;
        fn_800E946C(obj, obj->unk88);
        obj->state++;
        break;
    case 1:
        if (obj->unk15 != obj->parent->unk2AD) {
            obj->flagsA &= ~1;
            break;
        }
        obj->flagsA |= 1;
        if (obj->unk15 != 0 && obj->unk89 != obj->parent->unk2AC) {
            a = obj->unk7D;
            b = obj->unk7E;
            if (obj->parent->unk2AC == 0) {
                if (obj->parent->unk2AE & 4) {
                    obj->unk88 = 0xB;
                } else {
                    obj->unk88 = 4;
                }
            } else {
                obj->unk88 = 4;
            }
            fn_800E947C(obj, obj->unk88, a, b);
        }
        obj->unk89 = obj->parent->unk2AC;
        fn_8003C6E4(&obj->unk60, obj->parent->unk2AD, obj->parent->unk2AC);
        break;
    }
}
