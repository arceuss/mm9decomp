#include "types.h"

extern u8 lbl_80301388[];
void fn_800F615C(u8*);
u32 fn_80115F88(u32, u32, u32);
void fn_800F6238(u8*);
u32 fn_800253B0(u32, u32);

u32 fn_8002714C(u32 a, u32 b) {
    u32 r;

    if ((*(u16*)(lbl_80301388 + 0x2A) & 1) == 0) {
        fn_800F615C(lbl_80301388);
        r = fn_80115F88(*(u32*)(lbl_80301388 + 0x18), a, b);
        fn_800F6238(lbl_80301388);
        return r;
    }
    return fn_800253B0(a, b);
}
