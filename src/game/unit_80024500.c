#include "types.h"

extern u32 lbl_804EE6C0;
extern u8 lbl_804EC838[];
void* fn_800E8C44(u32);

void fn_80024500(u32 a) {
    u8* p = (u8*)fn_800E8C44(lbl_804EE6C0);

    if (p != NULL) {
        u8** t = (u8**)lbl_804EC838;

        p[9] = 0;
        *(u32*)(p + 0x18) = *(u32*)t[0];
        *(u16*)(p + 0x28) = 0x146;
        p[0xB] |= 0x24;
        p[0x2E] = 0x10;
        *(u16*)(p + 0x2A) = 0;
        p[0x2C] = 0;
        p[0x2F] = 0;
        p[0x21] = p[0x20];
        p[0x14] = a;
        p[0x8A] = 0;
    }
}
