#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk800D2600 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 unk9;
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
    /* 0x1C */ u8 pad1C[0x20 - 0x1C];
    /* 0x20 */ u8 unk20;
    /* 0x21 */ u8 unk21;
    /* 0x22 */ u8 pad22[0x30 - 0x22];
    /* 0x30 */ u16 unk30;
    /* 0x32 */ u8 pad32[0x3C - 0x32];
    /* 0x3C */ void* unk3C;
    /* 0x40 */ u8 pad40[0x64 - 0x40];
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0x6C - 0x68];
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ u8 pad70[0x74 - 0x70];
    /* 0x74 */ s32 unk74;
    /* 0x78 */ u8 pad78[0xAC - 0x78];
    /* 0xAC */ void (*unkAC)(struct Unk800D2600*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ u8 unkC8;
    /* 0xC9 */ u8 unkC9;
    /* 0xCA */ u8 padCA[0xCC - 0xCA];
    /* 0xCC */ s32 unkCC;
    /* 0xD0 */ s32 unkD0;
} Unk800D2600;

typedef struct Unk803051D8 {
    /* 0x00 */ u8 pad0[0x2];
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 pad3[0x38 - 0x3];
} Unk803051D8;

extern Unk80280390Entry* lbl_80280390[];
extern u8 lbl_80280298[];
extern void (*lbl_80280288[4])(Unk800D2600* obj);
extern u8 lbl_804ED2D8[8];
extern Unk803051D8 lbl_803051D8;

void fn_800E9424(Unk800D2600* obj, u16 anim);
void fn_800E91F0(Unk800D2600* obj, void* data, s32 arg2);
void fn_800E9244(Unk800D2600* obj);
void fn_800D2884(Unk800D2600* obj);

void fn_800D2600(Unk800D2600* obj) {
    fn_800E9424(obj, 0x36);
    obj->flagsA |= 1;
    fn_800E91F0(obj, lbl_80280298, 0);
    obj->unkAC = fn_800D2884;
    obj->unk3C = lbl_804ED2D8;
    obj->unk30 = 0x2001;
    obj->flagsB |= 0x10;
    obj->flagsB &= 0xDF;
    obj->unk21 = obj->unk20;
    obj->unk18 = lbl_80280390[obj->unk9]->unk4;
    obj->unk10 = 1;
    obj->unk13 = 0;
    obj->state = 0;
    obj->step = 0;
    obj->unk6C = 0;
    obj->unkC8 = 0;
    obj->unkC9 = 0xC;
    obj->unk64 += 0x800;
    obj->unk74 = obj->unk64;
    obj->unkCC = obj->unk64;
    obj->unkD0 = (obj->unk14 << 12) + 0x3000;
    if (lbl_803051D8.unk2 & 0x20) {
        obj->flagsA &= ~1;
        obj->flagsA &= 0xFD;
        fn_800E9244(obj);
        obj->unk18 = lbl_80280390[obj->unk9]->unkC;
        obj->unk10 = 3;
        obj->state = 0;
        obj->step = 0;
        obj->unk13 = 0;
    } else {
        lbl_80280288[0](obj);
    }
}
