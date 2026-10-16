#include "types.h"

extern u16 lbl_80316D78[0x1814];

void* fn_8009BECC(u32 size) {
    u16* p = lbl_80316D78;
    u16 w = p[0x1801];
    u16 v = p[0x1800];
    void* ret = (u8*)p + w * 0x1800 + (v << 2);
    u32 need = (size + 3) >> 2;
    if (0x600 - v >= need) {
        p[0x1800] = v + need;
        return ret;
    }
    return 0;
}
