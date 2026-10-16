#include "types.h"

extern u32** lbl_8027EAF8[];

u32* fn_800B79D4(u8* obj, u32 flags, s32 idx) {
    u32 a = (flags >> 16) & 0x7F;
    if ((flags >> 23) & 1) {
        return (u32*)lbl_8027EAF8[obj[9]][a][idx];
    }
    return lbl_8027EAF8[obj[9]][a];
}
