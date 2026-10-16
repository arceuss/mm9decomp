#include "types.h"

s32 fn_80081C40(u8* p) {
    s32 v;
    u8* q = *(u8**)(p + 0x28);

    if (*(u8*)(q + 1) == 0) {
        if (*(u8*)(p + 2) != 0) {
            *(u8**)(p + 0x28) = q - 8;
            return 1;
        }
        return 0;
    }
    v = *(s32*)(q + 4);
    *(s32*)(p + 0xF0) = v;
    if (*(u8*)(q + 1) == 2) {
        *(s32*)(p + 0xF0) = v - *(s32*)(p + 0xEC);
    }
    v = *(s32*)(p + 0xF0);
    if (v <= 0) {
        *(s32*)(p + 0xF0) = 0;
        return 0;
    }
    *(s32*)(p + 0xF0) = v - 1;
    return 1;
}
