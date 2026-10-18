#include "types.h"

typedef struct Unk800CCBB4 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 kind;
    /* 0x0A */ u8 unkA;
    /* 0x0B */ u8 unkB;
    /* 0x0C */ u8 padC[0x10 - 0xC];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 type;
    /* 0x15 */ u8 pad15;
    /* 0x16 */ u8 timer;
    /* 0x17 */ u8 pad17;
    /* 0x18 */ u32 unk18;
    /* 0x1C */ u8 pad1C[0x20 - 0x1C];
    /* 0x20 */ u8 unk20;
    /* 0x21 */ u8 unk21;
    /* 0x22 */ u8 pad22[0x50 - 0x22];
    /* 0x50 */ u32 unk50;
    /* 0x54 */ u32 unk54;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0xAC - 0x68];
    /* 0xAC */ void (*hit)(struct Unk800CCBB4* obj);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ u8 unkC8;
    /* 0xC9 */ u8 padC9[0xCC - 0xC9];
    /* 0xCC */ s32 unkCC;
    /* 0xD0 */ s32 unkD0;
} Unk800CCBB4;

extern u32* lbl_80280390[];
extern u8 lbl_8027FAAC[];
extern u8 lbl_803051D8[];
extern void (*lbl_8027F8CC[])(Unk800CCBB4* obj);

void fn_800E91F0(Unk800CCBB4* obj, s32 a, s32 b);
void fn_800CCB04(Unk800CCBB4* obj);
void fn_800E9424(Unk800CCBB4* obj, s32 id);
void fn_800E946C(Unk800CCBB4* obj, u8 id);
void fn_800E9AA0(Unk800CCBB4* obj, s32 a, s32 b);
void fn_800E9244(Unk800CCBB4* obj);

static inline void SetState(Unk800CCBB4* obj, u8 n, u8 s) {
    obj->unk18 = lbl_80280390[obj->kind][n];
    obj->unk10 = n;
    obj->state = s;
    obj->step = 0;
    obj->unk13 = 0;
}

void fn_800CCBB4(Unk800CCBB4* obj) {
    SetState(obj, 1, lbl_8027FAAC[obj->type]);
    obj->unkA |= 3;
    fn_800E91F0(obj, 0, 0);
    obj->hit = fn_800CCB04;
    if (obj->state == 0) {
        fn_800E9424(obj, 0x1C);
        fn_800E946C(obj, 3);
        fn_800E9AA0(obj, 0, 0);
        obj->timer = 0x28;
        obj->y -= 0x400;
        obj->unkCC = 0;
        obj->unkD0 = 0;
        obj->step = 5;
    } else if (obj->state == 3) {
        fn_800E9424(obj, 0x64);
        fn_800E946C(obj, 3);
        fn_800E9AA0(obj, 0, 0);
        if (obj->type == 0 || obj->type == 9 || obj->type == 0xB) {
            obj->unkA &= ~0x10;
            obj->unk54 &= ~0x400;
            obj->x += (((obj->type == 1) << 1) - 1) << 10;
        } else {
            obj->unkA |= 0x10;
            obj->unk54 |= 0x400;
            obj->x += (((obj->type == 1) << 1) - 1) << 10;
        }
        obj->y -= 0x100;
        if (obj->type == 9) {
            obj->timer = 0x28;
        } else if (obj->type == 0xA) {
            obj->timer = 0x96;
        } else if (obj->type == 0xB) {
            obj->timer = 0xD2;
        } else {
            obj->timer = 0x28;
        }
        obj->unkCC = 0;
        obj->unkD0 = 0;
        obj->step = 5;
    } else if (obj->state == 1) {
        fn_800E9424(obj, 0x1C);
        obj->unk50 |= 3;
    } else if (obj->state == 4) {
        fn_800E9424(obj, 0x64);
        obj->unk50 |= 3;
    }
    obj->unk54 &= ~0x200;
    obj->unkC8 = 0;
    obj->unkB &= ~0x20;
    obj->unk21 = obj->unk20;
    if (lbl_803051D8[2] & 0x20) {
        obj->unkA &= ~1;
        obj->unkA &= ~2;
        fn_800E9244(obj);
        SetState(obj, 3, 0);
        return;
    }
    lbl_8027F8CC[obj->state](obj);
}
