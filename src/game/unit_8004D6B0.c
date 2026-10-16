#include "types.h"

typedef struct Unk8004D6B0Pos {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Unk8004D6B0Pos;

typedef struct Unk8004D6B0 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x11 - 0xB];
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x16 - 0x13];
    /* 0x16 */ u8 timer;
    /* 0x17 */ u8 count;
    /* 0x18 */ u8 pad18[0x60 - 0x18];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0x88 - 0x68];
    /* 0x88 */ u8 unk88[0x10];
} Unk8004D6B0;

extern u8 lbl_80265F48[];

void fn_800E946C(Unk8004D6B0* obj, u8 anim);
void fn_8009996C(void* arg0, void* arg1);
void fn_800E9750(Unk8004D6B0* obj, u16 arg1);
void fn_80074AE4(Unk8004D6B0Pos* pos, s32 vx);

void fn_8004D6B0(Unk8004D6B0* obj) {
    Unk8004D6B0Pos pos;
    s32 dir;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 1);
        fn_8009996C(obj->unk88, lbl_80265F48);
        obj->timer = 0x18;
        obj->step++;
    case 1:
        fn_800E9750(obj, 0xFFFF);
        if (--obj->timer == 0) {
            obj->step++;
        }
        break;
    case 2:
        obj->timer = 8;
        obj->count = 7;
        obj->step++;
    case 3:
        fn_800E9750(obj, 0xFFFF);
        if (--obj->timer == 0) {
            dir = ((obj->flagsA >> 3) & 2) - 1;
            pos.x = obj->x - dir * -0xF00;
            pos.y = obj->y - 0x900;
            fn_80074AE4(&pos, dir * 0x300);
            obj->timer = 8;
            if (--obj->count == 0) {
                obj->step++;
            }
        }
        break;
    case 4:
        obj->timer = 8;
        obj->step++;
    case 5:
        fn_800E9750(obj, 0xFFFF);
        if (--obj->timer == 0) {
            obj->state = 0;
            obj->step = 0;
            obj->timer = 0x78;
        }
        break;
    }
}
