#include "types.h"

typedef struct Vec2i {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Vec2i;

typedef struct Unk8005A7D4 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x12 - 0xB];
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x54 - 0x13];
    /* 0x54 */ struct {
        u32 hi : 21;
        u32 flip : 1;
        u32 low : 10;
    } bits54;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ s32 vx;
    /* 0x6C */ s32 vy;
    /* 0x70 */ u8 pad70[0x74 - 0x70];
    /* 0x74 */ s32 gravity;
    /* 0x78 */ u8 pad78[0x88 - 0x78];
    /* 0x88 */ u8 unk88[1];
} Unk8005A7D4;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x21C];
    /* 0x21C */ u8 unk21C[1];
} Unk80304B90;

extern Unk80304B90 lbl_80304B90;

void fn_800E946C(Unk8005A7D4* obj, s32 anim);
void fn_8009996C(void* arg0, s32 arg1);
void fn_800E9750(Unk8005A7D4* obj, u16 arg1);
s32 fn_800A3FAC(s32 x, s32 y);
s32 fn_800A3CD4(s32 x, s32 y);
s32 fn_800A36F8(s32 x, s32 y);
void fn_80040AD0(s32 arg0, Vec2i* pos, s32 arg2, s32 arg3);
void fn_80042CF8(Unk8005A7D4* obj, s32 arg1);
u32 fn_80080484(void* cam, s32* pos, s32 arg2);
void fn_80042D30(Unk8005A7D4* obj);

void fn_8005A7D4(Unk8005A7D4* obj) {
    Vec2i pos;
    u32 f;
    BOOL hit;
    s32 d;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 1);
        obj->vy = 0;
        obj->gravity = 0x40;
        fn_8009996C(obj->unk88, 0);
        f = obj->vx > 0;
        if (f) {
            obj->flagsA |= 0x10;
        } else {
            obj->flagsA &= 0xEF;
        }
        obj->bits54.flip = f;
        obj->step++;
    case 1:
        hit = FALSE;
        fn_800E9750(obj, 0xFFFF);
        obj->x += obj->vx;
        if (obj->vx < 0) {
            if (fn_800A3FAC(obj->x - 0xE00, obj->y) > 0) {
                hit = TRUE;
            }
        } else if (fn_800A3CD4(obj->x + 0xE00, obj->y) < 0) {
            hit = TRUE;
        }
        obj->y += obj->vy;
        obj->vy += obj->gravity;
        d = fn_800A36F8(obj->x, obj->y);
        if (d < 0) {
            obj->vy = 0;
            obj->y += d;
        }
        if (hit) {
            pos.x = obj->x;
            pos.y = obj->y;
            fn_80040AD0(2, &pos, 0, 0);
            fn_80042CF8(obj, 4);
        } else if (fn_80080484(lbl_80304B90.unk21C, &obj->x, 1) > 0x1400) {
            fn_80042D30(obj);
        }
        break;
    }
}
