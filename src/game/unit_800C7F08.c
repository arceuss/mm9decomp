#include "game/work_8038DC58.h"

BOOL fn_800C7F08(void) {
    s32 i;

    for (i = 0; i < 8; i++) {
        if (lbl_8038DC58.unkC[0x1E - 0xC + i] < 2) {
            return FALSE;
        }
    }
    return TRUE;
}
