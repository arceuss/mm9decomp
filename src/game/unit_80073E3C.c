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

typedef struct Unk80073E3C {
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
    /* 0x34 */ struct Unk80073E3C* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ Vec2i pos;
    /* 0x68 */ u8 pad68[0xA0 - 0x68];
    /* 0xA0 */ u32 flagsA0;
    /* 0xA4 */ u8 padA4[0xAC - 0xA4];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ Vec2i unkC8;
} Unk80073E3C;

extern Unk80280390Entry* lbl_80265138[];

typedef struct Unk80073E3CHit {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ struct Unk80073E3CHit* other;
    /* 0x10 */ u8 pad10[0x14 - 0x10];
    /* 0x14 */ u32 flags;
    /* 0x18 */ u8 pad18[0x23 - 0x18];
    /* 0x23 */ u8 kind_hi : 4;
    /* 0x23 */ u8 kind : 4;
    /* 0x24 */ u8 pad24[0x28 - 0x24];
    /* 0x28 */ void* obj;
} Unk80073E3CHit;

void fn_800B5ECC(Unk80073E3C* player, s32* pos);
void fn_800B5F38(Unk80073E3C* player, s32 arg1);

void fn_80073E3C(Unk80073E3CHit* hit) {
    Unk80073E3C* self = hit->obj;
    Unk80073E3C* target = hit->other->obj;

    if ((hit->flags & 1) && hit->kind == 3) {
        self->unkC8 = target->pos;
    }
}
