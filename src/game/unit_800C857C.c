#include "game/work_8038DC58.h"

BOOL fn_800C857C(void) {
    s32 i;

    for (i = 0; i < 8; i++) {
        if (!(lbl_8038DC58.unkC[(i + 0x35) >> 3] & (1 << ((i + 0x35) & 7)))) {
            return FALSE;
        }
    }
    return TRUE;
}
