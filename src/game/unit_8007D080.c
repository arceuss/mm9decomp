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

typedef struct Unk8007D080 {
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
    /* 0x34 */ struct Unk8007D080* parent;
    /* 0x38 */ u8 pad38[0x54 - 0x38];
    /* 0x54 */ u32 flags54_hi : 21;
    /* 0x54 */ u32 flags54_b10 : 1;
    /* 0x54 */ u32 flags54_lo : 10;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ Vec2i pos;
    /* 0x68 */ Vec2i vel;
    /* 0x70 */ s32 unk70;
    /* 0x74 */ u8 pad74[0xAC - 0x74];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
} Unk8007D080;

extern Unk80280390Entry* lbl_80270168[];

extern void* lbl_804EE810;

Unk8007D080* fn_800E8C44(void* pool);

void fn_8007D080(Unk8007D080* parent, Vec2i* pos, Vec2i* vel) {
    Unk8007D080* obj = fn_800E8C44(lbl_804EE810);

    if (obj != NULL) {
        obj->unk2E = 0x10;
        obj->unk9 = 17;
        obj->unk18 = lbl_80270168[17]->unk0;
        obj->unk2A = 0;
        obj->unk2C = 0;
        obj->unk2F = 0;
        obj->parent = parent;
        obj->pos = *pos;
        obj->vel = *vel;
        obj->unk14 = 0;
        obj->unk15 = 0;
    }
}
