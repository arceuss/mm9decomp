#include "types.h"

void fn_800B6484(u8* obj, u32 a, u16 b, u16 c) {
    u8 t1 = obj[0x11];
    u8 t2 = obj[0x12];
    u8 t3 = obj[0x13];
    u8 s1 = obj[0xEF];
    u8 s2 = obj[0xF0];
    u8 s3 = obj[0xF1];

    *(u32*)(obj + 0x12C) = a;
    *(u16*)(obj + 0x130) = b;
    *(u16*)(obj + 0x132) = c;
    obj[0xEC] = t1;
    obj[0x11] = 12;
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
    obj[0xF5] = 12;
}
