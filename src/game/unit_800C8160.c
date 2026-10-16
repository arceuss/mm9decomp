#include "game/work_8038DC58.h"

BOOL fn_800C8160(void) {
    s32 i;
    s32 bit;

    for (i = 0; i < 0x25; i++) {
        bit = i + 8;
        if ((lbl_8038DC58.unkC[bit >> 3] & (1 << (bit & 7))) && bit != 0xD && bit != 0x14 && bit != 0x17 && bit != 0x2C) {
            return FALSE;
        }
    }
    return TRUE;
}
