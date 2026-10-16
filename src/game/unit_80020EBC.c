#include "types.h"

typedef struct Unk80020EBC {
    /* 0x00 */ u8 pad0[0x11];
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x16 - 0x13];
    /* 0x16 */ u8 timer;
    /* 0x17 */ u8 pad17[0x60 - 0x17];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ s32 vx;
    /* 0x6C */ s32 vy;
    /* 0x70 */ u8 pad70[0xD8 - 0x70];
    /* 0xD8 */ u8 lastPick;
    /* 0xD9 */ u8 repeat;
} Unk80020EBC;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x25C];
    /* 0x25C */ s32 unk25C;
    /* 0x260 */ u8 pad260[0x300 - 0x260];
} Unk80304B90;

extern Unk80304B90 lbl_80304B90;
extern u32 lbl_804EE988;
extern u32 lbl_804EC7F0[2];

void fn_800E946C(Unk80020EBC* obj, u8 anim);
s32 fn_800A4098(s32 x, s32 y);
void fn_800E9750(Unk80020EBC* obj, u16 arg1);

void fn_80020EBC(Unk80020EBC* obj) {
    s32 y;
    u32 rnd;
    u8 v;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 3);
        obj->vy = -0x100;
        obj->step++;
    case 1:
        y = obj->y + obj->vy;
        obj->y = y;
        if (y < fn_800A4098(obj->x, y) - 0x1800) {
            obj->y = fn_800A4098(obj->x, y) - 0x1800;
            obj->step++;
        }
        break;
    case 2:
        obj->vx = 0x180;
        obj->timer = 0x3C;
        obj->step++;
    case 3:
        obj->x += obj->vx;
        if (obj->timer == 0) {
            obj->step++;
        } else {
            obj->timer--;
        }
        break;
    case 4:
        obj->vx = -0x280;
        obj->timer = 0x1E;
        obj->step++;
    case 5:
        if (obj->timer == 0) {
            obj->x += obj->vx;
            if (obj->x < lbl_80304B90.unk25C - 0x1A00) {
                obj->x = lbl_80304B90.unk25C - 0x1A00;
                obj->step++;
            }
        } else {
            obj->timer--;
        }
        break;
    case 6:
        obj->timer = 0x5A;
        obj->step++;
    case 7:
        if (obj->timer == 0) {
            rnd = lbl_804EE988 * 0x343FD + 0x269EC3;
            lbl_804EE988 = rnd & 0x7FFFFFFF;
            v = lbl_804EC7F0[(rnd >> 16) & 1];
            if (v == obj->lastPick) {
                if (++obj->repeat == 2) {
                    while (v == obj->lastPick) {
                        rnd = lbl_804EE988 * 0x343FD + 0x269EC3;
                        lbl_804EE988 = rnd & 0x7FFFFFFF;
                        v = lbl_804EC7F0[(rnd >> 16) & 1];
                    }
                    obj->repeat = 0;
                }
            } else {
                obj->repeat = 0;
            }
            obj->state = v;
            obj->step = 0;
            obj->lastPick = v;
        } else {
            obj->timer--;
        }
        break;
    }
    fn_800E9750(obj, 0xFFFF);
}
