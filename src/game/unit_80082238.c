#include "types.h"

void fn_800815CC(u8*, s32, s32);

s32 fn_80082238(u8* p) {
    u8* q = *(u8**)(p + 0x28);
    s32 f1 = *(u8*)(q + 1);
    s32 v = *(s32*)(q + 4);
    s32 r;

    if (f1 == 0) {
        r = 0;
    } else {
        fn_800815CC(p, f1, v);
        r = 0;
    }
    return r;
}
