#include "types.h"

u8 fn_8009E894(void);
s32 fn_800A36F8(s32, s32);

s32 fn_800C0C1C(s32 a, s32 b) {
    if ((fn_8009E894() & 0xF) == 3) {
        return 0;
    }
    return fn_800A36F8(a, b);
}
