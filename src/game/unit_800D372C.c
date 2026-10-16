#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk800D372C {
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
    /* 0x34 */ struct Unk800D372C* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0xAC - 0x68];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
} Unk800D372C;

extern Unk80280390Entry* lbl_80280390[];

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x126];
    /* 0x126 */ u8 unk126;
    /* 0x127 */ u8 pad127[0x21A - 0x127];
    /* 0x21A */ u16 unk21A;
    /* 0x21C */ u8 pad21C[0x2B0 - 0x21C];
    /* 0x2B0 */ s32 unk2B0;
} Unk80304B90;

typedef struct Unk800D372COther {
    /* 0x00 */ u8 pad0[0x8];
    /* 0x08 */ s8 unk8;
    /* 0x09 */ u8 pad9[0x60 - 0x9];
    /* 0x60 */ s32 unk60;
} Unk800D372COther;

typedef struct Unk800D372CHit {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ struct Unk800D372CHit* other;
    /* 0x10 */ u8 pad10[0x28 - 0x10];
    /* 0x28 */ void* obj;
} Unk800D372CHit;

extern Unk80304B90 lbl_80304B90;

BOOL fn_800B661C(Unk800D372COther* p, s32 arg);

void fn_800D372C(Unk800D372CHit* hit) {
    Unk800D372C* self = hit->obj;
    Unk800D372COther* target = hit->other->obj;

    if (self->step < 2 && target->unk8 == 0 && (u32)(target->unk60 - self->unk60 + 0x200) < 0x400 && fn_800B661C(target, 1)) {
        self->parent = (Unk800D372C*)target;
        lbl_80304B90.unk126 |= 2;
        lbl_80304B90.unk21A = 0x8000;
        lbl_80304B90.unk2B0 = 2;
        self->step = 2;
    }
}
