#include "types.h"
extern u8 lbl_80383E70[];
extern s32 fn_800AA6D8(u32, u16*, s32);
s32 fn_800AA8C4(u32 bank, u16 source, u16 target) {
    s32 result = 0;
    u32 saved;
    if (bank == 1) {
        saved = *(u32*)(lbl_80383E70 + source * 4 + 4);
        result = fn_800AA6D8(bank, &source, 1);
        *(u32*)(lbl_80383E70 + target * 4 + 4) = *(u32*)(lbl_80383E70 + source * 4 + 4);
        *(u32*)(lbl_80383E70 + source * 4 + 4) = saved;
    } else if (bank == 2) {
        saved = *(u32*)(lbl_80383E70 + source * 4 + 0x804);
        result = fn_800AA6D8(bank, &source, 1);
        *(u32*)(lbl_80383E70 + target * 4 + 0x804) = *(u32*)(lbl_80383E70 + source * 4 + 0x804);
        *(u32*)(lbl_80383E70 + source * 4 + 0x804) = saved;
    }
    return result;
}
