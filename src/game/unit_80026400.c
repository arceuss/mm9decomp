#include "types.h"

extern u8 lbl_80301320[];

void fn_80026400(u8 value) {
    u8* q = *(u8**)(lbl_80301320 + 0x5C);
    u8* w = *(u8**)(q + 4);
    if (value >= *(u16*)(w + 0x10)) {
        return;
    }
    q[0x14] = value;
}
