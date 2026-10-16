#include "types.h"

u32 fn_80014A30(u8* obj) {
    s32 v = *(s32*)(obj + 0x60);
    s32 d = v / 65536;

    d <<= 16;
    if (v < d + 0x3000) {
        return 0;
    }
    if (v < d + 0x5000) {
        return 1;
    }
    if (v < d + 0x7000) {
        return 2;
    }
    if (v < d + 0x9000) {
        return 3;
    }
    if (v < d + 0xB000) {
        return 4;
    }
    return 6 + ((v >= d + 0xD000) & 1);
}
