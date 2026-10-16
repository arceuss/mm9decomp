#include "types.h"

typedef struct Unk8027F3C8Entry {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ s32 unk10;
} Unk8027F3C8Entry;

typedef struct Unk800C2EA0 {
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
} Unk800C2EA0;

extern Unk8027F3C8Entry* lbl_8027F3C8[];

void fn_800E9244(Unk800C2EA0* obj);
void fn_800E9CB8(Unk800C2EA0* obj);

void fn_800C2EA0(Unk800C2EA0* obj) {
    obj->flagsA &= ~1;
    fn_800E9244(obj);
    obj->flagsB &= 0xEF;
    fn_800E9CB8(obj);
    obj->unk18 = lbl_8027F3C8[obj->unk9]->unk10;
    obj->unk10 = 4;
    obj->state = 0;
    obj->step = 0;
    obj->unk13 = 0;
}
