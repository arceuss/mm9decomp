#include "game/work_8031BF70.h"

typedef struct Unk800A0BE0 {
    /* 0x0 */ u8 pad0[0xE];
    /* 0x0E */ u8 step;
} Unk800A0BE0;

void fn_800A0BE0(Unk800A0BE0* work) {
    if (work->step == 0) {
        lbl_8031BF70.unk4CEE0 = 0;
        lbl_8031BF70.unk4CEE4 = 0;
        work->step++;
    }
}
