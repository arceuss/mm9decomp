#include "types.h"

extern u8 lbl_80301320[];
void fn_80115F58(u32);

void fn_80025358(void) {
    u8 v = lbl_80301320[0];

    lbl_80301320[1] = v;
    lbl_80301320[0] = 1;
    fn_80115F58(*(u32*)(lbl_80301320 + 0x54));
    if (lbl_80301320[0x28] != 0) {
        lbl_80301320[0x28]--;
    }
}
