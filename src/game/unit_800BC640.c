#include "types.h"

typedef struct Unk800BC640 {
    /* 0x00 */ u8 pad0[0x15];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0xA0 - 0x16];
    /* 0xA0 */ u32 flagsA0;
    /* 0xA4 */ u8 padA4[0xC8 - 0xA4];
    /* 0xC8 */ u8 unkC8;
} Unk800BC640;

typedef struct Unk800BC640Hit {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ struct Unk800BC640Hit* other;
    /* 0x10 */ u8 pad10[0x14 - 0x10];
    /* 0x14 */ u32 flags;
    /* 0x18 */ u8 pad18[0x28 - 0x18];
    /* 0x28 */ Unk800BC640* obj;
} Unk800BC640Hit;

void fn_800BC640(Unk800BC640Hit* hit) {
    Unk800BC640* self;
    Unk800BC640* target;

    if (hit->flags & 0x1000) {
        return;
    }
    if (!(hit->flags & 4) && !(hit->flags & 0x20)) {
        return;
    }
    self = hit->obj;
    target = hit->other->obj;
    if ((target->flagsA0 & 0x200) && self->unk15 == 2) {
        return;
    }
    self->unkC8 = 1;
}
