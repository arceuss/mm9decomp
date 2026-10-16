#include "types.h"

s32 fn_8000D074(u8 i);
s32 fn_8000C8F4(void);

s32 fn_8000C1B8(u32 flags) {
    u32 mask = flags & 0x200;
    s32 result = 0;
    u8 i;

    for (i = 0; (u32)i < 9; i++) {
        if (flags & (1 << i)) {
            if ((u8)fn_8000D074(i) != 0) {
                result = 1;
            }
        }
    }
    if (mask != 0) {
        if ((u8)fn_8000C8F4() != 0) {
            result = 1;
        }
    }
    return result;
}
