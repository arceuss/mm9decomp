#include "types.h"

extern void (*lbl_8027E7C0[])(u8*, u32);

void fn_800B5894(u8* obj, u32 idx) {
    lbl_8027E7C0[idx](obj, idx);
    obj[0x10C] = idx;
    obj[0x112] = idx;
    obj[0x10F] = 0;
    obj[0x110] = 0;
    obj[0x111] = 0;
}
