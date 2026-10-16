#include "types.h"

void fn_800B6594(u8* obj) {
    u8 t1 = obj[0x11];
    u8 t2 = obj[0x12];
    u8 t3 = obj[0x13];
    u8 s1 = obj[0xEF];
    u8 s2 = obj[0xF0];
    u8 s3 = obj[0xF1];

    *(u32*)(obj + 0x104) &= ~4;
    obj[0xA] |= 1;
    obj[0xEC] = t1;
    obj[0x11] = 0;
    obj[0xED] = t2;
    obj[0x12] = 0;
    obj[0xEE] = t3;
    obj[0x13] = 0;
    obj[0xF2] = s1;
    obj[0xEF] = 0;
    obj[0xF3] = s2;
    obj[0xF0] = 0;
    obj[0xF4] = s3;
    obj[0xF1] = 0;
    obj[0xF5] = 0;
}
