#include "types.h"

typedef struct Unk10ED8 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x11 - 0xB];
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x16 - 0x13];
    /* 0x16 */ u8 timer;
} Unk10ED8;

extern u8 lbl_80262130[];
void fn_8009996C(u8* a, u8* b);

void fn_80010ED8(Unk10ED8* obj) {
    switch (obj->step) {
    case 0:
        fn_8009996C((u8*)obj + 0x88, lbl_80262130);
        obj->flagsA &= ~1;
        obj->timer = 30;
        obj->step++;
    case 1:
        if (--obj->timer == 0) {
            obj->state = 1;
            obj->step = 0;
        }
        break;
    }
}
