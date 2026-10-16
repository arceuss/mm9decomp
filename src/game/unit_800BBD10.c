#include "types.h"

typedef struct Unk8027EE40 {
    /* 0x0 */ u16 sprite;
    /* 0x2 */ u16 unk2;
} Unk8027EE40;

typedef struct Unk800BBD10 {
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
    /* 0x15 */ u8 variant;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17;
    /* 0x18 */ void* unk18;
    /* 0x1C */ u8 pad1C[0xC8 - 0x1C];
    /* 0xC8 */ u8 unkC8;
} Unk800BBD10;

extern Unk8027EE40 lbl_8027EE40[4];
extern u8 lbl_804ECEB8[4][2];
extern void (*lbl_804ECEA8)(Unk800BBD10* obj);
extern void (*lbl_804ECEAC[1])(Unk800BBD10* obj);
extern void (*lbl_804ECEB0[1])(Unk800BBD10* obj);
extern void** lbl_8027F228[];

void fn_800E9810(Unk800BBD10* obj, u16 id);
void fn_800E9A84(Unk800BBD10* obj, u16 id);
void fn_800E9424(Unk800BBD10* obj, u16 id);
void fn_800E946C(Unk800BBD10* obj, u8 anim);
BOOL fn_800BC214(Unk800BBD10* obj);

void fn_800BBD10(Unk800BBD10* obj) {
    u32 v = obj->variant;
    u16 spr;

    obj->unkC8 = 0;
    spr = lbl_8027EE40[v].sprite;
    if (spr == 0x100) {
        fn_800E9810(obj, 0x141);
    } else {
        obj->flagsB &= 0xFB;
    }
    fn_800E9A84(obj, 0x144);
    fn_800E9424(obj, spr);
    obj->unk16 = 0;
    fn_800E946C(obj, lbl_804ECEB8[v][0]);
    obj->flagsA |= 3;
    lbl_804ECEA8(obj);
    obj->unk18 = lbl_8027F228[obj->kind][1];
    obj->unk10 = 1;
    obj->step = 0;
    obj->unk13 = 0;
    obj->state = 0;
    if (obj->unk14 <= 1) {
        obj->step = 2;
    }
    if (!fn_800BC214(obj)) {
        lbl_804ECEAC[obj->state](obj);
        lbl_804ECEB0[obj->state](obj);
    }
}
