#include "types.h"

void fn_800B72B0(u8* obj, u8 a, u32 b) {
    obj[1] = a;
    obj[0] = 2;
    *(u16*)(obj + 0x02) = 0x1C00;
    *(u16*)(obj + 0x04) = 0x1C00;
    *(u16*)(obj + 0x06) = 0x1C00;
    *(u16*)(obj + 0x08) = 0x1C00;
    *(u16*)(obj + 0x0A) = 0x1C00;
    *(u16*)(obj + 0x0C) = 0x1C00;
    *(u16*)(obj + 0x0E) = 0x1C00;
    *(u16*)(obj + 0x10) = 0x1C00;
    *(u16*)(obj + 0x12) = 0x1C00;
    *(u16*)(obj + 0x14) = 0x1C00;
    *(u16*)(obj + 0x16) = 0x1C00;
    if (b == 1) {
        *(u32*)(obj + 0x18) = 0x7FF;
    } else {
        *(u32*)(obj + 0x18) = 0x201;
    }
}
