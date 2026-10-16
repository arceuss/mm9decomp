#include "types.h"

extern u8 lbl_803051D8[];

void fn_800833EC(s32 a, s32 b) {
    s32 i;

    for (i = a; i != b; i++) {
        lbl_803051D8[i >> 3] &= ~(1 << (i & 7));
    }
}
