#include "types.h"

typedef struct Unk802819B0Entry {
    /* 0x00 */ u8 pad0[0x4];
    /* 0x04 */ s32 unk4;
} Unk802819B0Entry;

typedef struct Unk800DB310 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x10 - 0xB];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15[0x18 - 0x15];
    /* 0x18 */ s32 unk18;
} Unk800DB310;

extern Unk802819B0Entry* lbl_802819B0[];
extern u8 lbl_804ED3B0[8];
extern void (*lbl_80280F18[])(Unk800DB310* obj);

void fn_800DB310(Unk800DB310* obj) {
    obj->unk18 = lbl_802819B0[obj->unk9]->unk4;
    obj->unk10 = 1;
    obj->state = 0;
    obj->step = 0;
    obj->unk13 = 0;
    obj->state = lbl_804ED3B0[obj->unk14];
    obj->flagsA |= 3;
    lbl_80280F18[obj->state](obj);
}
