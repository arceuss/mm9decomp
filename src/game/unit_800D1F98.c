#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk800D1F98 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 padA;
    /* 0x0B */ u8 unkB;
    /* 0x0C */ u8 padC[0x14 - 0xC];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15[0x18 - 0x15];
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
    /* 0x34 */ struct Unk800D1F98* unk34;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0xC8 - 0x68];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
    /* 0xCD */ u8 padCD[0xD8 - 0xCD];
    /* 0xD8 */ s32 unkD8;
} Unk800D1F98;

typedef struct Vec2i {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Vec2i;

extern Unk80280390Entry* lbl_80280390[];
extern void* lbl_804EE908;

Unk800D1F98* fn_800E8C44(void* pool);

Unk800D1F98* fn_800D1F98(Unk800D1F98* parent, Vec2i* pos) {
    Unk800D1F98* obj = fn_800E8C44(lbl_804EE908);

    if (obj != NULL) {
        obj->unk2E = 0x10;
        obj->unk9 = 0xE;
        obj->unk18 = lbl_80280390[14]->unk0;
        obj->unk2A = 0;
        obj->unk2C = 0;
        obj->unk2F = 0;
        obj->unkB |= 0x20;
        obj->unk21 = obj->unk20;
        obj->unk34 = parent;
        obj->unk60 = pos->x;
        obj->unk64 = pos->y;
        obj->unk14 = 0;
        obj->unkC8 = parent->unkD8;
        obj->unkCC = 0;
    }
    return obj;
}
