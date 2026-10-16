#include "types.h"

s32 fn_800A80C0(s32 value, s32 count, s32 limit) {
    if ((u32)(value + count - 1) <= (u32)((count - 1) * 2)) {
        return value;
    }
    if (count >= limit) {
        count = limit - 1;
    }
    return (value < 0 ? -1 : 1) * count;
}
