#include "types.h"

typedef struct Unk800D91D0 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x16 - 0xB];
    /* 0x16 */ u8 timer;
} Unk800D91D0;

void fn_800E9750(Unk800D91D0* obj, u16 arg1);

void fn_800D91D0(Unk800D91D0* obj) {
    obj->timer = (obj->timer + 1) % 128;
    if (obj->timer < 0x60) {
        obj->flagsA |= 1;
    } else {
        obj->flagsA &= ~1;
    }
    fn_800E9750(obj, 0xFFFF);
}
