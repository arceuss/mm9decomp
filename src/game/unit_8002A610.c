#include "types.h"

extern u8 lbl_80301320[];
void fn_801FB4A0(u8* a, u8* b);

void fn_8002A610(u8* p) {
    if (*(u32*)(lbl_80301320 + 4) & 0x10) {
        fn_801FB4A0(p, p + 0x14);
    }
}
