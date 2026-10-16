#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
} Unk80280390Entry;

typedef struct Unk800D07B0 {
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
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[0x30 - 0x1C];
    /* 0x30 */ u16 unk30;
    /* 0x32 */ u8 pad32[0x3C - 0x32];
    /* 0x3C */ void* unk3C;
    /* 0x40 */ u8 pad40[0x54 - 0x40];
    /* 0x54 */ u32 unk54_hi : 21;
    /* 0x54 */ u32 flipX : 1;
    /* 0x54 */ u32 unk54_lo : 10;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0xAC - 0x68];
    /* 0xAC */ void (*unkAC)(struct Unk800D07B0*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 baseX;
    /* 0xCC */ u8 unkCC;
    /* 0xCD */ u8 unkCD;
    /* 0xCE */ u8 padCE[0xD0 - 0xCE];
    /* 0xD0 */ s32 unkD0;
} Unk800D07B0;

typedef struct Unk803051D8 {
    /* 0x00 */ u8 pad0[0x2];
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 pad3[0x38 - 0x3];
} Unk803051D8;

extern Unk80280390Entry* lbl_80280390[];
extern u8 lbl_802800C0[];
extern u8 lbl_804ED0C0[8];
extern u8 lbl_804ED0B8[8];
extern void (*lbl_802800AC[])(Unk800D07B0* obj);
extern Unk803051D8 lbl_803051D8;

void fn_800E9424(Unk800D07B0* obj, u16 anim);
void fn_800E946C(Unk800D07B0* obj, s32 arg1);
void fn_800E91F0(Unk800D07B0* obj, void* data, s32 arg2);
void fn_800D0BEC(Unk800D07B0* obj);
void fn_800E9244(Unk800D07B0* obj);

static inline void SetBox(Unk800D07B0* obj, void* box) {
    obj->flagsB |= 0x10;
    obj->unk3C = box;
    obj->unk30 = 5;
}

void fn_800D07B0(Unk800D07B0* obj) {
    u32 flip;

    fn_800E9424(obj, 0x30);
    fn_800E946C(obj, 0);
    flip = (obj->unk14 & 0xF) != 0;
    if (flip) {
        obj->flagsA |= 0x10;
    } else {
        obj->flagsA &= 0xEF;
    }
    obj->flipX = flip;
    obj->unkCD = 0;
    obj->flagsA |= 1;
    fn_800E91F0(obj, lbl_802800C0, 0);
    obj->unkAC = fn_800D0BEC;
    if (obj->flagsA & 0x10) {
        SetBox(obj, lbl_804ED0C0);
    } else {
        SetBox(obj, lbl_804ED0B8);
    }
    obj->unk18 = lbl_80280390[obj->kind]->unk4;
    obj->unk10 = 1;
    obj->unk13 = 0;
    obj->state = 0;
    obj->step = 0;
    obj->x += (obj->unk14 & 0xF) ? 0x400 : -0x400;
    obj->unkD0 = obj->x;
    if ((obj->unk14 & 0xF) == 0) {
        obj->x -= 0x2000;
    } else {
        obj->x += 0x2000;
    }
    obj->baseX = obj->x;
    obj->y += 0x800;
    obj->unkCC = 0;
    if (lbl_803051D8.unk2 & 0x20) {
        obj->flagsA &= ~1;
        obj->flagsA &= 0xFD;
        fn_800E9244(obj);
        obj->unk18 = lbl_80280390[obj->kind]->unkC;
        obj->unk10 = 3;
        obj->state = 0;
        obj->step = 0;
        obj->unk13 = 0;
    } else {
        lbl_802800AC[obj->state](obj);
    }
}
