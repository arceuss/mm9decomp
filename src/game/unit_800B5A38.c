#include "types.h"

void fn_800D5234(s32 arg);

s32 fn_800B5A38(u8* obj, s32 a, s32 idx) {
    u16* p = (u16*)(obj + idx * 2 + 0x14E);
    u16 cur = *p;
    s32 v = cur + (a << 8);
    u32 changed;

    if (v > 0x1C00) {
        v = 0x1C00;
    }
    changed = (cur != v);
    *p = v;
    if (changed) {
        fn_800D5234(6);
    }
    return 0x1C00 - v;
}
