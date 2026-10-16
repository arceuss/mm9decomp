#include "types.h"

void fn_8009C04C(s32, u8*, s32);

void fn_80083398(u8* p) {
    fn_8009C04C(0, p, 0x34);
    *(u8*)(p + 0x12) = 1;
}
