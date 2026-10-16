#include "types.h"

typedef struct Unk800D2884Obj {
    /* 0x00 */ u8 pad0[0x11];
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
} Unk800D2884Obj;

typedef struct Unk800D2884 {
    /* 0x00 */ u8 pad0[0x14];
    /* 0x14 */ u32 flags14;
    /* 0x18 */ u8 pad18[0x23 - 0x18];
    /* 0x23 */ u8 unk23_hi : 4;
    /* 0x23 */ u8 unk23_lo : 4;
    /* 0x24 */ u8 pad24[0x28 - 0x24];
    /* 0x28 */ Unk800D2884Obj* obj;
} Unk800D2884;

void fn_800D2884(Unk800D2884* hit) {
    Unk800D2884Obj* obj = hit->obj;

    if ((hit->flags14 & 1) && hit->unk23_lo == 5) {
        obj->state = 1;
        obj->step = 0;
    }
}
