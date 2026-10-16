#include "types.h"

void fn_800C675C(u32);

s32 fn_80083310(u8* p) {
    u8* q = *(u8**)(p + 0x28);

    if (*(u8*)(q + 1) == 0) {
        fn_800C675C(*(s16*)(q + 2) & 0xFF);
    }
    return 0;
}
