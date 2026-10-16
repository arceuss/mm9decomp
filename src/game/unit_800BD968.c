#include "types.h"

typedef struct Unk800BD968 {
    /* 0x00 */ u8 pad0[0xA0];
    /* 0xA0 */ u32 flagsA0;
    /* 0xA4 */ u8 padA4[0xCD - 0xA4];
    /* 0xCD */ u8 unkCD;
} Unk800BD968;

typedef struct Unk800BD968Hit {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ struct Unk800BD968Hit* other;
    /* 0x10 */ u8 pad10[0x14 - 0x10];
    /* 0x14 */ u32 flags;
    /* 0x18 */ u8 pad18[0x28 - 0x18];
    /* 0x28 */ Unk800BD968* obj;
} Unk800BD968Hit;

void fn_800BD968(Unk800BD968Hit* hit) {
    Unk800BD968* self;
    Unk800BD968* target;

    if ((hit->flags & 4) || (hit->flags & 0x20)) {
        self = hit->obj;
        target = hit->other->obj;
        self->unkCD |= 2;
        if (target->flagsA0 & 0x200) {
            self->unkCD |= 4;
        }
    }
}
