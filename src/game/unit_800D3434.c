#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk804EE984 {
    /* 0x00 */ u8 pad0[0x64];
    /* 0x64 */ s32 unk64;
} Unk804EE984;

typedef struct Unk800D3434 {
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
    /* 0x34 */ struct Unk800D3434* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0x6C - 0x68];
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ u8 pad70[0xAC - 0x70];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
} Unk800D3434;

extern Unk80280390Entry* lbl_80280390[];

extern void* lbl_804EE908;
extern Unk804EE984* lbl_804EE984;
extern u8 lbl_80280300[12];

s32 fn_800A4C0C(s32 x, s32 y);
BOOL fn_800A37F4(s32 x, s32 y);
Unk800D3434* fn_800E8C44(void* pool);

void fn_800D3434(Unk800D3434* obj) {
    u8 kind;
    s32 x;
    s32 y;
    u32 i;
    Unk800D3434* child;

    switch (obj->step) {
    case 0:
        x = fn_800A4C0C(obj->unk60, obj->unk64) + 0x800;
        y = obj->unk64;
        for (i = 0; i < 12; i++) {
            kind = lbl_80280300[(u8)i];
            child = fn_800E8C44(lbl_804EE908);
            if (child != NULL) {
                child->unk2E = 0x10;
                child->unk9 = 0x11;
                child->unk18 = lbl_80280390[0x11]->unk0;
                child->unk2A = 0;
                child->unk2C = 0;
                child->unk2F = 0;
                child->flagsB |= 0x20;
                child->unk21 = child->unk20;
                child->parent = obj;
                child->unk60 = x + ((u8)i << 12);
                child->unk64 = y;
                child->unk14 = 2;
                child->unk15 = kind;
            }
        }
        obj->step++;
    case 1:
        if (lbl_804EE984->unk64 <= obj->unk64) {
            obj->step++;
        }
        break;
    case 2:
        obj->unk6C = -0x80;
        obj->step++;
    case 3:
        obj->unk64 += obj->unk6C;
        if (fn_800A37F4(obj->unk60, obj->unk64)) {
            obj->unk6C = 0;
        }
        break;
    }
}
