#include "types.h"

typedef struct Unk800CED0COther {
    /* 0x0 */ u8 pad0[0x8];
    /* 0x8 */ s8 unk8;
} Unk800CED0COther;

typedef struct Unk800CED0CObj {
    /* 0x00 */ u8 pad0[0x34];
    /* 0x34 */ Unk800CED0COther* unk34;
    /* 0x38 */ u8 pad38[0xA0 - 0x38];
    /* 0xA0 */ u32 flagsA0;
} Unk800CED0CObj;

typedef struct Unk800CED0C {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ struct Unk800CED0C* other;
    /* 0x10 */ u8 pad10[0x28 - 0x10];
    /* 0x28 */ void* obj;
} Unk800CED0C;

void fn_800CED0C(Unk800CED0C* hit) {
    Unk800CED0CObj* self = hit->obj;
    Unk800CED0COther* target = hit->other->obj;

    if ((self->flagsA0 & 4) && target->unk8 == 0) {
        self->unk34 = target;
    }
}
