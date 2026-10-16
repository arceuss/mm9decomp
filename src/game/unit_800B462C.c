#include "types.h"

extern u8 lbl_80304B90[];
extern s32* lbl_8027EB60[];

s32 fn_80080484(u8* a, u8* b, s32 c);
s32 fn_800B916C(u8* a, u8* b, s32 c, s32 d, s32 e, s32 f, s32 g);
u32* fn_800B79D4(u8* obj, u32 flags, s32 idx);

s32 fn_800B462C(u8* obj) {
    s32 r;
    u8* p;

    if (*(u32*)(obj + 0x104) & 0x4000) {
        r = 0;
    } else if (fn_80080484(lbl_80304B90 + 0x21C, obj + 0x60, 1) == 0 &&
               (*(u16*)(obj + 0x188) & 1) &&
               !(*(u16*)(obj + 0x188) & 2)) {
        r = 1;
    } else {
        r = 0;
    }
    if (r) {
        p = obj + 0x19C;
        if (fn_800B916C(obj + 0x60, p, *(s32*)p, 0, 0, 0,
                        ((obj[0xA] << 14) & 0x40000) | 0x80000) != 0) {
            return 1;
        }
        if (fn_800B916C(obj + 0x60, p,
                        (s32)fn_800B79D4(obj, ((s32**)lbl_8027EB60)[obj[9]][6], 0),
                        0, 0, 0,
                        ((obj[0xA] << 14) & 0x40000) | 0x80000) != 0) {
            return 1;
        }
    }
    return 0;
}
