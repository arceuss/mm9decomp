#include "types.h"

extern u32 (*lbl_8027EB38[])(u8*, u8*, u8*);

s32 fn_800B9840(u8** obj, u8* a, s32 b, u8* c) {
    u8* t = *obj;
    s32 i;
    for (i = 0; i < 4; i++) {
        if ((lbl_8027EB38[i](a, t, c) & 0x200) == 0x200) {
            return 1;
        }
    }
    return 0;
}
