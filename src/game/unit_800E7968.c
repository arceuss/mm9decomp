#include "types.h"

typedef struct Unk803B9308 {
    /* 0x0000 */ s32 unk0;
    /* 0x0004 */ s32 unk4;
    /* 0x0008 */ u8 pad8[0x2018 - 0x8];
} Unk803B9308;

extern Unk803B9308 lbl_803B9308;

void fn_800A7764(void);
void fn_800A77E4(void);

void fn_800E7968(void) {
    lbl_803B9308.unk0 = 0;
    lbl_803B9308.unk4 = 0;
    fn_800A7764();
    fn_800A77E4();
}
