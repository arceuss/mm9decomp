#include "types.h"

extern u8 lbl_80305210[];

u32 fn_800F3DF8(void);
void fn_800F4AA8(u32);
void fn_800840F8(void);

void fn_80083570(u32 arg) {
    if (arg == 0) {
        u32 n = fn_800F3DF8();
        u32 total = 0x20120;
        u32 old;
        u32 aligned;

        if ((n & 0xFFFF) == 1) {
            total = 0x120F00;
        }
        old = *(u32*)(lbl_80305210 + 0x18);
        aligned = (total + 0x1F) & ~0x1F;
        fn_800F4AA8(old);
        *(u32*)(lbl_80305210 + 0x0) = old;
        old += aligned;
        *(u32*)(lbl_80305210 + 0xC) = aligned;
        *(u32*)(lbl_80305210 + 0x18) = old;
    } else {
        fn_800840F8();
    }
}
