#include "types.h"

int fn_800B6010(u8* obj, u8* arg) {
    s8 t = (s8)arg[8];

    if (t != 3 && t != 9 && t != 6) {
        return 0;
    }
    if ((arg[0xB] & 0x10) == 0) {
        return 0;
    }
    if ((1 << obj[0x11]) & 0x7013) {
        if (*(u32*)(obj + 0x104) & 2) {
            return 0;
        }
    } else {
        return 0;
    }
    return *(u16*)(obj + 0x1F0) == arg[0x20];
}
