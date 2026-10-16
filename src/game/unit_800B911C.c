#include "types.h"

extern u32 fn_800B7A28();

s32 fn_800B911C(u8* obj, s32 b, s32 c, s32 d, s32 e, u32 flags) {
    u32 r = fn_800B7A28(obj, obj, c, d, e, (flags << 18 & 0x40000) | 0x10001);
    if ((r & 0xF) != 0 || (r & 0x40) == 0x40) {
        return 1;
    }
    return 0;
}
