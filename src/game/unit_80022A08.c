#include "types.h"

extern u8 lbl_802638A0[];

s32 fn_80022A08(u8* obj) {
    u32 w;
    u8 kind;

    if (obj[0x14] == 0) {
        if ((*(u32*)(obj + 0xA0) & 0x200) == 0) {
            if (*(s16*)(obj + 0xB6) != 0) {
                return 0;
            }
        }
        kind = obj[9];
        *(u32*)(obj + 0x18) = *(u32*)(*(u32*)(lbl_802638A0 + kind * 4) + 8);
        obj[0x10] = 2;
        obj[0x13] = 0;
        obj[0x11] = 0;
        obj[0x12] = 0;
        return 1;
    }
    w = *(u32*)(obj + 0x34);
    if (*(u8*)(w + 0x10) < 2) {
        return 0;
    }
    kind = obj[9];
    *(u32*)(obj + 0x18) = *(u32*)(*(u32*)(lbl_802638A0 + kind * 4) + 8);
    obj[0x10] = 2;
    obj[0x13] = 0;
    obj[0x11] = 0;
    obj[0x12] = 0;
    return 1;
}
