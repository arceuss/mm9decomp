#include "types.h"

s32 fn_8008212C(u8* p) {
    u32 t;
    u8* q = *(u8**)(p + 0x28);
    u8 f1 = *(u8*)(q + 1);

    if (f1 != 0) {
        if ((*(u8*)(p + 1) & *(u32*)(q + 4)) != 0) {
            return 0;
        }
    }
    if (f1 == 0) {
        t = *(u32*)(q + 4);
        if ((*(u8*)(p + 1) & t) == 0) {
            return 0;
        }
    }
    *(u32*)(p + 0x28) -= 8;
    return 1;
}
