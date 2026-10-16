#include "game/work_8038DC58.h"

void fn_800A69C8(void);

void fn_800C7CDC(void) {
    lbl_8038DC58.unkC[0x15 - 0xC] &= ~0x1C;
    lbl_8038DC58.unk4E = 0;
    lbl_8038DC58.unkC[0x1D - 0xC] = 0;
    fn_800A69C8();
}
