#include "types.h"

extern u8 lbl_80301420[];

extern void fn_800316C8(u8* p, u32 v);

void fn_8002C660(u8* o) {
    u8 t = o[7];

    if (t == 0) {
        fn_800316C8(lbl_80301420, 0xA0007);
        return;
    }
    fn_800316C8(lbl_80301420, ((t - 1) << 24) + 0x4000B);
}
