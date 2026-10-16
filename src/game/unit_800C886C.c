#include "game/work_8038DC58.h"

BOOL fn_800C886C(void) {
    s32 i;

    for (i = 0; i < 8; i++) {
        if (!(lbl_8038DC58.unkC[(i + 0x4d) >> 3] & (1 << ((i + 0x4d) & 7)))) {
            return FALSE;
        }
    }
    return TRUE;
}
