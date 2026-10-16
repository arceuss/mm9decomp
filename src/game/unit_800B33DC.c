#include "types.h"

extern u8* lbl_804EE8C0;
extern u8* lbl_804EE8F8;

s32 fn_800B7914(u8* obj, s32 v);

s32 fn_800B33DC(u8* obj) {
    u32 r;

    if (obj[0xF0] != 0) {
        r = fn_800B7914(obj, 9);
        if (r != 0xFFFFFFFF) {
            if (r == 9) {
                if (obj[0xF0] != 1) {
                    if (obj[0x1F8] < 3) {
                        if (*(s16*)(lbl_804EE8C0 + 0xA) != 0) {
                            obj[0xF2] = obj[0xEF];
                            obj[0xEF] = 3;
                            obj[0xF3] = obj[0xF0];
                            obj[0xF0] = 0;
                            obj[0xF4] = obj[0xF1];
                            obj[0xF1] = 0;
                        }
                    } else {
                        if (obj[0x1F9] == 0 && *(s16*)(lbl_804EE8F8 + 0xA) != 0) {
                            obj[0xF2] = obj[0xEF];
                            obj[0xEF] = 3;
                            obj[0xF3] = obj[0xF0];
                            obj[0xF0] = 0;
                            obj[0xF4] = obj[0xF1];
                            obj[0xF1] = 0;
                        }
                    }
                }
            } else {
                obj[0xF2] = obj[0xEF];
                obj[0xEF] = 3;
                obj[0xF3] = obj[0xF0];
                obj[0xF0] = 0;
                obj[0xF4] = obj[0xF1];
                obj[0xF1] = 0;
            }
            return r;
        }
    }
    return 9;
}
