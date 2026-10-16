#include "types.h"

typedef struct Unk800DC028 {
    /* 0x00 */ u8 pad0[0x14];
    /* 0x14 */ u8 unk14;
} Unk800DC028;

extern void (*lbl_802810B4[])(Unk800DC028* obj);

void fn_800DC028(Unk800DC028* obj) {
    lbl_802810B4[obj->unk14](obj);
}
