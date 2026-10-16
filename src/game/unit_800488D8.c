#include "types.h"
#include "game/work_8031BF70.h"

typedef struct Unk800488D8 {
    /* 0x00 */ u8 pad0[0x11];
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x16 - 0x13];
    /* 0x16 */ u8 timer;
    /* 0x17 */ u8 unk17;
    /* 0x18 */ u8 pad18[0x60 - 0x18];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ s32 vx;
    /* 0x6C */ s32 vy;
    /* 0x70 */ s32 ax;
    /* 0x74 */ s32 ay;
    /* 0x78 */ u8 pad78[0x7C - 0x78];
    /* 0x7C */ u8 unk7C;
    /* 0x7D */ u8 pad7D[0xAC - 0x7D];
    /* 0xAC */ void (*unkAC)(struct Unk800488D8*);
    /* 0xB0 */ u8 padB0[0xD0 - 0xB0];
    /* 0xD0 */ s32 unkD0;
} Unk800488D8;

extern Unk800488D8* lbl_804EE984;
extern u8 lbl_80265680[];

s32 fn_8009E894(s32 x, s32 y);
void fn_800E946C(Unk800488D8* obj, u8 anim);
void fn_800E91F0(Unk800488D8* obj, void* data, s32 arg2);
void fn_8004806C(Unk800488D8* obj);
void fn_800E9750(Unk800488D8* obj, u16 arg1);

void fn_800488D8(Unk800488D8* obj) {
    s32 ny;
    s16 tile;

    switch (obj->step) {
    case 0:
        obj->ay = -0x20;
        obj->vy = 0;
        obj->step++;
    case 1:
        ny = obj->y + obj->vy;
        tile = fn_8009E894(obj->x, ny);
        if (obj->unk7C == 0 && __abs(lbl_804EE984->x - obj->x) < 0x2000 &&
            __abs(lbl_804EE984->y - 0x1000 - obj->y) < 0x2000) {
            fn_800E946C(obj, 1);
            obj->timer = 8;
        }
        if ((tile & 0x8000) || ny > lbl_8031BF70.unk4AEB8) {
            obj->y = ny;
        } else {
            if (obj->unk7C == 0) {
                obj->state = 0;
                obj->step = 1;
                obj->vy = 0xC000;
                obj->ay = 0x100;
                obj->unkD0 = obj->y + 0x7FF;
            } else if (obj->unk17 == 0) {
                obj->state = 0;
                obj->step = 3;
                obj->vy = 0xC000;
                obj->ay = 0x100;
                obj->unkD0 = obj->y + 0x7FF;
            } else {
                obj->vx = 0;
                obj->vy = 0;
                obj->ax = 0x10;
                obj->ay = 0x10;
                obj->state = 1;
                obj->step = 1;
            }
            fn_800E91F0(obj, lbl_80265680, 1);
            obj->unkAC = fn_8004806C;
            fn_800E9750(obj, 0xFFFF);
            break;
        }
        obj->vy += obj->ay;
        if (obj->vy < -0x700) {
            obj->vy = -0x700;
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    }
}
