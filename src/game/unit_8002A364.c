#include "types.h"

extern u8 lbl_80301320[];
void fn_8002B218(void);
void fn_80025C34(u32, u32, u32);

void fn_8002A364(u32 arg) {
    u8* q = *(u8**)(lbl_80301320 + 0x5C);
    if (q[0] != 7) {
        return;
    }
    if (!(*(u32*)(lbl_80301320 + 4) & 0x20)) {
        return;
    }
    if (arg == 0) {
        return;
    }
    if (*(s32*)(arg) >= 6) {
        return;
    }
    q[1] = q[0];
    (*(u8**)(lbl_80301320 + 0x5C))[0] = 8;
    fn_80025C34((u32)fn_8002B218, arg, 0x10);
}
