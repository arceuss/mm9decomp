#include "types.h"

typedef struct Unk80080540 {
    /* 0x00 */ u8 pad0[0x1D];
    /* 0x1D */ u8 unk1D;
    /* 0x1E */ u8 pad1E[0x20 - 0x1E];
    /* 0x20 */ u8 step;
    /* 0x21 */ u8 pad21[0x26 - 0x21];
    /* 0x26 */ s16 unk26;
    /* 0x28 */ u8 pad28[0x38 - 0x28];
    /* 0x38 */ s32 unk38;
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ u8 pad40[0x48 - 0x40];
    /* 0x48 */ s32 unk48;
    /* 0x4C */ s32 unk4C;
} Unk80080540;

void fn_80080280(Unk80080540* work, u8 arg1);

void fn_80080540(Unk80080540* work) {
    if (work->step == 0) {
        work->unk26 = 0;
        work->step++;
    }
    work->unk38 += work->unk48;
    work->unk3C += work->unk4C;
    fn_80080280(work, work->unk1D);
}
