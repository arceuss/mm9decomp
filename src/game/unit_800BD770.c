#include "types.h"

typedef struct Unk800BD770Parent {
    /* 0x000 */ u8 pad0[0x10C];
    /* 0x10C */ u8 unk10C;
} Unk800BD770Parent;

typedef struct Unk800BD770 {
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
    /* 0x34 */ Unk800BD770Parent* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0xA0 - 0x68];
    /* 0xA0 */ u32 unkA0;
    /* 0xA4 */ u8 padA4[0xC9 - 0xA4];
    /* 0xC9 */ u8 unkC9;
    /* 0xCA */ u8 padCA[0xD1 - 0xCA];
    /* 0xD1 */ u8 unkD1;
} Unk800BD770;

typedef struct Unk803051D8 {
    /* 0x00 */ u8 pad0[0x2];
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 pad3[0x38 - 0x3];
} Unk803051D8;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x21C];
    /* 0x21C */ u8 unk21C[1];
} Unk80304B90;

extern Unk803051D8 lbl_803051D8;
extern Unk80304B90 lbl_80304B90;
extern void** lbl_8027F228[];

void fn_800E9244(Unk800BD770* obj);
void fn_800BD23C(Unk800BD770* obj);
u32 fn_80080484(void* cam, s32* pos, s32 arg2);
void fn_80040AD0(s32 a, s32* pos, s32 c, s32 d);

static inline void SetMode(Unk800BD770* obj, u8 mode) {
    obj->unk18 = lbl_8027F228[obj->kind][mode];
    obj->unk10 = mode;
    obj->state = 0;
    obj->step = 0;
    obj->unk13 = 0;
}

static inline void Finish(Unk800BD770* obj) {
    SetMode(obj, 2);
    fn_800BD23C(obj);
}

BOOL fn_800BD770(Unk800BD770* obj) {
    if (obj->unkC9 != obj->parent->unk10C) {
        obj->flagsA &= ~1;
        obj->flagsA &= 0xFD;
        fn_800E9244(obj);
        SetMode(obj, 3);
        return TRUE;
    }
    if (lbl_803051D8.unk2 & 0x20) {
        Finish(obj);
        return TRUE;
    }
    if (obj->unkA0 & 0x80000) {
        Finish(obj);
        return TRUE;
    }
    if (fn_80080484(lbl_80304B90.unk21C, &obj->x, 1) > 0x800) {
        Finish(obj);
        return TRUE;
    }
    if (obj->unkD1 != 0) {
        fn_80040AD0(2, &obj->x, 0, 0);
        Finish(obj);
        return TRUE;
    }
    return FALSE;
}
