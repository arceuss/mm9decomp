#include "types.h"

u16 fn_800A502C(u16 id);

int fn_800B608C(u8* obj) {
    u32 v = (u16)fn_800A502C(*(u16*)(obj + 0x1F0));

    return v != 0xFFFF;
}
