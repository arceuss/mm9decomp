#include "game/work_8031BF70.h"

typedef struct Unk800A0CD0 {
    /* 0x0 */ u8 pad0[0xE];
    /* 0x0E */ u8 step;
} Unk800A0CD0;

void fn_800A0CD0(Unk800A0CD0* work) {
    if (work->step == 0) {
        lbl_8031BF70.unk4CEE0 = 4;
        lbl_8031BF70.unk4CEE4 = 1;
        work->step++;
    }
}
