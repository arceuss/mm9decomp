#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk80010A14 {
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
    /* 0x34 */ struct Unk80010A14* parent;
    /* 0x38 */ u8 pad38[0x54 - 0x38];
    /* 0x54 */ u32 unk54_0 : 21;
    /* 0x54 */ u32 flipX : 1;
    /* 0x54 */ u32 unk54_22 : 10;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0xAC - 0x68];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
    /* 0xCD */ u8 padCD[0xD8 - 0xCD];
    /* 0xD8 */ s32 unkD8;
    /* 0xDC */ s32 unkDC;
    /* 0xE0 */ s32 unkE0;
    /* 0xE4 */ s8 unkE4;
    /* 0xE5 */ u8 padE5;
    /* 0xE6 */ u8 unkE6;
} Unk80010A14;

typedef struct Vec2i {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Vec2i;

extern Unk80280390Entry* lbl_802638A0[];
extern u8 lbl_802620D0[];
extern u8 lbl_803012C8[0x40];
extern u32 lbl_804EE988;
extern Unk80010A14* lbl_804EE984;

void fn_800E9424(Unk80010A14* obj, u16 anim);
void fn_800E91F0(Unk80010A14* obj, void* arg1, s32 arg2);
void fn_80010D7C(void*);
void fn_800D1F98(Unk80010A14* obj, Vec2i pos);
void fn_80010C98(Unk80010A14* obj);

static inline void SyncFlip(Unk80010A14* obj) {
    if (obj->flipX) {
        obj->flagsA |= 0x10;
    } else {
        obj->flagsA &= 0xEF;
    }
}

void fn_80010A14(Unk80010A14* obj) {
    Vec2i pos;
    u32 seed;
    s32 i;

    fn_800E9424(obj, 0x31);
    obj->flagsA |= 1;
    fn_800E91F0(obj, lbl_802620D0, 0xF);
    obj->unkAC = fn_80010D7C;
    obj->unk18 = lbl_802638A0[obj->unk9]->unk4;
    obj->unk10 = 1;
    obj->state = 0;
    obj->step = 0;
    obj->unk13 = 0;
    if (obj->unk14 == 0) {
        obj->unk2E = 0x11;
        obj->state = 0;
        obj->step = 0;
        obj->unkDC = obj->unk60 = obj->unk60 / 0x10000 * 0x10000 + 0x8000;
        obj->unkE0 = obj->unk64 = (obj->unk64 >> 12) / 14 * 14 * 0x1000 + 0x8200;
        pos.x = obj->unk60;
        pos.y = obj->unk64 - 0x200;
        fn_800D1F98(obj, pos);
        obj->flipX = lbl_804EE984->unk60 - obj->unk60 > 0;
        SyncFlip(obj);
        obj->unkE4 = -1;
        seed = lbl_804EE988;
        for (i = 0; i < 0x40; i++) {
            seed = seed * 0x343FD + 0x269EC3;
            lbl_803012C8[i] = (seed >> 16) & 7;
            seed &= 0x7FFFFFFF;
        }
        lbl_804EE988 = seed;
        obj->unkD8 = 0x10;
    } else {
        obj->state = 7;
        obj->step = 0;
        obj->unkE6 = 0;
    }
    fn_80010C98(obj);
}
