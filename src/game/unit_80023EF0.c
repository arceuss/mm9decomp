#include "types.h"

extern u8 lbl_804EE6B8[8];

void fn_80023EF0(u8* p, u32 a, u32 b, u32 c, u16 d) {
    *(u32*)(p + 0) = a;
    *(u32*)(p + 4) = (u32)&lbl_804EE6B8;
    *(u32*)(p + 8) = c;
    *(u16*)(p + 0xC) = d;
}
