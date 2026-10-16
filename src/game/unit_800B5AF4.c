#include "types.h"

void fn_800D5234(s32 arg);

s32 fn_800B5AF4(u8* obj, s32 d) {
    u8 cur = obj[0x14C];
    s32 v = cur + d;

    if (v > 9) {
        v = 9;
    }
    if (cur != v) {
        fn_800D5234(4);
    }
    obj[0x14C] = v;
    return v;
}
