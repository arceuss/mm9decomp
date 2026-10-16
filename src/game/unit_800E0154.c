#include "types.h"
#include "game/sound.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk800E0154 {
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
    /* 0x34 */ void* parent;
    /* 0x38 */ u8 pad38[0x54 - 0x38];
    /* 0x54 */ u32 unk54_0 : 21;
    /* 0x54 */ u32 flipX : 1;
    /* 0x54 */ u32 unk54_22 : 10;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ u8 pad6C[0x88 - 0x6C];
    /* 0x88 */ u8 unk88;
    /* 0x89 */ u8 pad89[0xAC - 0x89];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
} Unk800E0154;

extern Unk80280390Entry* lbl_802819B0[];

typedef struct Unk800E0154Parent {
    /* 0x0000 */ u8 pad0[0xFF4];
    /* 0x0FF4 */ u8 unkFF4;
    /* 0x0FF5 */ u8 unkFF5;
} Unk800E0154Parent;

typedef struct Vec2i {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Vec2i;

extern Vec2i lbl_802810E0[][18];

void fn_800E946C(Unk800E0154* obj, u8 id);
void fn_800E9750(Unk800E0154* obj, u16 arg1);

static inline void SyncFlip(Unk800E0154* obj) {
    if (obj->flipX) {
        obj->flagsA |= 0x10;
    } else {
        obj->flagsA &= 0xEF;
    }
}

extern void* lbl_804EE948;

Unk800E0154* fn_800E8C44(void* pool);
void fn_800D5234(s32 id);
void fn_800D5458(s32 id);

static inline Unk800E0154* Spawn(Unk800E0154* owner) {
    Unk800E0154* obj = fn_800E8C44(lbl_804EE948);

    if (obj != NULL) {
        obj->unk2E = 0x10;
        obj->unk9 = 10;
        obj->unk18 = lbl_802819B0[10]->unk0;
        obj->unk2A = 0;
        obj->unk2C = 0;
        obj->unk2F = 0;
        obj->unk14 = 0x10;
        obj->unk15 = 0xB;
        obj->unk60 = owner->unk60;
        obj->unk64 = owner->unk64;
        obj->parent = owner;
    }
    return obj;
}

void fn_800E0154(Unk800E0154* obj) {
    Unk800E0154Parent* parent = obj->parent;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 0xF);
        obj->flipX = 1;
        SyncFlip(obj);
        obj->unk60 = lbl_802810E0[obj->unk14][obj->unk15].x;
        obj->unk64 = lbl_802810E0[obj->unk14][obj->unk15].y;
        obj->unk68 = -0x200;
        fn_800D5234(SE_UFO_LOOP);
        obj->step++;
    case 1:
        obj->unk60 += obj->unk68;
        if (obj->unk60 <= 0x5800) {
            obj->unk60 = 0x5800;
            obj->step++;
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    case 2:
        obj->unk88 = 0;
        Spawn(obj);
        obj->unk16 = 0;
        obj->step++;
    case 3:
        if (obj->unk88 == 1 && ++obj->unk16 > 0x1E) {
            obj->step++;
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    case 4:
        obj->step++;
    case 5:
        obj->unk60 += obj->unk68;
        if (obj->unk60 <= -0x1800) {
            fn_800D5458(SE_UFO_LOOP);
            parent->unkFF5 = 1;
            obj->unk18 = lbl_802819B0[obj->unk9]->unk10;
            obj->unk10 = 4;
            obj->state = 0;
            obj->step = 0;
            obj->unk13 = 0;
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    }
}
