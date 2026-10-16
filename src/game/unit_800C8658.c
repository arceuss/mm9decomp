#include "game/work_8038DC58.h"

BOOL fn_800C8658(void) {
    s32 i;

    for (i = 0; i < 11; i++) {
        if (!(lbl_8038DC58.unkC[(i + 0x3e) >> 3] & (1 << ((i + 0x3e) & 7)))) {
            return FALSE;
        }
    }
    return TRUE;
}
