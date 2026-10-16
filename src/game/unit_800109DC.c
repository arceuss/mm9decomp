#include "types.h"

extern u8 lbl_80304B90[];

void fn_800109DC(u8* obj) {
    u8 v = obj[0x12];
    u32* w;

    if (v != 0) {
        return;
    }
    w = (u32*)(lbl_80304B90 + 0x2D8);
    if ((*w & 1) == 0) {
        *w |= 2;
    }
    obj[0x12] = obj[0x12] + 1;
}
