#include "types.h"

void fn_800243D0(u32, u32, u32);

void fn_80024438(u8* p) {
    s32 full;
    s32 i;
    s32 n = p[0x88];

    if (n > p[0x89] * 4) {
        n = p[0x89] * 4;
    }
    full = n >> 2;
    for (i = 0; i < full; i++) {
        fn_800243D0(7, p[0x14], 6 - i);
    }
    if (i < p[0x89]) {
        fn_800243D0((n & 3) + 3, p[0x14], 6 - i);
        i++;
    }
    for (; i < p[0x89]; i++) {
        fn_800243D0(3, p[0x14], 6 - i);
    }
}
