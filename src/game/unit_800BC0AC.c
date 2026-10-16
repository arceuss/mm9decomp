#include "types.h"

typedef struct Unk8027EE40 {
    /* 0x0 */ u16 sprite;
    /* 0x2 */ u16 unk2;
} Unk8027EE40;

typedef struct Unk800BC0AC {
    /* 0x00 */ u8 pad0[0xB];
    /* 0x0B */ u8 flagsB;
    /* 0x0C */ u8 padC[0x12 - 0xC];
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x15 - 0x13];
    /* 0x15 */ u8 variant;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17[0x24 - 0x17];
    /* 0x24 */ u16 sprite;
    /* 0x26 */ u8 pad26[0x60 - 0x26];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ s32 vx;
    /* 0x6C */ s32 vy;
    /* 0x70 */ u8 pad70[0xCA - 0x70];
    /* 0xCA */ u8 timer;
} Unk800BC0AC;

extern Unk8027EE40 lbl_8027EE40[4];
extern u8 lbl_804ECEB8[4][2];

void fn_800E9810(Unk800BC0AC* obj, u16 id);
void fn_800E9A84(Unk800BC0AC* obj, u16 id);
void fn_800E9424(Unk800BC0AC* obj, u16 id);
void fn_800E946C(Unk800BC0AC* obj, u8 anim);
void fn_800E9750(Unk800BC0AC* obj, u16 arg1);

void fn_800BC0AC(Unk800BC0AC* obj) {
    u16 spr;
    u32 v;

    switch (obj->step) {
    case 0:
        obj->timer = 6;
        obj->step++;
    case 1:
        if (--obj->timer != 0) {
            break;
        }
        obj->step = 2;
    case 2:
        v = obj->variant;
        spr = lbl_8027EE40[v].sprite;
        if (spr == 0x100) {
            fn_800E9810(obj, 0x141);
        } else {
            obj->flagsB &= 0xFB;
        }
        fn_800E9A84(obj, 0x144);
        if (obj->sprite != spr) {
            fn_800E9424(obj, spr);
        }
        obj->unk16 = 1;
        fn_800E946C(obj, lbl_804ECEB8[v][1]);
        obj->step++;
    case 3:
        obj->x += obj->vx;
        obj->y += obj->vy;
        break;
    }
    fn_800E9750(obj, 0xFFFF);
}
