#include "types.h"

extern void fn_800D56A4(s32 a);

void fn_80032FFC(u8* o) {
    if (o[0x26E] == 2) {
        fn_800D56A4(7);
        o[0x26C] = 0x1D;
    } else if (o[0x26E] == 3) {
        o[0x26E] = 1;
    }
}
