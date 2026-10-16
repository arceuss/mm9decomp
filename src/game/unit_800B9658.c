#include "types.h"

extern s32 fn_800A507C();

s32 fn_800B9658(u8* obj) {
    u16 a = *(u16*)(obj + 0x4C);
    if (a == 0) {
        return 0;
    }
    if (*(u16*)(obj + 0x54) != 0xFFFF) {
        return 0;
    }
    {
        u32 m = a & 0x6000;
        if (((m == 0x4000) ^ (m == 0x2000)) == 0) {
            return 0;
        }
    }
    {
        s32 v4 = *(s32*)(obj + 0x20);
        s32 v5 = *(s32*)(obj + 0x1C);
        s32 v0 = *(s32*)(obj + 0x24);
        if (v5 != v0 || v4 != *(s32*)(obj + 0x28)) {
            return 0;
        }
        return fn_800A507C(v5);
    }
}
