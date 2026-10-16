#include "types.h"

extern void fn_800BA4D4();

s32 fn_800B7844(u8* obj) {
    s32 r;
    if ((*(u16*)(obj + 0x188) & 0xC) != 0 && (*(u32*)(obj + 0x104) & 0x2000) == 0) {
        r = (*(u16*)(obj + 0x188) >> 3) & 1;
        fn_800BA4D4(obj, r);
    } else {
        r = (obj[0x0A] >> 4) & 1;
    }
    return r;
}
