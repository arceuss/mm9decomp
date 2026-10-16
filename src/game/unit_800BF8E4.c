#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk800BF8E4 {
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
    /* 0x34 */ struct Unk800BF8E4* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0xAC - 0x68];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ u8 unkC8;
    /* 0xC9 */ u8 unkC9;
    /* 0xCA */ u8 unkCA;
    /* 0xCB */ u8 unkCB;
    /* 0xCC */ u8 unkCC;
} Unk800BF8E4;

extern s32* lbl_8027F228[10];

typedef struct Unk800BF8E4Player {
    /* 0x000 */ u8 pad0[0x1F8];
    /* 0x1F8 */ u8 shots;
} Unk800BF8E4Player;

extern void* lbl_804EE8C0;
extern const u8 lbl_804EE8E0[8];

Unk800BF8E4* fn_800E8C44(void* pool);
void fn_800BBBFC(Unk800BF8E4* obj, s32 arg1);

Unk800BF8E4* fn_800BF8E4(Unk800BF8E4Player* p, u8 arg1, u8 kind, u8 cost, u8 arg4) {
    Unk800BF8E4* obj = fn_800E8C44(lbl_804EE8C0);

    if (obj != NULL) {
        obj->parent = (Unk800BF8E4*)p;
        obj->unk15 = kind;
        obj->unk14 = lbl_804EE8E0[kind];
        obj->unk9 = 5;
        obj->unk18 = *lbl_8027F228[5];
        fn_800BBBFC(obj, 0);
        obj->unk2E = 0x10;
        obj->unk2A = 0;
        obj->unk2C = 0;
        obj->unk2F = 0;
        obj->flagsB &= 0xDF;
        obj->unk21 = obj->unk20;
        obj->unkC8 = cost;
        p->shots = cost + p->shots;
        obj->unkCA = arg4;
    }
    return obj;
}
