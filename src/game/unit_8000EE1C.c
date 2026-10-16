#include "types.h"

extern u8 lbl_80301280[];
extern u32 lbl_80261DD8[][4];
extern u8 lbl_80261DE8[];

s32 fn_8000EE1C(s32 idx) {
    u8* p = *(u8**)(lbl_80301280 + 0x40);
    s32 v = lbl_80261DD8[*(u32*)p & 7][idx >> 4];
    if (v == 0xFF) {
        return 0;
    }
    return *(u32*)(lbl_80261DE8 + (v << 4)
        + ((*(u16*)(p + ((idx >> 4) * 2 + 8)) >> 12) & 0xC));
}
