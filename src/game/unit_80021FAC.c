#include "types.h"

extern u8 lbl_802638A0[];

u32 fn_80021FAC(u8* obj) {
    u8 v;

    if (obj[0x14] <= 1) {
        *(s16*)(obj + 0xB8) = *(s16*)(*(u32*)(obj + 0x38) + 0xB6);
        *(s16*)(obj + 0xB6) = *(s16*)(obj + 0xB8);
    }
    if ((*(u32*)(obj + 0xA0) & 0x200) == 0) {
        if (*(s16*)(obj + 0xB6) == 0) {
            return 0;
        }
    }
    *(u32*)(obj + 0x18) = *(u32*)(*(u32*)(lbl_802638A0 + obj[9] * 4) + 8);
    obj[0x10] = 2;
    v = obj[0x14];
    if (v == 0) {
        obj[0x11] = 0;
    } else if (v == 1) {
        obj[0x11] = 1;
    } else {
        obj[0x11] = 2;
    }
    obj[0x12] = 0;
    obj[0x13] = 0;
    return 1;
}
