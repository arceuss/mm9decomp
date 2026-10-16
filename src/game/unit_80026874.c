#include "types.h"

extern u8 lbl_80301320[];

s32 fn_80026874(void) {
    u8* q = *(u8**)(lbl_80301320 + 0x5C);

    if (*(u32*)(q + 0xC) != 0) {
        if (q[0x17] == 0) {
            if (q[0x14] < *(u16*)(*(u8**)(q + 4) + 0x10)) {
                return *(u32*)(*(u8**)(q + 0x18) + q[0x14] * 0x20 + 0x14) != 0;
            }
        } else if (q[0x17] == 1) {
            if (q[0x15] < *(u32*)(q + 0xC)) {
                return *(u32*)(*(u8**)(q + 0x18) + q[0x15] * 0x30 + 0x14) != 0;
            }
        }
    }
    return 0;
}
