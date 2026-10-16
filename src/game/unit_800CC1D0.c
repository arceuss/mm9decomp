#include "types.h"

typedef struct Unk800CC1D0 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 kind;
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x10 - 0xB];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15[0x18 - 0x15];
    /* 0x18 */ void* unk18;
    /* 0x1C */ u8 pad1C[0x60 - 0x1C];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0xAC - 0x68];
    /* 0xAC */ void (*unkAC)(struct Unk800CC1D0* obj);
    /* 0xB0 */ u8 padB0[0xC9 - 0xB0];
    /* 0xC9 */ u8 unkC9;
    /* 0xCA */ u16 unkCA;
    /* 0xCC */ u8 padCC[0xD4 - 0xCC];
    /* 0xD4 */ s32 homeY;
} Unk800CC1D0;

typedef struct Unk803051D8 {
    /* 0x00 */ u8 pad0[0x2];
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 pad3[0x38 - 0x3];
} Unk803051D8;

extern Unk803051D8 lbl_803051D8;
extern void** lbl_80280390[];
extern u8 lbl_804ED000[4];
extern void (*lbl_804ECFF0[2])(Unk800CC1D0* obj);

void fn_800E9424(Unk800CC1D0* obj, u16 id);
void fn_800E91F0(Unk800CC1D0* obj, void* data, s32 arg2);
void fn_800E9244(Unk800CC1D0* obj);
void fn_800CC1CC(Unk800CC1D0* obj);
s32 fn_800A37F4(s32 x, s32 y);
s32 fn_800A44BC(s32 x, s32 y);
void fn_800CC120(Unk800CC1D0* obj);

static inline void SetMode(Unk800CC1D0* obj, u8 mode) {
    obj->unk18 = lbl_80280390[obj->kind][mode];
    obj->unk10 = mode;
    obj->state = 0;
    obj->step = 0;
    obj->unk13 = 0;
}

static inline void SetModeState(Unk800CC1D0* obj, u8 mode, u8 state) {
    obj->unk18 = lbl_80280390[obj->kind][mode];
    obj->unk10 = mode;
    obj->step = 0;
    obj->unk13 = 0;
    obj->state = state;
}

void fn_800CC1D0(Unk800CC1D0* obj) {
    s32 d;

    SetModeState(obj, 1, lbl_804ED000[obj->unk14]);
    obj->flagsA |= 3;
    fn_800E9424(obj, 0x1B);
    fn_800E91F0(obj, NULL, 0);
    obj->unkAC = fn_800CC1CC;
    if (obj->unk14 == 0) {
        d = fn_800A37F4(obj->x, obj->y - 0x600);
        if (d > 0) {
            obj->y += d;
        } else {
            d = fn_800A44BC(obj->x, obj->y - 0x600);
            if (d != 0 && d != 0x7FFFFFFF && d != -1) {
                obj->y = d + 0x600;
            }
        }
        fn_800CC120(obj);
    }
    obj->unkCA = 0x4000;
    obj->homeY = obj->y;
    obj->unkC9 = 0;
    if (lbl_803051D8.unk2 & 0x20) {
        obj->flagsA &= ~1;
        obj->flagsA &= 0xFD;
        fn_800E9244(obj);
        SetMode(obj, 3);
        return;
    }
    lbl_804ECFF0[obj->state](obj);
}
