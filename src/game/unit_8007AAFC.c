#include "types.h"

typedef struct Unk8007AAFC {
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
    /* 0x1C */ u8 pad1C[0xA0 - 0x1C];
    /* 0xA0 */ u32 hitFlags;
} Unk8007AAFC;

typedef struct Unk803051D8 {
    /* 0x00 */ u8 pad0[0x2];
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 pad3[0x38 - 0x3];
} Unk803051D8;

extern Unk803051D8 lbl_803051D8;
extern void** lbl_80270168[];
extern void (*lbl_8026FF98[])(Unk8007AAFC* obj);

void fn_800E9244(Unk8007AAFC* obj);

static inline void SetMode(Unk8007AAFC* obj, u8 mode) {
    obj->unk18 = lbl_80270168[obj->kind][mode];
    obj->unk10 = mode;
    obj->state = 0;
    obj->step = 0;
    obj->unk13 = 0;
}

static inline BOOL CheckHit(Unk8007AAFC* obj) {
    if (obj->hitFlags & 0x80000) {
        obj->unk18 = lbl_80270168[obj->kind][2];
        obj->unk10 = 2;
        obj->unk13 = 0;
        obj->state = 0;
        obj->step = 0;
        return TRUE;
    }
    return FALSE;
}

void fn_8007AAFC(Unk8007AAFC* obj) {
    if (lbl_803051D8.unk2 & 0x20) {
        obj->flagsA &= ~1;
        obj->flagsA &= 0xFD;
        fn_800E9244(obj);
        SetMode(obj, 3);
        return;
    }
    if (CheckHit(obj)) {
        fn_800E9244(obj);
        obj->flagsA &= ~1;
        SetMode(obj, 4);
    } else {
        lbl_8026FF98[obj->state](obj);
    }
}
