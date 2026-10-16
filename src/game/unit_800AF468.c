#include "types.h"

typedef struct Unk800AF468 {
    /* 0x000 */ u8 pad0[0xA];
    /* 0x00A */ u8 flagsA;
    /* 0x00B */ u8 padB[0x12 - 0xB];
    /* 0x012 */ u8 step;
    /* 0x013 */ u8 unk13;
    /* 0x014 */ u8 pad14[0xA0 - 0x14];
    /* 0x0A0 */ s32 unkA0;
    /* 0x0A4 */ s32 unkA4;
    /* 0x0A8 */ u8 unkA8;
    /* 0x0A9 */ u8 padA9[0xED - 0xA9];
    /* 0x0ED */ u8 unkED;
    /* 0x0EE */ u8 unkEE;
    /* 0x0EF */ u8 padEF[0x104 - 0xEF];
    /* 0x104 */ u32 flags104;
} Unk800AF468;

void fn_800AF468(Unk800AF468* work) {
    switch (work->step) {
    case 0:
        work->flagsA &= ~1;
        work->flags104 |= 0xA;
        work->unkA0 = 0;
        work->unkA4 = 0;
        work->unkA8 = 0;
        work->unkED = work->step;
        work->step = 1;
        work->unkEE = work->unk13;
        work->unk13 = 0;
    case 1:
        work->flags104 |= 0x200;
        break;
    }
}
