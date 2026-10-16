#include "types.h"

extern u8 lbl_8038B2F8[];
void fn_800D56A4(s32 a);
void fn_800316C8(u8* o, u32 v);

void fn_800324DC(u8* obj) {
    u8 t = obj[0x26E];
    if (t == 2) {
        fn_800D56A4(7);
        fn_800316C8(obj, 5);
    } else if (t == 3) {
        obj[0x26E] = 1;
    }
}
