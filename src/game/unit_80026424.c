#include "types.h"

extern u8 lbl_80301320[];

void fn_80026424(u32 value) {
    u8* q = *(u8**)(lbl_80301320 + 0x5C);
    if (q[0x17] != 1) {
        return;
    }
    if (value >= *(u32*)(q + 0xC)) {
        return;
    }
    q[0x15] = (u8)value;
}
