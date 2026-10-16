#include "types.h"

void fn_800B63B0(u8* obj, u32 a, u32 b, u32 c, u32 d) {
    *(u32*)(obj + 0x1A8) = a;
    *(u32*)(obj + 0x1AC) = b;
    *(u32*)(obj + 0x1B0) = c;
    *(u32*)(obj + 0x1B4) = d;
}
