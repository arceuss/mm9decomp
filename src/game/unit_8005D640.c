#include "types.h"

typedef struct Unk8005D640 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x11 - 0xB];
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x16 - 0x13];
    /* 0x16 */ u8 timer;
    /* 0x17 */ u8 blink;
    /* 0x18 */ u8 pad18[0x60 - 0x18];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ s32 vx;
    /* 0x6C */ u8 pad6C[0x74 - 0x6C];
    /* 0x74 */ s32 targetX;
    /* 0x78 */ u8 pad78[0x7D - 0x78];
    /* 0x7D */ u8 unk7D;
    /* 0x7E */ u8 pad7E[0xA0 - 0x7E];
    /* 0xA0 */ u32 hitFlags;
} Unk8005D640;

void fn_800E946C(Unk8005D640* obj, s32 arg1);
void fn_800E9758(Unk8005D640* obj);
void fn_800E9750(Unk8005D640* obj, u16 arg1);

void fn_8005D640(Unk8005D640* obj) {
    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 2);
        obj->vx = -((((obj->flagsA >> 3) & 2) - 1) << 6);
        obj->blink = 6;
        obj->step++;
    case 1:
        fn_800E9758(obj);
        if (obj->blink == 0) {
            obj->unk7D = obj->unk7D == 0;
            obj->blink = 6;
        } else {
            obj->blink--;
        }
        obj->x += obj->vx;
        if (obj->vx < 0) {
            if (obj->x < obj->targetX) {
                obj->x = obj->targetX;
                obj->step++;
                break;
            }
        } else if (obj->x > obj->targetX) {
            obj->x = obj->targetX;
            obj->step++;
            break;
        }
        if ((obj->hitFlags & 1) || (obj->hitFlags & 0x2000)) {
            obj->state = 0;
            obj->step = 2;
        }
        break;
    case 2:
        fn_800E946C(obj, 1);
        obj->timer = 0x3C;
        obj->step++;
    case 3:
        fn_800E9750(obj, 0xFFFF);
        if ((obj->hitFlags & 1) || (obj->hitFlags & 0x2000)) {
            obj->state = 0;
            obj->step = 2;
        }
        if (--obj->timer == 0) {
            obj->state = 0;
            obj->step = 0;
        }
        break;
    }
}
