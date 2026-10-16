#include "types.h"

typedef struct Unk800CBA6C {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 kind;
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 flagsB;
    /* 0x0C */ u8 padC[0x10 - 0xC];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15[0x18 - 0x15];
    /* 0x18 */ void* unk18;
    /* 0x1C */ u8 pad1C[0x30 - 0x1C];
    /* 0x30 */ u16 unk30;
    /* 0x32 */ u8 pad32[0x3C - 0x32];
    /* 0x3C */ void* unk3C;
    /* 0x40 */ u8 pad40[0x60 - 0x40];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0xAC - 0x68];
    /* 0xAC */ void (*unkAC)(struct Unk800CBA6C* obj);
} Unk800CBA6C;

typedef struct Unk803051D8 {
    /* 0x00 */ u8 pad0[0x2];
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 pad3[0x38 - 0x3];
} Unk803051D8;

extern Unk803051D8 lbl_803051D8;
extern void** lbl_80280390[];
extern u8 lbl_804ECFE8[4];
extern u16 lbl_804ECFEC[2];
extern u8 lbl_804ECFE0[8];
extern void (*lbl_804ECFD8[2])(Unk800CBA6C* obj);

void fn_800E9424(Unk800CBA6C* obj, u16 id);
void fn_800E91F0(Unk800CBA6C* obj, void* data, s32 arg2);
void fn_800E9244(Unk800CBA6C* obj);
void fn_800CBA68(Unk800CBA6C* obj);

static inline void SetMode(Unk800CBA6C* obj, u8 mode) {
    obj->unk18 = lbl_80280390[obj->kind][mode];
    obj->unk10 = mode;
    obj->state = 0;
    obj->step = 0;
    obj->unk13 = 0;
}

static inline void SetModeState(Unk800CBA6C* obj, u8 mode, u8 state) {
    obj->unk18 = lbl_80280390[obj->kind][mode];
    obj->unk10 = mode;
    obj->step = 0;
    obj->unk13 = 0;
    obj->state = state;
}

void fn_800CBA6C(Unk800CBA6C* obj) {
    SetModeState(obj, 1, lbl_804ECFE8[obj->unk14]);
    obj->flagsA |= 3;
    fn_800E9424(obj, lbl_804ECFEC[obj->unk14]);
    fn_800E91F0(obj, NULL, 0);
    obj->unkAC = fn_800CBA68;
    obj->flagsB |= 0x10;
    obj->unk3C = lbl_804ECFE0;
    obj->unk30 = 0x2001;
    obj->y += 0x100;
    if (lbl_803051D8.unk2 & 0x20) {
        obj->flagsA &= ~1;
        obj->flagsA &= 0xFD;
        fn_800E9244(obj);
        SetMode(obj, 3);
        return;
    }
    lbl_804ECFD8[obj->state](obj);
}
