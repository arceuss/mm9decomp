#include "types.h"

int fn_800B66BC(u8* obj, s32 a) {
    if (a) {
        *(u32*)(obj + 0x104) |= 0x40000;
    }
    obj[0xEC] = obj[0x11];
    obj[0x11] = 9;
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
    obj[0xF5] = 9;
    return 1;
}
