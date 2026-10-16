#include "types.h"

typedef struct Unk802819B0Entry {
    /* 0x00 */ u8 pad0[0x4];
    /* 0x04 */ s32 unk4;
} Unk802819B0Entry;

typedef struct Unk800E46F8 {
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
} Unk800E46F8;

extern Unk802819B0Entry* lbl_802819B0[];
extern u8 lbl_804ED3E8[8];
extern void (*lbl_802817D4[])(Unk800E46F8* obj);

void fn_800E46F8(Unk800E46F8* obj) {
    obj->unk18 = lbl_802819B0[obj->unk9]->unk4;
    obj->unk10 = 1;
    obj->state = 0;
    obj->step = 0;
    obj->unk13 = 0;
    obj->state = lbl_804ED3E8[obj->unk14];
    obj->flagsA |= 3;
    lbl_802817D4[obj->state](obj);
}
