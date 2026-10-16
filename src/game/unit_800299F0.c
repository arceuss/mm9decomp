#include "types.h"

extern u8 lbl_80316D78[];

u32 fn_800299F0(void) {
    return *(u32*)(lbl_80316D78 + 0x3008) + 0x2C19000;
}
