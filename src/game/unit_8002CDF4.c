#include "types.h"

extern u8 lbl_8038B2F8[];

void fn_8002CDF4(u8* obj) {
    u8* p;
    s16 t;
    p = (u8*)*(u32**)(lbl_8038B2F8 + 0x184);
    p[0x2500] = *(s16*)(obj + 8);
    t = *(s16*)(obj + 8);
    if (t > 0) {
        *(s16*)(obj + 8) = t - 1;
        return;
    }
    obj[0x26C] = 2;
    obj[0x288] = 1;
    obj[5] = 2;
}
