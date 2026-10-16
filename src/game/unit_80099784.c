#include "types.h"

extern u8 lbl_80316398[];

void fn_8009C04C(s32, void*, s32);

void fn_80099784(void) {
    lbl_80316398[0] = 0;
    lbl_80316398[1] = 0;
    lbl_80316398[2] = 0;
    lbl_80316398[3] = 0;
    fn_8009C04C(0, lbl_80316398 + 0x904, 0x24);
    lbl_80316398[0x934] = 0;
    lbl_80316398[0x935] = 0;
}
