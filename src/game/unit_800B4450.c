#include "types.h"

int fn_800B4450(u8* obj) {
    u32 v = *(u16*)(obj + 0x1E0);

    if ((v & 0xF) == 0 && (v & 0x40) != 0x40) {
        return 1;
    }
    return 0;
}
