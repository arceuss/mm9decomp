#include "types.h"

extern u8 lbl_8038B2F8[];
void fn_80036130(u8* o, s32 a);
s32 fn_800D4A60(s32 a);
void fn_800D48DC(s32 a);

void fn_80032F94(u8* obj) {
    fn_80036130(obj, 3);
    if (obj[0x28B] == 0) {
        if (fn_800D4A60(7) != 0) {
            fn_800D48DC(7);
        }
        obj[0x26C] = 9;
    }
}
