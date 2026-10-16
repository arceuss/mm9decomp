#include "types.h"

extern u8 lbl_80301388[];

s32 fn_800270E0(s32 a, u32 b) {
    s32 n = *(u32*)(lbl_80301388 + 0x30) & 0xFF;
    u8* p = *(u8**)(lbl_80301388 + 0x2C);

    while (n > 0) {
        if (a == *(u16*)(p + 4) && (b & *(u32*)p) == b) {
            return 1;
        }
        p += 0x10;
        n--;
    }
    return 0;
}
