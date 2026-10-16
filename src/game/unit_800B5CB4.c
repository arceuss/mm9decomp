#include "types.h"

s32 fn_800B4478(u8* obj);

s32 fn_800B5CB4(u8* obj, u32 a) {
    u32* p;

    if ((1 << obj[0x11]) & 0x5F) {
        if (a == 2) {
            if (!(*(u32*)(obj + 0x104) & 0x20000)) {
                if (obj[0x11] != 3) {
                    return 0;
                }
            } else if (obj[0x11] == 2 && fn_800B4478(obj)) {
                return 0;
            }
        }
        obj[0xEC] = obj[0x11];
        obj[0x11] = 8;
        obj[0xED] = obj[0x12];
        obj[0x12] = 0;
        obj[0xEE] = obj[0x13];
        obj[0x13] = 0;
        obj[0xF2] = obj[0xEF];
        obj[0xEF] = 0;
        obj[0xF3] = obj[0xF0];
        obj[0xF0] = 0;
        obj[0xF4] = obj[0xF1];
        obj[0xF1] = 0;
        obj[0xF5] = 8;
        if (a >= 2) {
            p = (u32*)(obj + 0x104);
            *p |= 4;
        } else {
            p = (u32*)(obj + 0x104);
            *p &= ~4;
        }
        *p |= 0x20;
        return 1;
    }
    return 0;
}
