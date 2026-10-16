#include "types.h"

typedef struct Unk802819B0Entry {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ s32 unk10;
} Unk802819B0Entry;

typedef struct Unk80040FE4 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x10 - 0xB];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 pad14[0x18 - 0x14];
    /* 0x18 */ s32 unk18;
} Unk80040FE4;

extern Unk802819B0Entry* lbl_80265138[];

void fn_80040FE4(Unk80040FE4* obj) {
    obj->flagsA &= ~1;
    obj->unk18 = lbl_80265138[obj->unk9]->unk10;
    obj->unk10 = 4;
    obj->state = 0;
    obj->step = 0;
    obj->unk13 = 0;
}
