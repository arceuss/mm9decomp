#include "types.h"

s32 fn_800B9610(u8* obj) {
    u16 a = *(u16*)(obj + 0x4C);
    if (a == 0) {
        return 0;
    }
    if (*(u16*)(obj + 0x54) != 0xFFFF) {
        return 0;
    }
    if (!(a & 0x400)) {
        return 0;
    }
    if (!(a & 0x2)) {
        return 0x20;
    }
    return 0;
}
