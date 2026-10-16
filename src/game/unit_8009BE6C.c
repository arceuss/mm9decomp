#include "types.h"

extern u8 lbl_80316D78[];

void OSSetMEM1ArenaLo(u32);
void OSSetMEM2ArenaLo(u32);

void fn_8009BE6C(void) {
    *(u32*)(lbl_80316D78 + 0x3004) = 0x80000000;
    OSSetMEM1ArenaLo(0x80DAD000);
    *(u32*)(lbl_80316D78 + 0x3008) = 0x90000000;
    OSSetMEM2ArenaLo(0x92C19000);
    *(u16*)(lbl_80316D78 + 0x3002) = 0;
    *(u16*)(lbl_80316D78 + 0x3000) = 0;
}
