#include "types.h"

u32 fn_800B63C4(u8* obj, u32 v) {
    if (v & 1) {
        *(u32*)(obj + 0x104) |= 0x800;
    }
    if (v & 2) {
        *(u32*)(obj + 0x104) |= 0x1000;
    }
    if (v & 4) {
        *(u32*)(obj + 0x104) |= 0x2000;
    }
    if (v & 8) {
        *(u32*)(obj + 0x104) |= 0x4000;
    }
    if (v & 0x10) {
        *(u32*)(obj + 0x104) |= 0x8000;
    }
    return v;
}
