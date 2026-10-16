#include "types.h"

typedef struct Unk800E7960 {
    /* 0x0 */ u8 pad0[0x4];
    /* 0x4 */ s32 unk4;
} Unk800E7960;

void fn_800E7960(Unk800E7960* work, s32 value) {
    work->unk4 = value;
}
