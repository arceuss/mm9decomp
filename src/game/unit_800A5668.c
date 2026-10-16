#include "types.h"

typedef struct Unk803B9308 {
    /* 0x0000 */ s32 unk0;
    /* 0x0004 */ s32 unk4;
    /* 0x0008 */ u8 pad8[0x2018 - 0x8];
} Unk803B9308;

extern Unk803B9308 lbl_8036CF50;

void fn_800A5668(void) {
    lbl_8036CF50.unk0 = 1;
}
