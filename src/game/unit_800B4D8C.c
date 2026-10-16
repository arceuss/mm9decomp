#include "types.h"

s32 fn_800B7844(u8* obj);

s32 fn_800B4D8C(u8* obj) {
    s32 v;
    s32 t;
    s32 s;
    s32 res;

    if (*(s16*)(obj + 0xD8) == 0) {
        v = 0;
    } else {
        t = *(s16*)(obj + 0xD8) * 100 / 100;
        s = obj[0x1F3];
        if (s < 50) {
            s = s * 100 / 50;
        } else {
            s = 100;
        }
        v = t * (100 - s * 75 / 100) / 100;
        if (-v == 0) {
            v = 0;
        }
    }
    {
        s16 e0 = *(s16*)(obj + 0xE0);
        *(s16*)(obj + 0xDC) = v;
        if ((s16)v < e0) {
            *(s16*)(obj + 0xE0) = v;
        } else {
            *(s16*)(obj + 0xDC) = e0;
        }
    }
    if (*(u16*)(obj + 0x188) & 0xC) {
        s32 f = fn_800B7844(obj);
        s32 sg = (f == 1) * 2 - 1;
        if (!(*(u32*)(obj + 0x104) & 0x800)) {
            res = *(s16*)(obj + 0xDC) * sg;
        } else {
            res = 0;
        }
    } else {
        res = 0;
    }
    {
        s32 p0 = *(s32*)(obj + 0x60);
        s32 e4 = *(s16*)(obj + 0xE4);
        *(s32*)(obj + 0x68) = res;
        res += e4;
        *(s32*)(obj + 0x60) = p0 + res;
    }
    return res;
}





