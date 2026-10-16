#include "types.h"

typedef struct Unk80080584 {
    /* 0x00 */ u8 pad0[0x1D];
    /* 0x1D */ u8 unk1D;
    /* 0x1E */ u8 pad1E[0x20 - 0x1E];
    /* 0x20 */ u8 step;
    /* 0x21 */ u8 pad21[0x26 - 0x21];
    /* 0x26 */ s16 unk26;
    /* 0x28 */ u8 pad28[0x38 - 0x28];
    /* 0x38 */ s32 unk38;
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ u8 pad40[0x50 - 0x40];
    /* 0x50 */ s32* unk50;
    /* 0x54 */ u8 pad54[0x5C - 0x54];
    /* 0x5C */ s32 unk5C;
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ s32 unk68;
} Unk80080584;

void fn_80080280(Unk80080584* work, u8 arg1);

void fn_80080584(Unk80080584* work) {
    s32* base;

    if (work->step == 0) {
        work->unk26 = 0;
        work->step++;
    }
    base = work->unk50;
    work->unk5C += work->unk60;
    work->unk64 += work->unk68;
    if (base != NULL) {
        work->unk38 = base[0] + work->unk5C;
        work->unk3C = base[1] + work->unk64;
    }
    fn_80080280(work, work->unk1D);
}
