#include "types.h"

typedef struct Unk80050A80 {
    /* 0x00 */ u8 pad0[0x11];
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x16 - 0x13];
    /* 0x16 */ u8 timer;
    /* 0x17 */ u8 pad17[0x60 - 0x17];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0x6C - 0x68];
    /* 0x6C */ s32 vy;
    /* 0x70 */ u8 pad70[0x74 - 0x70];
    /* 0x74 */ s32 ay;
    /* 0x78 */ u8 pad78[0x84 - 0x78];
    /* 0x84 */ s32 lastY;
    /* 0x88 */ u8 unk88[0xCC - 0x88];
    /* 0xCC */ u8 unkCC;
    /* 0xCD */ u8 unkCD;
} Unk80050A80;

extern u8 lbl_802661A8[];
extern u32 lbl_804EE988;

void fn_800E946C(Unk80050A80* obj, u8 anim);
void fn_800E9750(Unk80050A80* obj, u16 arg1);
void fn_80042A70(s32 x, s32 y, s32 arg2, s32 arg3);
s32 fn_800A36F8(s32 x, s32 y);
void fn_800D5234(s32 se);
void fn_8009996C(void* arg0, void* arg1);

void fn_80050A80(Unk80050A80* obj) {
    u8 hit;
    s32 d;
    u32 rnd;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 2);
        obj->vy = 0;
        obj->ay = 0x40;
        obj->lastY = obj->y;
        obj->step++;
    case 1:
        hit = 0;
        fn_800E9750(obj, 0xFFFF);
        if (obj->y - obj->lastY >= 0x700) {
            fn_80042A70(obj->x, obj->y - 0x700, 0, 0);
            obj->lastY = obj->y;
        }
        obj->y += obj->vy;
        obj->vy += obj->ay;
        d = fn_800A36F8(obj->x, obj->y);
        if (d < 0) {
            obj->y += d;
            hit = 1;
        }
        d = fn_800A36F8(obj->x - 0xE00, obj->y);
        if (d < 0) {
            obj->y += d;
            hit++;
        }
        d = fn_800A36F8(obj->x + 0xE00, obj->y);
        if (d < 0) {
            obj->y += d;
            hit++;
        }
        if (hit != 0) {
            obj->step++;
        }
        break;
    case 2:
        fn_800E946C(obj, 3);
        fn_800D5234(0x41);
        obj->timer = 0x14;
        fn_8009996C(obj->unk88, lbl_802661A8);
        obj->step++;
    case 3:
        fn_800E9750(obj, 0xFFFF);
        if (--obj->timer == 0) {
            obj->state = 4;
            obj->step = 0;
            rnd = lbl_804EE988 * 0x343FD + 0x269EC3;
            lbl_804EE988 = rnd & 0x7FFFFFFF;
            obj->unkCC = (rnd >> 16) & 1;
            obj->unkCD = obj->unkCC;
        }
        break;
    }
}
