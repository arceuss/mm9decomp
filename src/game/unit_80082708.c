#include "types.h"

s32 fn_80082708(u8* p) {
    u8* e;
    u8* q = *(u8**)(p + 0x28);

    e = p + (*(u8*)(q + 1) << 4);
    if (*(u32*)(e + 0x2C) == 0) {
        return 0;
    }
    *(u16*)(e + (*(s16*)(q + 2) << 1) + 0x36) = *(u32*)(q + 4);
    return 0;
}
