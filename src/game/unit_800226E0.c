
#include "types.h"

extern u8 lbl_80304B90[];
void fn_800E9750(u8*, u16);

void fn_800226E0(u8* obj) {
    u32 lim;
    u8 v;
    s32 y;
    s32* py;

    switch (obj[0x12]) {
    case 0:
        v = obj[0xD8];
        if (v == 1) {
            obj[0xD8] = 0;
            *(s32*)(obj + 0x6C) = 0x160;
        } else {
            obj[0xD8] = 1;
            *(s32*)(obj + 0x6C) = -0x160;
        }
        obj[0x16] = 0;
        obj[0x12]++;
    case 1:
        py = (s32*)(obj + 0x6C);
        *(s32*)(obj + 0x64) = *(s32*)(obj + 0x64) + *py;
        y = *(s32*)(obj + 0x64);
        if (y < 0) {
            lim = *(u32*)(lbl_80304B90 + 0x260) - 0x3801;
            if (y >= lim) {
                *(s32*)(obj + 0x64) = lim;
                obj[0x16] = 1;
            }
        } else {
            lim = *(u32*)(lbl_80304B90 + 0x260) + 0x27FF;
            if (y > lim) {
                *(s32*)(obj + 0x64) = lim;
                obj[0x16] = 1;
            }
        }
        if (obj[0x16] != 0) {
            obj[0x11] = 2;
            obj[0x12] = 0;
        }
        break;
    }
    fn_800E9750(obj, 0xFFFF);
}
