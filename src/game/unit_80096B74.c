#include "types.h"

extern u8 lbl_80316D78[];

void fn_80096B74(void) {
    u8* q = *(u8**)(lbl_80316D78 + 0x3004) + 0xD40000;
    s8 v = *(s8*)(q + 0x1000);

    if (*(u8*)(q + 0x1002) != 0) {
        if ((u8)v <= 2) {
            q[0x1000] = v + 3;
        } else {
            q[0x1002] = 0;
            (*(u8**)(lbl_80316D78 + 0x3004) + 0xD40000)[0x1000] = 0;
        }
    } else {
        s32 i;
        for (i = 0; i < 6; i++) {
            v++;
            if (v > 10 || v == 6) {
                q[0x1002] = 1;
                (*(u8**)(lbl_80316D78 + 0x3004) + 0xD40000)[0x1000] = 0;
                return;
            }
            if (*(u16*)(q + 0x101C) & (1 << v)) {
                q[0x1000] = v;
                return;
            }
        }
    }
}
