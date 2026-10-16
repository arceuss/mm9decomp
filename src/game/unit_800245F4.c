#include "types.h"

s32 fn_800245F4(u8* obj, u32 v) {
    if (obj[0x89] == v) {
        return 0;
    }
    obj[0x89] = (u8)v;
    return 1;
}
