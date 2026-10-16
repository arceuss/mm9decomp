#include "types.h"

extern u8 lbl_80301388[];
void fn_80029980(void);
u32 fn_80025C34(u32, u32, u32);
s32 fn_80027A38(u32, u32);

s32 fn_8002701C(u32 a, u32 b) {
    u16 h = *(u16*)(lbl_80301388 + 0x2A);
    u32 arr[2];

    arr[1] = b;
    arr[0] = a;
    if (h & 8) {
        if ((h & 1) == 0) {
            return fn_80027A38(a, b);
        }
        *(u16*)(lbl_80301388 + 0x2A) = h | 4;
        fn_80025C34((u32)fn_80029980, (u32)arr, 8);
        return 1;
    }
    return fn_80027A38(a, b);
}
