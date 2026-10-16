#include "game/work_8038DC58.h"

BOOL fn_800C8770(void) {
    s32 i;

    for (i = 0; i < 12; i++) {
        if (lbl_8038DC58.unkC[0x27 - 0xC + i] >= 27) {
            return TRUE;
        }
    }
    return FALSE;
}
