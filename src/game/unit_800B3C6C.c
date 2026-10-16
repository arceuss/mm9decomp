#include "types.h"

s32 fn_800B9658(u8* obj);
s32 fn_800B95CC(u8* obj, u32 v, s32 w);
s32 fn_800B9458(u8* obj, u32 v, s32 w);

void fn_800B3C6C(u8* obj) {
    s32 v;
    s32 d;
    u8 t;
    if (((1 << obj[0x11]) & 0x13) != 0) {
        s32 r = fn_800B9658(obj + 0x19C);
        if ((*(u32*)(obj + 0x104) & 0x10000) != 0)
            r += *(s16*)(obj + 0xE4);
        *(u16*)(obj + 0xE4) = r;
    }
    t = obj[9];
    *(u32*)(obj + 0xC8) = *(u32*)(obj + 0xD0);
    *(u32*)(obj + 0xCC) = *(u32*)(obj + 0xD4);
    *(u32*)(obj + 0x1A0) = *(u32*)(obj + 0x1A4);
    if (t == 2 && obj[0x11] == 2) {
        if ((*(u32*)(obj + 0xA0) & 0x1000) != 0) {
            *(u16*)(obj + 0x136) = 0x10;
            *(s16*)(obj + 0x134) = 0x80 * -(((obj[0xA] >> 3) & 2) - 1);
        }
        v = *(u16*)(obj + 0x136);
        if (v > 0) {
            d = *(s16*)(obj + 0x134);
            *(u16*)(obj + 0xE4) = d;
            v = v - 1;
        }
    } else {
        v = 0;
    }
    *(u16*)(obj + 0x136) = v;
    obj[0x1F3] = fn_800B95CC(obj + 0x60, *(u32*)(obj + 0x19C), 0);
    obj[0x1F4] = fn_800B9458(obj + 0x60, *(u32*)(obj + 0x19C), 0);
}
