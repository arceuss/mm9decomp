#include "types.h"

typedef struct Unk800E5CD0 {
    /* 0x0 */ u8 pad0[0x2];
    /* 0x2 */ s16 unk2;
} Unk800E5CD0;

void fn_800E5CD0(Unk800E5CD0* work) {
    work->unk2 = 0;
}
