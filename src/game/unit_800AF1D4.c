#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk800AF1D4 {
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
    /* 0x1C */ struct Unk800AF1D4* unk1C;
    /* 0x20 */ u8 unk20;
    /* 0x21 */ u8 unk21;
    /* 0x22 */ u8 pad22[0x2A - 0x22];
    /* 0x2A */ s16 unk2A;
    /* 0x2C */ u8 unk2C;
    /* 0x2D */ u8 pad2D;
    /* 0x2E */ u8 unk2E;
    /* 0x2F */ u8 unk2F;
    /* 0x30 */ u8 pad30[0x34 - 0x30];
    /* 0x34 */ struct Unk800AF1D4* parent;
    /* 0x38 */ struct Unk800AF1D4* unk38;
    /* 0x3C */ u8 pad3C[0x60 - 0x3C];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0xAC - 0x68];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
    /* 0xCD */ u8 padCD[0xEC - 0xCD];
    /* 0xEC */ u8 prevState;
    /* 0xED */ u8 prevStep;
    /* 0xEE */ u8 prev13;
    /* 0xEF */ u8 unkEF;
    /* 0xF0 */ u8 unkF0;
    /* 0xF1 */ u8 unkF1;
    /* 0xF2 */ u8 prevEF;
    /* 0xF3 */ u8 prevF0;
    /* 0xF4 */ u8 prevF1;
    /* 0xF5 */ u8 unkF5;
    /* 0xF6 */ u8 padF6[0x104 - 0xF6];
    /* 0x104 */ u32 unk104;
    /* 0x108 */ u8 pad108[0x10C - 0x108];
    /* 0x10C */ u8 unk10C;
} Unk800AF1D4;


Unk800AF1D4* fn_80041028(s32 arg0, s32 arg1, s32* pos, s32 flip);

static inline void SetStep(Unk800AF1D4* p, u8 step) {
    p->prevStep = p->step;
    p->step = step;
    p->prev13 = p->unk13;
    p->unk13 = 0;
}

static inline void SetState(Unk800AF1D4* p, u8 state) {
    p->prevState = p->state;
    p->state = state;
    p->prevStep = p->step;
    p->step = 0;
    p->prev13 = p->unk13;
    p->unk13 = 0;
    p->prevEF = p->unkEF;
    p->unkEF = 0;
    p->prevF0 = p->unkF0;
    p->unkF0 = 0;
    p->prevF1 = p->unkF1;
    p->unkF1 = 0;
    p->unkF5 = state;
}

void fn_800AF1D4(Unk800AF1D4* p) {
    p->unk104 |= 0x200;
    switch (p->step) {
    case 0:
        p->unk104 |= 8;
        p->flagsA &= ~1;
        if (!(p->unk1C->unk9 & 1)) {
            break;
        }
        if (p->unk104 & 0x40000) {
            p->unk38 = fn_80041028(0, 2, &p->unk60, (p->flagsA >> 4) & 1);
        } else {
            p->unk38 = fn_80041028(0, 0, &p->unk60, (p->flagsA >> 4) & 1);
        }
        p->unk104 &= ~0x40000;
        SetStep(p, 1);
    case 1:
        if (p->unk38 != NULL && p->unk38->unk10 < 2) {
            break;
        }
        p->unk104 &= ~8;
        p->flagsA |= 1;
        p->unk104 &= ~0x200;
        SetState(p, 0);
        break;
    }
}
