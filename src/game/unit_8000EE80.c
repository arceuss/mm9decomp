#include "types.h"

extern u8 lbl_80301280[];

void fn_8000EE80(s32 idx, u32 a, u32 b) {
    u32 off = (idx >> 4) * 2 + 8;
    *(u16*)(*(u8**)(lbl_80301280 + 0x40) + off) &= ~0x3C;
    *(u16*)(*(u8**)(lbl_80301280 + 0x40) + off) =
        a | (*(u16*)(*(u8**)(lbl_80301280 + 0x40) + off) & 0xFF7B);
    *(u16*)(*(u8**)(lbl_80301280 + 0x40) + off) |= b;
}
