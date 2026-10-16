#include "types.h"

extern u8 lbl_8038B2F8[];

void fn_800372B4(u8* obj) {
    u8* p;
    s16 t;
    p = (u8*)*(u32**)(lbl_8038B2F8 + 0x184);
    p[0x2500] = *(s16*)(obj + 8);
    t = *(s16*)(obj + 8);
    if (t < 0x20) {
        *(s16*)(obj + 8) = t + 1;
        return;
    }
    obj[0x271] = 1;
    p = (u8*)*(u32**)(lbl_8038B2F8 + 0x184);
    p[0x2500] = 0x20;
    obj[0x26C] = 3;
}
