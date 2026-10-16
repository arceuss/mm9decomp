#include "game/work_8031BF70.h"

typedef struct Unk800A0C14 {
    /* 0x0 */ u8 pad0[0xE];
    /* 0x0E */ u8 step;
} Unk800A0C14;

void fn_800A0C14(Unk800A0C14* work) {
    if (work->step == 0) {
        lbl_8031BF70.unk4CEE0 = 3;
        lbl_8031BF70.unk4CEE4 = 2;
        work->step++;
    }
}
