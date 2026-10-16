#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Vec2i {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Vec2i;

typedef struct Unk80070CF8 {
    /* 0x00 */ u8 pad0[0x8];
    /* 0x08 */ s8 unk8;
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
    /* 0x34 */ struct Unk80070CF8* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ Vec2i pos;
    /* 0x68 */ u8 pad68[0xA0 - 0x68];
    /* 0xA0 */ u32 flagsA0;
    /* 0xA4 */ u8 padA4[0xAC - 0xA4];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ u8 unkC8;
    /* 0xC9 */ u8 padC9[0xD0 - 0xC9];
} Unk80070CF8;

extern Unk80280390Entry* lbl_80265138[];

typedef struct Unk80070CF8Hit {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ struct Unk80070CF8Hit* other;
    /* 0x10 */ u8 pad10[0x14 - 0x10];
    /* 0x14 */ u32 flags;
    /* 0x18 */ u8 pad18[0x23 - 0x18];
    /* 0x23 */ u8 kind_hi : 4;
    /* 0x23 */ u8 kind : 4;
    /* 0x24 */ u8 pad24[0x28 - 0x24];
    /* 0x28 */ void* obj;
} Unk80070CF8Hit;

void fn_800B5ECC(Unk80070CF8* player, s32* pos);
extern Unk80070CF8* lbl_804EE984;

void fn_800B5F38(Unk80070CF8* player, s32 arg1);

void fn_80070CF8(Unk80070CF8Hit* hit) {
    Unk80070CF8* self = hit->obj;
    Unk80070CF8* target = hit->other->obj;

    if (hit->flags & 0x400) {
        self->pos.x = lbl_804EE984->pos.x;
        self->pos.y = lbl_804EE984->pos.y;
    }
    if ((hit->flags & 8) && target->unk8 == 5 && target->unk9 == 10) {
        if ((target->state == 2 && target->step >= 2) || (target->state == 3 && target->step >= 4)) {
            if (self->unkC8 == 0) {
                self->unkC8++;
            }
        }
    }
}
