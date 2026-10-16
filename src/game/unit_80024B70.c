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

typedef struct Unk80024B70 {
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
    /* 0x34 */ Vec2i* parent;
    /* 0x38 */ u32* unk38;
    /* 0x3C */ u8 pad3C[0x60 - 0x3C];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0x88 - 0x68];
    /* 0x88 */ u8 unk88;
    /* 0x89 */ u8 pad89[0xAC - 0x89];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
} Unk80024B70;


typedef struct Unk803051D8 {
    /* 0x00 */ u8 pad0[0x3];
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 pad4[0x38 - 0x4];
} Unk803051D8;

extern Unk803051D8 lbl_803051D8;
extern u32 lbl_80263980[];
extern u8 lbl_80263970[];

void fn_80024B70(Unk80024B70* obj) {
    Vec2i* base = obj->parent;
    u32 cur = *obj->unk38;
    u32 max;
    u8 frame;
    u8 digit;

    if (lbl_803051D8.unk3 & 0x40) {
        obj->flagsA |= 1;
    } else {
        obj->flagsA &= ~1;
    }
    max = lbl_80263980[obj->unk15];
    if (max == 0xFFFFFFFF) {
        frame = 10;
    } else if (max == 0xFFFFFFFE) {
        frame = 11;
    } else {
        if (cur == 0x8CA0 && obj->unk15 == 7) {
            digit = 0;
        } else {
            cur *= 100;
            cur /= max;
            if (obj->unk15 == 3) {
                digit = cur % 6;
            } else {
                digit = cur % 10;
            }
        }
        frame = lbl_80263970[digit];
    }
    obj->unk60 = base->x + obj->unk15 * 0xA00;
    obj->unk64 = base->y;
    obj->unk88 = frame;
}
