#include "types.h"

typedef struct Unk800442AC {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x11 - 0xB];
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x60 - 0x13];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ s32 vx;
    /* 0x6C */ u8 pad6C[0x70 - 0x6C];
    /* 0x70 */ s32 homeX;
    /* 0x74 */ u8 pad74[0x88 - 0x74];
    /* 0x88 */ u8 unk88[0x10];
} Unk800442AC;

extern u8 lbl_802652B8[];

void fn_800E946C(Unk800442AC* obj, u8 anim);
void fn_8009996C(void* arg0, void* arg1);
s32 fn_800A3FAC(s32 x, s32 y);
s32 fn_800A3CD4(s32 x, s32 y);
void fn_800E9750(Unk800442AC* obj, u16 arg1);

void fn_800442AC(Unk800442AC* obj) {
    BOOL hit = FALSE;
    s32 d;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 0);
        fn_8009996C(obj->unk88, lbl_802652B8);
        obj->vx = 0x200;
        obj->vx *= ((obj->flagsA >> 3) & 2) - 1;
        obj->step++;
    case 1:
        obj->x += obj->vx;
        if (obj->vx < 0) {
            d = (obj->homeX - 0x4000) - obj->x;
            if (d > 0) {
                obj->x += d;
                hit = TRUE;
            }
            d = fn_800A3FAC(obj->x - 0x800, obj->y);
            if (d > 0) {
                obj->x += d;
                hit = TRUE;
            }
            d = fn_800A3FAC(obj->x - 0x800, obj->y - 0xF00);
            if (d > 0) {
                obj->x += d;
                hit = TRUE;
            }
            d = fn_800A3FAC(obj->x - 0x800, obj->y + 0xF00);
            if (d > 0) {
                obj->x += d;
                hit = TRUE;
            }
        } else {
            d = (obj->homeX + 0x4000) - obj->x;
            if (d < 0) {
                obj->x += d;
                hit = TRUE;
            }
            d = fn_800A3CD4(obj->x + 0x800, obj->y - 0xF00);
            if (d < 0) {
                obj->x += d;
                hit = TRUE;
            }
            d = fn_800A3CD4(obj->x + 0x800, obj->y + 0xF00);
            if (d < 0) {
                obj->x += d;
                hit = TRUE;
            }
            d = fn_800A3CD4(obj->x + 0x800, obj->y);
            if (d < 0) {
                obj->x += d;
                hit = TRUE;
            }
        }
        if (hit) {
            obj->state = 1;
            obj->step = 0;
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    }
}
