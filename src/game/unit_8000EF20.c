#include "types.h"

extern u8 lbl_80301280[];

s32 fn_8000EF20(s32 idx) {
    u8* p = *(u8**)(lbl_80301280 + 0x40);
    return ((*(u32*)lbl_80301280 >> 8) & 0x70000)
        + ((*(u16*)(p + ((idx >> 4) * 2 + 8)) << 12) & 0x3C000);
}
