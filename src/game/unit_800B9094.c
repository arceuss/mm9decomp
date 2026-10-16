#include "types.h"

extern u32 fn_800B7A28();

s32 fn_800B9094(u8* a, u8* b, u8* c, u32 d, u32 e) {
    u32 r;
    fn_800B7A28(a, b, c, d, *(u32*)(c + 4), (e << 18 & 0x40000) | 0xB0100);
    r = fn_800B7A28(a, b, c, d, *(u32*)(c + 4), (e << 18 & 0x40000) | 0xA0100);
    if ((r & 0xF) != 0 || (r & 0x40) == 0x40) {
        return 0;
    }
    return 1;
}
