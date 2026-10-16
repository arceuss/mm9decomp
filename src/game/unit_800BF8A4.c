#include "types.h"

typedef struct Unk800BF8A4 {
    /* 0x00 */ u8 pad0[0x15];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0xA0 - 0x16];
    /* 0xA0 */ u32 flagsA0;
    /* 0xA4 */ u8 padA4[0xC8 - 0xA4];
    /* 0xC8 */ u8 unkC8;
} Unk800BF8A4;

typedef struct Unk800BF8A4Hit {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ struct Unk800BF8A4Hit* other;
    /* 0x10 */ u8 pad10[0x14 - 0x10];
    /* 0x14 */ u32 flags;
    /* 0x18 */ u8 pad18[0x28 - 0x18];
    /* 0x28 */ Unk800BF8A4* obj;
} Unk800BF8A4Hit;

void fn_800BF8A4(Unk800BF8A4Hit* hit) {
    Unk800BF8A4* self;
    Unk800BF8A4* target;

    if (hit->flags & 0x1000) {
        return;
    }
    if (!(hit->flags & 4) && !(hit->flags & 0x20)) {
        return;
    }
    self = hit->obj;
    target = hit->other->obj;
    if (target->flagsA0 & 0x200) {
        return;
    }
    self->unkC8 = 1;
}
