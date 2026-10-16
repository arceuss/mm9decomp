#include "types.h"

typedef struct Unk802819B0Entry {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ s32 unk10;
} Unk802819B0Entry;

typedef struct Unk800CF4AC {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 padA[0x10 - 0xA];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 pad14[0x18 - 0x14];
    /* 0x18 */ s32 unk18;
} Unk800CF4AC;

extern Unk802819B0Entry* lbl_80280390[];

void fn_800E9244(Unk800CF4AC* obj);

void fn_800CF4AC(Unk800CF4AC* obj) {
    fn_800E9244(obj);
    obj->unk18 = lbl_80280390[obj->unk9]->unk10;
    obj->unk10 = 4;
    obj->state = 0;
    obj->step = 0;
    obj->unk13 = 0;
}
