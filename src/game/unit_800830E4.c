#include "types.h"

s32 fn_800830E4(u8* p) {
    u8* q = *(u8**)(p + 0x28);

    switch (*(u8*)(q + 1)) {
    case 0:
        *(u8*)(p + 1) |= 8;
        break;
    case 1:
        *(u8*)(p + 1) &= 0xFFF7;
        break;
    }
    return 0;
}
