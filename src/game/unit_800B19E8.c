#include "types.h"

extern u8 lbl_80304B90[];

s32 fn_800B7950(u8* obj);
s32 fn_800B7978(u8* obj, s32 v);

s32 fn_800B19E8(u8* obj) {
    u8 t;
    u32 a, b;

    if ((*(u16*)(lbl_80304B90 + obj[0x14] * 2 + 0x2A0) & 0x8000) != 0 ||
        ((1 << obj[0x11]) & 0x1110) != 0)
        return -1;
    t = obj[0x10F];
    a = fn_800B7978(obj, *(u16*)(obj + 0x188));
    b = fn_800B7978(obj, fn_800B7950(obj));
    if ((a & 0x10) != 0) {
        if ((b & 0x10) == 0)
            return 0;
        return (t >= 0x60) ? 2 : (s32)((u32)((t | ~0x20u) - ((u32)(t - 0x20) >> 1)) >> 31);
    }
    return (t >= 0x60) ? 2 : (s32)((u32)((t | ~0x20u) - ((u32)(t - 0x20) >> 1)) >> 31);
}
