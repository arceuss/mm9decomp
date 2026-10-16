#include "types.h"

typedef struct UnkB1F8 {
    /* 0x00 */ u8 pad0[0x1F8];
    /* 0x1F8 */ u8 unk1F8;
} UnkB1F8;

typedef struct Unk800BC1F4 {
    /* 0x00 */ u8 pad0[0x34];
    /* 0x34 */ UnkB1F8* unk34;
    /* 0x38 */ u8 pad38[0xC8 - 0x38];
    /* 0xC8 */ u8 unkC8;
    /* 0xC9 */ u8 unkC9;
} Unk800BC1F4;

void fn_800BC1F4(Unk800BC1F4* obj) {
    UnkB1F8* p = obj->unk34;
    s32 d;
    d = p->unk1F8;
    d -= obj->unkC9;
    if (d < 0) {
        d = 0;
    }
    p->unk1F8 = d;
}
