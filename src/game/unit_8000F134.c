#include "types.h"

extern u8 lbl_8037CC40[];
void fn_800BAFDC(u32, u32, u32);

void fn_8000F134(u32 a) {
    u8 v = lbl_8037CC40[0x1FDE];
    u32 pp;
    u32 b;

    pp = 0;
    if (v != 0xFF) {
        pp = (u32)lbl_8037CC40 + ((v << 4) & 0xFF0) + 0x1618;
    }
    if (pp != 0) {
        b = *(u8*)(lbl_8037CC40 + ((v << 4) & 0xFF0) + 0x1620);
    } else {
        b = 0;
    }
    fn_800BAFDC(a, (b << 5) + 0x220, 8);
}
