#include "types.h"

s32 fn_800B9458(u8* pos, s32 a, s32 b);
s32 fn_800A80C0(s32 pos, s32 a, s32 b);

s32 fn_800B4C40(u8* obj, s32 a) {
    s32 t0;
    s32 t1;
    s32 u;
    s32 q;
    s32 v;
    s32 d;
    s32 p;
    s32 lim;

    obj[0x1F4] = fn_800B9458(obj + 0x60, *(s32*)(obj + 0x19C), 0);
    t0 = obj[0x122];
    t1 = obj[0x123];
    if (t0 > t1) {
        t0 = t1;
    }
    u = t0 * 64 / 100;
    q = obj[0x1F4];
    if (q != 0) {
        q = 100;
    }
    if (u < 0) {
        v = u * 100 / (100 - q * 65 / 100);
    } else {
        v = u * (100 - q * 65 / 100) / 100;
    }
    if (v == 0) {
        v = 1;
    }
    d = v + *(s16*)(obj + 0xE6);
    *(s32*)(obj + 0x74) = d;
    p = a + d;
    *(s32*)(obj + 0x6C) = p;
    a = fn_800A80C0(p, 0x700, 0x700);
    lim = *(s32*)(obj + 0xE8);
    if (lim != 0 && a < -lim) {
        a = -lim;
    }
    *(s32*)(obj + 0x6C) = a;
    return a;
}
