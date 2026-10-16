#include "types.h"

typedef struct Unk8027F3C8Entry {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ s32 unk10;
} Unk8027F3C8Entry;

typedef struct Unk800C3354Owner {
    /* 0x000 */ u8 pad0[0x1F8];
    /* 0x1F8 */ u8 unk1F8;
} Unk800C3354Owner;

typedef struct Unk800C3354 {
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
    /* 0x34 */ Unk800C3354Owner* owner;
    /* 0x38 */ u8 pad38[0xC9 - 0x38];
    /* 0xC9 */ u8 unkC9;
} Unk800C3354;

extern Unk8027F3C8Entry* lbl_8027F3C8[];

void fn_800E9244(Unk800C3354* obj);

void fn_800C3354(Unk800C3354* obj) {
    s32 count;

    obj->unk18 = lbl_8027F3C8[obj->unk9]->unk10;
    obj->unk10 = 4;
    obj->state = 0;
    obj->step = 0;
    obj->unk13 = 0;
    fn_800E9244(obj);
    obj->flagsA &= ~1;
    obj->flagsB &= 0xEF;
    count = obj->owner->unk1F8;
    count -= obj->unkC9;
    if (count < 0) {
        count = 0;
    }
    obj->owner->unk1F8 = count;
}
