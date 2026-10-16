#include "types.h"
#include "game/work_8031BF70.h"

typedef struct Unk800484D8 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x12 - 0xB];
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x16 - 0x13];
    /* 0x16 */ u8 timer;
    /* 0x17 */ u8 pad17[0x60 - 0x17];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ s32 vx;
    /* 0x6C */ s32 vy;
    /* 0x70 */ s32 ax;
    /* 0x74 */ s32 ay;
    /* 0x78 */ u8 pad78[0x7C - 0x78];
    /* 0x7C */ u8 unk7C;
    /* 0x7D */ u8 pad7D[0x88 - 0x7D];
    /* 0x88 */ u8 unk88[0x10];
} Unk800484D8;

extern Unk800484D8* lbl_804EE984;
extern u8 lbl_802656B0[];

void fn_800E946C(Unk800484D8* obj, u8 anim);
void fn_80040AD0(s32 arg0, s32* pos, s32 arg2, s32 arg3);
void fn_800D5234(s32 se);
void fn_8009996C(void* arg0, void* arg1);
s32 fn_8009E894(s32 x, s32 y);
void fn_800E9750(Unk800484D8* obj, u16 arg1);
void fn_80042D30(Unk800484D8* obj);

void fn_800484D8(Unk800484D8* obj) {
    s32 n;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 1);
        obj->vx = 0;
        obj->vy = 0;
        obj->ax = 0x10;
        obj->ay = 0x10;
        obj->timer = 0xB4;
        obj->step++;
    case 1:
        if (--obj->timer < 0x3C && obj->unk7C != 2) {
            fn_800E946C(obj, 2);
        }
        if (obj->timer == 0) {
            fn_80040AD0(3, &obj->x, 0, 0);
            fn_800D5234(0x13);
            obj->flagsA &= ~1;
            fn_8009996C(obj->unk88, lbl_802656B0);
            obj->step++;
        }
        n = obj->x + obj->vx;
        if ((fn_8009E894(n, obj->y) & 0x8000) || obj->y > lbl_8031BF70.unk4AEB8) {
            obj->x = n;
        } else {
            obj->vx = 0;
        }
        n = obj->y + obj->vy;
        if ((fn_8009E894(obj->x, n) & 0x8000) || n > lbl_8031BF70.unk4AEB8) {
            obj->y = n;
        } else {
            obj->vy = 0;
        }
        obj->vx += obj->ax * (((lbl_804EE984->x - obj->x) >> 31) * 2 + 1);
        obj->vy += obj->ay * (((lbl_804EE984->y - 0x1000 - obj->y) >> 31) * 2 + 1);
        if (__abs(obj->vx) > 0x180) {
            obj->vx = (((lbl_804EE984->x - obj->x) >> 31) * 2 + 1) * 0x180;
        }
        if (__abs(obj->vy) > 0x180) {
            obj->vy = (((lbl_804EE984->y - 0x1000 - obj->y) >> 31) * 2 + 1) * 0x180;
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    case 2:
        obj->timer = 0xC;
        obj->step++;
    case 3:
        if (--obj->timer == 0) {
            fn_80042D30(obj);
        }
        break;
    }
}
