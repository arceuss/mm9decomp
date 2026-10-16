#include "types.h"

typedef struct Unk8004666C {
    /* 0x00 */ u8 pad0[0x11];
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x16 - 0x13];
    /* 0x16 */ u8 flap;
    /* 0x17 */ u8 right;
    /* 0x18 */ u8 pad18[0x60 - 0x18];
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
} Unk8004666C;

extern Unk8004666C* lbl_804EE984;
extern void* lbl_80265590[4];

void fn_800E946C(Unk8004666C* obj, u8 anim);
void fn_8009996C(void* arg0, void* arg1);
s32 fn_800A36F8(s32 x, s32 y);
s32 fn_800A3FAC(s32 x, s32 y);
s32 fn_800A3CD4(s32 x, s32 y);
void fn_800E9750(Unk8004666C* obj, u16 arg1);

void fn_8004666C(Unk8004666C* obj) {
    s32 d;

    switch (obj->step) {
    case 0:
        if (((lbl_804EE984->x - obj->x) >> 31) * 2 + 1 < 0) {
            fn_800E946C(obj, 2);
            obj->right = 0;
        } else {
            fn_800E946C(obj, 0);
            obj->right = 1;
        }
        obj->vx = 0;
        obj->vy = 0;
        obj->ay = 0x30;
        obj->ax = obj->ay * (((lbl_804EE984->x - obj->x) >> 31) * 2 + 1);
        obj->flap = 0;
        obj->step++;
    case 1:
        obj->y += obj->vy;
        obj->vy += obj->ay;
        if (obj->ay < 0) {
            if (obj->vy < 0) {
                obj->vy = 0;
                obj->ay = 0x30;
                if (obj->right == 0) {
                    fn_800E946C(obj, 0);
                    obj->right = 1;
                } else {
                    fn_800E946C(obj, 2);
                    obj->right = 0;
                }
            }
        } else if (obj->vy > 0x340) {
            obj->vy = 0x340;
            obj->ay = -0x30;
            obj->flap = 1;
        }
        obj->x += obj->vy * ((obj->right == 1) * 2 - 1);
        if (obj->right == 0) {
            fn_800E946C(obj, 2);
        } else {
            fn_800E946C(obj, 0);
        }
        if (obj->vy < 0x180 && obj->flap != 0) {
            fn_800E946C(obj, 1);
            fn_8009996C(obj->unk88, lbl_80265590[obj->unk7C]);
        }
        if (obj->vy == 0) {
            obj->flap = 0;
        }
        d = fn_800A36F8(obj->x, obj->y + 0x400);
        if (d < 0) {
            obj->y += d;
            obj->state = 1;
            obj->step = 0;
        }
        if (obj->right == 0) {
            if (fn_800A3FAC(obj->x - 0x800, obj->y + 0x400) > 0) {
                obj->state = 1;
                obj->step = 0;
            }
        } else if (fn_800A3CD4(obj->x + 0x800, obj->y + 0x400) < 0) {
            obj->state = 1;
            obj->step = 0;
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    }
}
