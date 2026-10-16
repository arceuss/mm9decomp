#include "types.h"

typedef struct Unk8004D410 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x11 - 0xB];
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x16 - 0x13];
    /* 0x16 */ u8 timer;
    /* 0x17 */ u8 wait;
    /* 0x18 */ u8 pad18[0x54 - 0x18];
    /* 0x54 */ u32 unk54_hi : 21;
    /* 0x54 */ u32 flipX : 1;
    /* 0x54 */ u32 unk54_lo : 10;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0x88 - 0x68];
    /* 0x88 */ u8 unk88[0xCC - 0x88];
    /* 0xCC */ u8 walks;
    /* 0xCD */ u8 padCD[0xD1 - 0xCD];
    /* 0xD1 */ u8 jumps;
} Unk8004D410;

extern u8 lbl_80265F00[];
extern Unk8004D410* lbl_804EE984;
extern u32 lbl_804EE988;

void fn_800E946C(Unk8004D410* obj, u8 anim);
void fn_8009996C(void* arg0, void* arg1);
void fn_800E9750(Unk8004D410* obj, u16 arg1);

static inline u8 Rand10(void) {
    u32 rnd = lbl_804EE988 * 0x343FD + 0x269EC3;

    lbl_804EE988 = rnd & 0x7FFFFFFF;
    return ((rnd >> 16) & 0x7FFF) % 10;
}

void fn_8004D410(Unk8004D410* obj) {
    u32 flip;
    s32 d;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 0);
        fn_8009996C(obj->unk88, lbl_80265F00);
        obj->wait = 0;
        obj->step++;
    case 1:
        fn_800E9750(obj, 0xFFFF);
        d = lbl_804EE984->x - obj->x;
        flip = (u32)(-d & ~d) >> 31;
        if (flip) {
            obj->flagsA |= 0x10;
        } else {
            obj->flagsA &= 0xEF;
        }
        obj->flipX = flip;
        if (__abs(obj->x - lbl_804EE984->x) < 0x2000) {
            if (obj->y - lbl_804EE984->y > 0x1000) {
                if (obj->wait != 0) {
                    goto tick;
                }
                if (Rand10() <= 7) {
                    if (obj->jumps >= 3) {
                        break;
                    }
                    obj->state = 2;
                    obj->step = 0;
                    obj->jumps++;
                    obj->walks = 0;
                    break;
                }
                obj->wait++;
            } else {
                obj->wait = 0;
            }
        } else if (obj->y - lbl_804EE984->y > 0x1000) {
            if (obj->wait != 0) {
                goto tick;
            }
            if (Rand10() > 7) {
                if (obj->jumps >= 3) {
                    break;
                }
                obj->state = 2;
                obj->step = 0;
                obj->jumps++;
                obj->walks = 0;
                break;
            }
            obj->wait++;
        } else {
            obj->wait = 0;
        }
    tick:
        if (--obj->timer == 0) {
            if (obj->walks != 2) {
                obj->state = 1;
                obj->walks++;
                obj->jumps = 0;
            } else {
                obj->state = 2;
                obj->jumps++;
                obj->walks = 0;
            }
            obj->step = 0;
        }
        break;
    }
}
