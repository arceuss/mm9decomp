#include "types.h"

extern u8 lbl_80268B00[];

void fn_800E9CB8(void*);

void fn_80042F58(u8* p) {
    p[0xA] &= ~1;
    fn_800E9CB8(p);
    *(u32*)(p + 0x18) = *(u32*)(*(u8**)(lbl_80268B00 + p[9] * 4) + 0x10);
    p[0x10] = 4;
    p[0x11] = 0;
    p[0x12] = 0;
    p[0x13] = 0;
}
