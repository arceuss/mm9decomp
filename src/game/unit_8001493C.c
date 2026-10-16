#include "types.h"

extern u32 lbl_804EE988;
extern u8 lbl_804EC728[2];

void fn_8001493C(u8* obj) {
    u32 seed = lbl_804EE988;
    u8 last;
    u8 cur;
    u8 temp;
    u8 idx;
    u32 v;

    v = seed * 0x343FD + 0x269EC3;
    lbl_804EE988 = v & 0x7FFFFFFF;
    if (obj[0xDA] == 1 && *(u16*)(obj + 0xE4) == 0) {
        obj[0x11] = 3;
        obj[0x12] = 0;
        obj[0xD8] = 3;
        obj[0xD9] = 0;
        return;
    }
    idx = (v >> 15) & 1;
    cur = *(u8*)(lbl_804EC728 + idx);
    last = obj[0xD8];
    if (cur == last) {
        temp = obj[0xD9];
        obj[0xD9] = temp + 1;
        if ((u8)(temp + 1) == 3) {
            while (*obj == last) {
                v = v * 0x343FD + 0x269EC3;
                lbl_804EE988 = v & 0x7FFFFFFF;
                idx = (v >> 15) & 1;
                cur = *(u8*)(lbl_804EC728 + idx);
            }
            obj[0xD9] = 0;
        }
    } else {
        obj[0xD9] = 0;
    }
    obj[0x11] = cur;
    obj[0x12] = 0;
    obj[0xD8] = cur;
}
