#include "types.h"

s32 fn_800B6104(u8* obj) {
    u8* p = *(u8**)(obj + 0x19C);

    return *(u32*)(obj + 0x60) +
           (((obj[0xA] >> 2) & 1) - 1) * (*(u16*)(p + 4) - *(s16*)(p + 0));
}
