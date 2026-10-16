#include "types.h"

extern u8 lbl_803051D8[];

void fn_800D5234(s32 arg);

s32 fn_800B5BF4(u8* obj, s32 d) {
    u8 cur = lbl_803051D8[0x9];
    s32 v = cur + d;

    if (v > 9) {
        v = 9;
    }
    if (cur != v) {
        fn_800D5234(4);
    }
    lbl_803051D8[0x9] = v;
    return v;
}
