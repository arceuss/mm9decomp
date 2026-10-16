#include "types.h"

s32 fn_800245D4(u8* obj, u32 v) {
    if (obj[0x88] == v) {
        return 0;
    }
    obj[0x88] = (u8)v;
    return 1;
}
