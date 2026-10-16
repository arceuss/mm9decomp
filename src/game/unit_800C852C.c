#include "game/work_8038DC58.h"

BOOL fn_800C852C(void) {
    s32 i;

    for (i = 0; i < 37; i++) {
        if (!(lbl_8038DC58.unkC[(i + 0x8) >> 3] & (1 << ((i + 0x8) & 7)))) {
            return FALSE;
        }
    }
    return TRUE;
}
