#include "types.h"

extern u8 lbl_803140C0[];
extern u8 lbl_8038B2F8[];
void fn_800316C8(u8* o, u32 v);
void fn_8008C07C(u8* p, u32 v);

void fn_800325A4(u8* obj) {
    u8 t = obj[0x26E];
    if (t == 2) {
        fn_800316C8(obj, 6);
        fn_8008C07C(lbl_803140C0, 0x208);
    } else if (t == 3) {
        obj[0x26E] = 1;
    }
}
