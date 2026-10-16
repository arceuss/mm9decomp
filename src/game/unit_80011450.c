#include "types.h"

typedef struct Unk80011450 {
    /* 0x00 */ u8 pad0[0x11];
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x16 - 0x13];
    /* 0x16 */ u8 timer;
} Unk80011450;

void fn_800E9750(Unk80011450* obj, u16 arg);

void fn_80011450(Unk80011450* obj) {
    switch (obj->step) {
    case 0:
        obj->timer = 30;
        obj->step++;
    case 1:
        if (--obj->timer == 0) {
            obj->state = 5;
            obj->step = 0;
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    }
}
