#include "types.h"

extern u8 lbl_802638A0[];
void fn_800E9244(u8* obj);
void fn_80040AD0(s32 a, u32 b, u32 c, u32 d);

void fn_80011C44(u8* obj) {
    u32 args[2];

    if (obj[0xE6] != 0) {
        args[0] = *(u32*)(obj + 0x60);
        args[1] = *(u32*)(obj + 0x64);
        fn_80040AD0(2, (u32)args, 0, 0);
    }
    fn_800E9244(obj);
    *(u8*)(obj + 0xA) &= ~1;
    *(u32*)(obj + 0x18) = *(u32*)(*(u32*)(lbl_802638A0 + obj[9] * 4) + 0x10);
    *(u8*)(obj + 0x10) = 4;
    obj[0x11] = 0;
    obj[0x12] = 0;
    obj[0x13] = 0;
}
