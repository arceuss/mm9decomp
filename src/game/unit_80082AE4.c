#include "types.h"

extern u8 lbl_80316398[];

s32 fn_80082AE4(u8* p) {
    u8* q = *(u8**)(p + 0x28);

    switch (*(u8*)(q + 1)) {
    case 0:
        *(u8*)(lbl_80316398 + 1) |= 2;
        break;
    case 1:
        *(u8*)(lbl_80316398 + 1) = 0;
        break;
    case 2:
        *(u8*)(lbl_80316398 + 0) |= 0x80;
        break;
    case 3:
        *(u8*)(lbl_80316398 + 0) &= 0x78;
        break;
    }
    return 0;
}
