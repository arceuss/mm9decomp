#include "types.h"

typedef struct Unk80079D28 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 kind;
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x10 - 0xB];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 pad14[0x18 - 0x14];
    /* 0x18 */ void* unk18;
    /* 0x1C */ u8 pad1C[0x34 - 0x1C];
    /* 0x34 */ struct Unk80079D28* parent;
} Unk80079D28;

typedef struct Unk803051D8 {
    /* 0x00 */ u8 pad0[0x2];
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 pad3[0x38 - 0x3];
} Unk803051D8;

extern Unk803051D8 lbl_803051D8;
extern void** lbl_80270168[];
extern void (*lbl_8026FF40[])(Unk80079D28* obj);

void fn_800E9244(Unk80079D28* obj);

static inline void SetMode(Unk80079D28* obj, u8 mode) {
    obj->unk18 = lbl_80270168[obj->kind][mode];
    obj->unk10 = mode;
    obj->state = 0;
    obj->step = 0;
    obj->unk13 = 0;
}

BOOL fn_8007A8DC(Unk80079D28* obj);

void fn_80079D28(Unk80079D28* obj) {
    if (obj->parent->unk10 >= 2) {
        obj->flagsA &= ~1;
        obj->flagsA &= 0xFD;
        fn_800E9244(obj);
        SetMode(obj, 3);
        return;
    }
    if (lbl_803051D8.unk2 & 0x20) {
        obj->flagsA &= ~1;
        obj->flagsA &= 0xFD;
        fn_800E9244(obj);
        SetMode(obj, 3);
        return;
    }
    if (fn_8007A8DC(obj)) {
        fn_800E9244(obj);
        obj->flagsA &= ~1;
        SetMode(obj, 4);
    } else {
        lbl_8026FF40[obj->state](obj);
    }
}
