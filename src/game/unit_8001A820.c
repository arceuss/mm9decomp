#include "types.h"

extern u8 lbl_802638A0[];
extern void (*lbl_804EC798[2])(u8* obj);
void fn_800E9244(u8* obj);

void fn_8001A820(u8* obj) {
    u8 a;
    u8 v;

    a = obj[0x0A];
    v = obj[0x14];
    if (v == 1) {
        a = *(u8*)(*(u32*)(obj + 0x34) + 0x10);
        if (a >= 2) {
            a = obj[0x0A];
            a = a & 0x7F;   /* hmm hmm */
            obj[0x0A] = a & 0xFD;
            fn_800E9244(obj);
            *(u32*)(obj + 0x18) = *(u32*)(*(u32*)(lbl_802638A0 + obj[9] * 4) + 0xC);
            obj[0x10] = 3;
            obj[0x11] = 0;
            obj[0x12] = 0;
            obj[0x13] = 0;
        }
    } else {
        lbl_804EC798[obj[0x11]](obj);
    }
}
