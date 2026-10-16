#include "types.h"

u32 fn_800AA554(u32, u16, u32, u32);
void fn_800AA9A4(void);

u32 fn_80029E64(u32 a, u32 b) {
    u32 r = fn_800AA554(a, (u16)0xFFFF, b, 0x10000);
    fn_800AA9A4();
    return r;
}
