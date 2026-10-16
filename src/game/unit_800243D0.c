#include "types.h"

extern u8 lbl_80383E70[];
void fn_8009C100(u8*, u8*, u32);

void fn_800243D0(u32 a, u32 b, u32 c) {
    u8* base = *(u8**)(lbl_80383E70 + 0x24);
    u32 f = *(u16*)(base + 0xA) & 1;
    u8* p1 = f ? base + a * 0x14 : base + a * 0xC;
    u8* p2;

    p1 += *(u32*)p1;
    p2 = f ? base + b * 0x14 : base + b * 0xC;
    p2 += *(u32*)p2;
    fn_8009C100(p1, p2 + c * 0x20, 0x20);
}
