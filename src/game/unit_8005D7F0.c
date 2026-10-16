#include "types.h"

typedef struct Unk8005D7F0Pos {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Unk8005D7F0Pos;

typedef struct Unk8005D7F0 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x11 - 0xB];
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x16 - 0x13];
    /* 0x16 */ u8 timer;
    /* 0x17 */ u8 pad17[0x60 - 0x17];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0x7D - 0x68];
    /* 0x7D */ u8 unk7D;
    /* 0x7E */ u8 pad7E[0x88 - 0x7E];
    /* 0x88 */ u8 unk88[0x10];
} Unk8005D7F0;

extern u8 lbl_802670E0[];
extern u8 lbl_80267158[];
extern Unk8005D7F0* lbl_804EE984;

void fn_800E946C(Unk8005D7F0* obj, u8 anim);
void fn_800E9750(Unk8005D7F0* obj, u16 arg1);
void fn_8009996C(void* arg0, void* arg1);
void fn_8007921C(Unk8005D7F0Pos* pos);

void fn_8005D7F0(Unk8005D7F0* obj) {
    Unk8005D7F0Pos pos;
    s32 px;
    u8 flip;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 7);
        obj->timer = 0x1E;
        obj->step++;
    case 1:
        fn_800E9750(obj, 0xFFFF);
        if (--obj->timer == 0) {
            obj->step++;
        }
        break;
    case 2:
        fn_800E946C(obj, 3);
        obj->timer = 0x28;
        obj->step++;
    case 3:
        fn_800E9750(obj, 0xFFFF);
        if (obj->unk7D == 1) {
            fn_8009996C(obj->unk88, lbl_802670E0);
        } else if (obj->unk7D >= 2) {
            fn_8009996C(obj->unk88, lbl_80267158);
        }
        if (--obj->timer == 0) {
            obj->step++;
        }
        break;
    case 4:
        fn_800E946C(obj, 5);
        fn_8009996C(obj->unk88, lbl_80267158);
        obj->timer = 0x3C;
        obj->step++;
    case 5:
        fn_800E9750(obj, 0xFFFF);
        flip = obj->flagsA & 0x10;
        if (!flip) {
            px = lbl_804EE984->x;
            if (obj->x < px) {
                obj->state = 5;
                obj->step = 0;
                break;
            }
        } else {
            px = lbl_804EE984->x;
            if (obj->x > px) {
                obj->state = 5;
                obj->step = 0;
                break;
            }
        }
        if (obj->timer == 0) {
            if (!flip) {
                if (obj->x > px) {
                    obj->step++;
                }
            } else if (obj->x < px) {
                obj->step++;
            }
        } else {
            obj->timer--;
        }
        break;
    case 6:
        fn_800E946C(obj, 6);
        obj->timer = 0x10;
        pos.x = obj->x + ((((obj->flagsA >> 3) & 2) - 1) << 10);
        pos.y = obj->y - 0x1E00;
        fn_8007921C(&pos);
        obj->step++;
    case 7:
        fn_800E9750(obj, 0xFFFF);
        if (--obj->timer == 0) {
            obj->step = 4;
        }
        break;
    }
}
