#include "types.h"

typedef struct Unk800AEF54Rect {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
} Unk800AEF54Rect;

typedef struct Unk800AEF54Pos {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Unk800AEF54Pos;

typedef struct Unk800AEF54 {
    /* 0x000 */ u8 pad0[0xA];
    /* 0x00A */ u8 flagsA;
    /* 0x00B */ u8 padB[0x12 - 0xB];
    /* 0x012 */ u8 step;
    /* 0x013 */ u8 unk13;
    /* 0x014 */ u8 pad14[0x60 - 0x14];
    /* 0x060 */ Unk800AEF54Pos pos;
    /* 0x068 */ u8 pad68[0xB6 - 0x68];
    /* 0x0B6 */ u16 unkB6;
    /* 0x0B8 */ u16 unkB8;
    /* 0x0BA */ u8 padBA[0xED - 0xBA];
    /* 0x0ED */ u8 prevStep;
    /* 0x0EE */ u8 prev13;
    /* 0x0EF */ u8 padEF[0x104 - 0xEF];
    /* 0x104 */ u32 unk104;
    /* 0x108 */ u8 timer;
    /* 0x109 */ u8 pad109[0x115 - 0x109];
    /* 0x115 */ u8 unk115;
    /* 0x116 */ u8 pad116[0x19C - 0x116];
    /* 0x19C */ Unk800AEF54Rect* rect;
} Unk800AEF54;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x125];
    /* 0x125 */ u8 unk125;
    /* 0x126 */ u8 pad126[0x2D8 - 0x126];
    /* 0x2D8 */ u32 unk2D8;
    /* 0x2DC */ u8 pad2DC[0x300 - 0x2DC];
} Unk80304B90;

typedef struct Unk8038DC58 {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ u8 unkC;
    /* 0x0D */ u8 padD[0x128 - 0xD];
} Unk8038DC58;

extern Unk80304B90 lbl_80304B90;
extern Unk8038DC58 lbl_8038DC58;
extern u8 lbl_804EE970;

void fn_800E9244(Unk800AEF54* obj);
void fn_80040D50(Unk800AEF54Pos* pos);
void fn_800D5564(s32 arg0);

static inline void SetStep(Unk800AEF54* obj, u8 step) {
    obj->prevStep = obj->step;
    obj->step = step;
    obj->prev13 = obj->unk13;
    obj->unk13 = 0;
}

void fn_800AEF54(Unk800AEF54* obj) {
    Unk800AEF54Pos pos;
    s32 t;

    switch (obj->step) {
    case 0:
        obj->unkB8 = 0;
        obj->unk104 = (obj->unk104 & ~1) | 2;
        obj->unkB6 = 0;
        fn_800E9244(obj);
        lbl_80304B90.unk2D8 |= 1;
        lbl_8038DC58.unkC |= 8;
        SetStep(obj, 1);
    case 1:
        if (lbl_804EE970 < 30) {
            break;
        }
        obj->flagsA &= ~1;
        obj->unk104 |= 8;
        if (!(obj->unk115 & 8)) {
            pos = obj->pos;
            pos.y -= obj->rect->y * (((obj->flagsA >> 4) & 2) - 1);
            fn_80040D50(&pos);
        } else {
            fn_800D5564(3);
        }
        obj->timer = 0xF0;
        SetStep(obj, 2);
    case 2:
        t = obj->timer - 1;
        obj->timer = t;
        if (t < 0) {
            SetStep(obj, 3);
            lbl_80304B90.unk125 |= 2;
        }
        break;
    }
}
