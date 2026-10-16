#include "types.h"

typedef struct Unk803B9308 {
    /* 0x0000 */ s32 unk0;
    /* 0x0004 */ s32 unk4;
    /* 0x0008 */ u8 pad8[0x2018 - 0x8];
} Unk803B9308;

extern Unk803B9308 lbl_803B9308;

typedef struct Unk80316D28 {
    /* 0x0 */ u8 pad0[0x3];
    /* 0x3 */ u8 unk3;
    /* 0x4 */ u8 unk4;
    /* 0x5 */ u8 pad5[0x10 - 0x5];
} Unk80316D28;

extern Unk80316D28 lbl_80316D28;

void fn_800A77C4(void);

void fn_800E7BC0(void) {
    if (lbl_80316D28.unk3 == 0 && lbl_80316D28.unk4 < 2) {
        fn_800A77C4();
    }
    lbl_803B9308.unk4 = 0;
}
