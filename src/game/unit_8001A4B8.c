#include "types.h"
#include "game/stateobj.h"

void fn_800B5ECC(u32 a, u32 b);
void fn_800C7608(StateObj* obj);

void fn_8001A4B8(u8* obj) {
    u32 p = *(u32*)(obj + 0xC);
    u32 f14 = *(u32*)(obj + 0x14);
    u32 w = *(u32*)(obj + 0x28);
    u32 v = *(u32*)(p + 0x28);
    u32 b[2];

    if (!(f14 & 1)) {
        return;
    }
    if (*(u8*)(w + 0x14) == 1) {
        if ((obj[0x23] & 0xF) != 8) {
            return;
        }
        b[0] = 0;
        b[1] = 0;
        if (!(f14 & 8)) {
            fn_800B5ECC(v, (u32)b);
        }
        return;
    }
    fn_800C7608((StateObj*)obj);
}
