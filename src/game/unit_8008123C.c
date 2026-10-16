#include "types.h"

typedef struct Unk8008123C {
    /* 0x00 */ u8 pad0;
    /* 0x01 */ u8 flags1;
    /* 0x02 */ u8 pad2;
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 pad4[0x24 - 0x4];
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ u8 pad2C[0xF0 - 0x2C];
    /* 0xF0 */ s32 unkF0;
} Unk8008123C;

void fn_8008123C(Unk8008123C* work, s32 value) {
    work->unk28 = value;
    work->unk24 = value;
    work->unkF0 = 0;
    work->unk3 = 0;
    work->flags1 |= 1;
}
