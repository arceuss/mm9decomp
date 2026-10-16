#include "types.h"

extern s32 (*lbl_8027E3E0[])(u8*);
extern s32 (*lbl_8027EA80[])(u8*);
extern s32 (*lbl_8027E794[])(u8*);
extern void (*lbl_8027E768[])(u8*);

s32 fn_800B5828(u8* obj, u32 v);

void fn_800B00A8(u8* obj) {
    s32 n;
    s32 r;
    r = fn_800B5828(obj, obj[0xF5]);
    if ((u32)r != 1) {
        lbl_8027E3E0[r](obj);
        return;
    }
    obj[0xF2] = obj[0xEF];
    obj[0xEF] = 1;
    obj[0xF3] = obj[0xF0];
    obj[0xF0] = 0;
    obj[0xF4] = obj[0xF1];
    obj[0xF1] = 0;
    r = lbl_8027EA80[obj[0x10C]](obj);
    if (r == -1)
        return;
    obj[0xF2] = obj[0xEF];
    obj[0xEF] = 3;
    obj[0xF3] = obj[0xF0];
    obj[0xF0] = 0;
    obj[0xF4] = obj[0xF1];
    obj[0xF1] = 0;
    obj[0x10C] = r;
    r &= 0xFF;
    if (n != 0) {
        r = lbl_8027E794[r](obj);
        obj[0x10C] = r;
    }
    lbl_8027E768[r](obj);
}
