#include "types.h"

extern u8 lbl_80301280[];
extern u8 lbl_8043CA80[];

s32 fn_8000ED10(s32, s32, s32, s32, s32, s32);

s32 fn_8000ECB8(s32 a, s32 b, s32 c, s8 d, s8 e) {
    u8* p = *(u8**)(lbl_80301280 + 0x40);
    u16 v = *(u16*)(p + ((a >> 4) * 2 + 8));
    return fn_8000ED10(a,
        ((v << 3) & 0xF800)
            + (*(u32*)(lbl_8043CA80 + 0x258)
               + ((*(u32*)lbl_80301280 >> 11) & 0x70000)),
        b, c, d, e);
}
