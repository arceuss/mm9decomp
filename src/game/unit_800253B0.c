#include "types.h"

extern u8 lbl_80301320[];
void fn_800F615C(u8*);
u32 fn_80115F88(u32, u32, u32);
void fn_800F6238(u8*);

u32 fn_800253B0(u32 a, u32 b) {
    u32 r;

    fn_800F615C(lbl_80301320 + 0x3C);
    r = fn_80115F88(*(u32*)(lbl_80301320 + 0x54), a, b);
    fn_800F6238(lbl_80301320 + 0x3C);
    return r;
}
