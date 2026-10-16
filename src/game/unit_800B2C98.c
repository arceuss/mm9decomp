#include "types.h"

extern u8* lbl_804EE8C0;

s32 fn_800B7914(u8* obj, s32 a);

s32 fn_800B2C98(u8* obj) {
    u32 v;

    if (obj[0xF0] != 0) {
        v = fn_800B7914(obj, 0x6);
        if (v != 0xFFFFFFFF) {
            if (v == 0x6) {
                if (obj[0xF0] != 1 && *(u16*)(obj + 0x14E + v * 2) >= 0x80 &&
                    obj[0x1F8] < 0x3 && *(s16*)(lbl_804EE8C0 + 0xA) != 0) {
                    obj[0xF2] = obj[0xEF];
                    obj[0xEF] = 0x3;
                    obj[0xF3] = obj[0xF0];
                    obj[0xF0] = 0;
                    obj[0xF4] = obj[0xF1];
                    obj[0xF1] = 0;
                }
            } else {
                obj[0xF2] = obj[0xEF];
                obj[0xEF] = 0x3;
                obj[0xF3] = obj[0xF0];
                obj[0xF0] = 0;
                obj[0xF4] = obj[0xF1];
                obj[0xF1] = 0;
            }
            return v;
        }
    }
    return 0x6;
}
