#include "types.h"

extern u8 lbl_802819B0[];

void fn_800D9198(u8* obj) {
    u32* e = (u32*)((void**)lbl_802819B0)[obj[9]];
    *(u32*)(obj + 0x18) = *(u32*)((u8*)e + 0x10);
    obj[0x10] = 4;
    obj[0x11] = 0;
    obj[0x12] = 0;
    obj[0x13] = 0;
}
