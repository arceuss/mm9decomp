#include "types.h"

extern u8 lbl_80301320[];
void fn_80025C34(u32, u32, u32);
void fn_8002B16C(void);

void fn_8002A310(u32 a) {
    if ((*(u8**)(lbl_80301320 + 0x5C))[0] != 7) {
        return;
    }
    if ((*(u32*)(lbl_80301320 + 4) & 0x20) == 0) {
        return;
    }
    if (a == 0) {
        return;
    }
    (*(u8**)(lbl_80301320 + 0x5C))[1] = (*(u8**)(lbl_80301320 + 0x5C))[0];
    (*(u8**)(lbl_80301320 + 0x5C))[0] = 8;
    fn_80025C34((u32)fn_8002B16C, a, 0xC);
}
