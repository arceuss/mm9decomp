#include "types.h"

s32 fn_800B60E8(u8* obj) {
    u8* p = *(u8**)(obj + 0x19C);

    return *(s16*)(p + 2) + (*(u32*)(obj + 0x64) + *(u16*)(p + 6));
}
