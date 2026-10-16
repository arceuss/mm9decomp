#include "types.h"

extern u8 lbl_80301320[];
void fn_80025C34(u32, u32, u32);

void fn_80025E10(void) {
    if (*(u32*)(*(u8**)(lbl_80301320 + 0x5C) + 0xD4) == 0) {
        return;
    }
    (*(u8**)(lbl_80301320 + 0x5C))[1] = (*(u8**)(lbl_80301320 + 0x5C))[0];
    (*(u8**)(lbl_80301320 + 0x5C))[0] = 0xF;
    fn_80025C34(*(u32*)(*(u8**)(lbl_80301320 + 0x5C) + 0xD4), 0, 0);
}
