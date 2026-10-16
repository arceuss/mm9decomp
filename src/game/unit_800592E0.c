#include "types.h"

typedef struct Unk800592E0 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x12 - 0xB];
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x54 - 0x13];
    /* 0x54 */ u32 unk54;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ s32 vx;
    /* 0x6C */ s32 range;
    /* 0x70 */ s32 ax;
    /* 0x74 */ s32 baseX;
    /* 0x78 */ u8 pad78[0x88 - 0x78];
    /* 0x88 */ u8 unk88[0x10];
} Unk800592E0;

extern u8 lbl_80266BC0[];

void fn_800E946C(Unk800592E0* obj, s32 arg1);
void fn_8009996C(void* arg0, void* arg1);
void fn_800E9750(Unk800592E0* obj, u16 arg1);

void fn_800592E0(Unk800592E0* obj) {
    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 0);
        fn_8009996C(obj->unk88, lbl_80266BC0);
        obj->step++;
    case 1:
        fn_800E9750(obj, 0xFFFF);
        obj->x += obj->vx;
        obj->vx += obj->ax;
        if (obj->vx <= 0) {
            obj->flagsA &= 0xEF;
            obj->unk54 &= ~0x400;
            if (obj->vx < -0x180) {
                obj->vx = -0x180;
            }
        } else {
            obj->flagsA |= 0x10;
            obj->unk54 |= 0x400;
            if (obj->vx > 0x180) {
                obj->vx = 0x180;
            }
        }
        if (obj->ax < 0) {
            if (obj->x > obj->baseX + obj->range && obj->vx <= 0) {
                obj->ax = -0x20;
            }
            if (obj->x < obj->baseX - obj->range) {
                obj->ax = 0x40;
            }
        } else {
            if (obj->x < obj->baseX - obj->range && obj->vx >= 0) {
                obj->ax = 0x20;
            }
            if (obj->x > obj->baseX + obj->range) {
                obj->ax = -0x40;
            }
        }
        break;
    }
}
