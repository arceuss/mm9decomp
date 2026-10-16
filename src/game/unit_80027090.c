#include "types.h"

extern u8 lbl_80301388[];

s32 fn_80027090(s32 a, u32 b) {
    s32 n = lbl_80301388[0x29];
    u8* p = *(u8**)(lbl_80301388 + 0x24);

    while (n > 0) {
        if (a == *(u16*)(p + 4) && (b & *(u32*)p) == b) {
            return 1;
        }
        p += 0x10;
        n--;
    }
    return 0;
}
