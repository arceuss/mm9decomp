#include "types.h"

extern u8 lbl_80301280[];

s32 fn_8000EEFC(s32 idx) {
    u8* p = *(u8**)(lbl_80301280 + 0x40);
    return *(u16*)(p + ((idx >> 4) * 2 + 8)) & 0x3C;
}
