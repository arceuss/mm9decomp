#include "types.h"

s32 fn_80082188(u8* p) {
    u8* q = *(u8**)(p + 0x28);

    switch (*(u8*)(q + 1)) {
    case 0:
        *(u16*)(p + 0xF6) = 0x8000;
        break;
    case 1:
        *(u16*)(p + 0xF6) = 0;
        break;
    case 2:
        *(u16*)(p + 0xF6) = *(u32*)(q + 4) | 0x8000;
        break;
    }
    return 0;
}
