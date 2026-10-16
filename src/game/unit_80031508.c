#include "types.h"

u32 fn_80031508(u8* obj, u32 direction) {
    u8 pos;

    pos = obj[0x2AC];
    if (direction != 0) {
        if (pos == 5) {
            return 0;
        }
        if (pos + 1 > obj[0x290] - 1) {
            return 5;
        }
        return (u8)(pos + 1);
    }
    if (pos == 0) {
        return 5;
    }
    if (pos > obj[0x290] - 1) {
        return (u8)(obj[0x290] - 1);
    }
    return (u8)(pos - 1);
}
