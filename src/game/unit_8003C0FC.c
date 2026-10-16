#include "types.h"

extern void fn_800316C8(u8* o, u32 v);
extern void fn_800E534C(s32 a);
extern void fn_800E5274(s32 a);

void fn_8003C0FC(u8* o) {
    switch ((u32)o[0x26C]) {
    case 2:
        fn_800316C8(o, 0xC);
        if ((s8)o[0x26D] == 0) {
            fn_800E534C(3);
        } else if ((s8)o[0x26D] == 1) {
            fn_800E5274(3);
        }
        if ((s8)o[0x26E] == 1) {
            fn_800E5274(4);
        } else if ((s8)o[0x26E] == 0) {
            fn_800E534C(4);
        }
        break;
    case 3:
        o[0x26C] = 1;
        break;
    }
}
