#include "types.h"

typedef struct Unk8027F3C8Entry {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ s32 unk10;
} Unk8027F3C8Entry;

typedef struct Unk800C5378Owner {
    /* 0x000 */ u8 pad0[0x1F9];
    /* 0x1F9 */ u8 unk1F9;
} Unk800C5378Owner;

typedef struct Unk800C5378 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 flagsB;
    /* 0x0C */ u8 padC[0x10 - 0xC];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 pad14[0x18 - 0x14];
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[0x34 - 0x1C];
    /* 0x34 */ Unk800C5378Owner* owner;
} Unk800C5378;

extern Unk8027F3C8Entry* lbl_8027F3C8[];

void fn_800E9244(Unk800C5378* obj);

void fn_800C5378(Unk800C5378* obj) {
    obj->unk18 = lbl_8027F3C8[obj->unk9]->unk10;
    obj->unk10 = 4;
    obj->state = 0;
    obj->step = 0;
    obj->unk13 = 0;
    fn_800E9244(obj);
    obj->flagsA &= ~1;
    obj->flagsB &= 0xEF;
    obj->owner->unk1F9 = 0;
}
