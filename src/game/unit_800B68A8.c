#include "types.h"

extern u8 lbl_8038DC58[];

void fn_800B68A8(u8* obj) {
    u8* p;

    if ((*(u32*)(obj + 0x14) & 1) == 0) {
        return;
    }
    p = *(u8**)(obj + 0x28);
    p[0x114] = 1 - ((p[0xA] >> 3) & 2);
    lbl_8038DC58[0xC] |= 4;
    lbl_8038DC58[0x15] |= 4;
    lbl_8038DC58[0x19] |= 0x20;
}
