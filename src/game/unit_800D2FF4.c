#include "types.h"

typedef struct Unk800D2FF4Other {
    /* 0x0 */ u8 pad0[0x8];
    /* 0x8 */ s8 unk8;
    /* 0x9 */ u8 unk9;
} Unk800D2FF4Other;

typedef struct Unk800D2FF4Obj {
    /* 0x00 */ u8 pad0[0xC8];
    /* 0xC8 */ u8 unkC8;
} Unk800D2FF4Obj;

typedef struct Unk800D2FF4 {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ struct Unk800D2FF4* other;
    /* 0x10 */ u8 pad10[0x14 - 0x10];
    /* 0x14 */ u32 flags14;
    /* 0x18 */ u8 pad18[0x28 - 0x18];
    /* 0x28 */ void* obj;
} Unk800D2FF4;

void fn_800D2FF4(Unk800D2FF4* hit) {
    Unk800D2FF4Other* target = hit->other->obj;
    Unk800D2FF4Obj* self = hit->obj;

    if ((hit->flags14 & 8) && target->unk8 == 6 && target->unk9 == 0x24) {
        self->unkC8 = 1;
    }
}
