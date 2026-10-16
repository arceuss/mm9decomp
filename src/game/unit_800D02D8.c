#include "types.h"

typedef struct Unk800D02D8 {
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
    /* 0x15 */ u8 pad15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 unk17;
    /* 0x18 */ void* unk18;
    /* 0x1C */ u8 pad1C[0x30 - 0x1C];
    /* 0x30 */ u16 unk30;
    /* 0x32 */ u8 pad32[0x3C - 0x32];
    /* 0x3C */ void* unk3C;
    /* 0x40 */ u8 pad40[0x60 - 0x40];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0xCC - 0x68];
    /* 0xCC */ s32 homeX;
    /* 0xD0 */ u32 unkD0;
} Unk800D02D8;

typedef struct Unk803051D8 {
    /* 0x00 */ u8 pad0[0x2];
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 pad3[0x38 - 0x3];
} Unk803051D8;

extern Unk803051D8 lbl_803051D8;
extern void** lbl_80280390[];
extern u8 lbl_804ED0B0[8];
extern void (*lbl_804ED0A8[2])(Unk800D02D8* obj);

void fn_800E9424(Unk800D02D8* obj, u16 id);
void fn_800E946C(Unk800D02D8* obj, u8 anim);
void fn_800E9244(Unk800D02D8* obj);
void fn_800D066C(Unk800D02D8* obj);

static inline void SetMode(Unk800D02D8* obj, u8 mode) {
    obj->unk18 = lbl_80280390[obj->kind][mode];
    obj->unk10 = mode;
    obj->state = 0;
    obj->step = 0;
    obj->unk13 = 0;
}

void fn_800D02D8(Unk800D02D8* obj) {
    fn_800E9424(obj, 0x2C);
    fn_800E946C(obj, 0);
    obj->flagsA |= 1;
    fn_800E9244(obj);
    obj->flagsB |= 0x10;
    obj->unk3C = lbl_804ED0B0;
    obj->unk30 = 0x2004;
    obj->unk18 = lbl_80280390[obj->kind][1];
    obj->unk10 = 1;
    obj->unk13 = 0;
    obj->state = 0;
    obj->step = 0;
    obj->unk16 = 0;
    obj->unk17 = 0;
    obj->unkD0 = obj->unk14 & 0xF0;
    if ((s32)((obj->unk14 >> 4) & 0xF) % 2 != 0) {
        obj->x -= 0x800;
    }
    obj->homeX = obj->x;
    fn_800D066C(obj);
    obj->y -= 0x800;
    if (lbl_803051D8.unk2 & 0x20) {
        obj->flagsA &= ~1;
        obj->flagsA &= 0xFD;
        fn_800E9244(obj);
        SetMode(obj, 3);
        return;
    }
    lbl_804ED0A8[obj->state](obj);
}
