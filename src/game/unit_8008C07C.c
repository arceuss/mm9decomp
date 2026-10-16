#include "types.h"

typedef struct Unk8008C07C {
    /* 0x0 */ u8 unk0[4];
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
} Unk8008C07C;

void fn_8008C07C(Unk8008C07C* work, u32 value) {
    work->unk0[0] = value;
    work->unk0[1] = value >> 8;
    work->unk0[2] = value >> 16;
    work->unk0[3] = value >> 24;
    work->unk4 = 0;
    work->unk8 = 0;
}
