#include "types.h"

extern u8 lbl_80316D78[];
u32 fn_800BB6C8(u32 a);
void fn_800BB7B8(s32 a);
void fn_800BB4E8(s32 a, s32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);

void fn_80037518(u8* obj) {
    u32 R;
    u32 a;
    u32 b;

    if ((fn_800BB6C8(0) & 0xFF) != 3) {
        return;
    }
    fn_800BB7B8(0);
    R = *(u32*)(lbl_80316D78 + 0x3004) + 0xC29000;
    a = *(u32*)(R + 0x10) >> 1;
    b = (*(u32*)(R + 0x14) >> 1) + R;
    fn_800BB4E8(1, 1, a + R + *(u32*)(a + R), b + *(u32*)b, 0x20, 0, b, a + R);
    obj[0x26F] = 2;
    obj[0x270] = 1;
}
