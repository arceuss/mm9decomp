#include "types.h"

extern u8 lbl_80316398[];

void fn_800B5DD4(u8* obj) {
    u8 a;
    u8 b;
    u8 c;
    u32 v;

    v = *(u32*)(obj + 0x104);
    v = (v & 0xFFFFFABF) | 0x40;
    *(u32*)(obj + 0x104) = v;
    lbl_80316398[0] &= 0xFE;
    a = obj[0xEC];
    b = obj[0xED];
    c = obj[0xEE];
    v &= ~4;
    v |= 0x20;
    obj[0x116] &= ~4;
    *(u32*)(obj + 0x104) = v;
    if (a == 4) {
        obj[0xEC] = obj[0x11];
        obj[0x11] = 0;
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
        obj[0xF5] = 0;
    } else {
        obj[0xEC] = obj[0x11];
        obj[0x11] = a;
        obj[0xED] = obj[0x12];
        obj[0x12] = b;
        obj[0xEE] = obj[0x13];
        obj[0x13] = c;
        obj[0xF2] = obj[0xEF];
        obj[0xEF] = 0;
        obj[0xF3] = obj[0xF0];
        obj[0xF0] = 0;
        obj[0xF4] = obj[0xF1];
        obj[0xF1] = 0;
        obj[0xF5] = a;
    }
}
