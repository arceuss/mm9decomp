#include "types.h"

typedef struct Unk800DC00C {
    /* 0x00 */ u8 pad0[0x14];
    /* 0x14 */ u8 unk14;
} Unk800DC00C;

extern void (*lbl_802810A0[])(Unk800DC00C* obj);

void fn_800DC00C(Unk800DC00C* obj) {
    lbl_802810A0[obj->unk14](obj);
}
