#include "types.h"

extern u16 lbl_802805C0[][4];

BOOL fn_800D4A60(u16 id);

BOOL fn_800D57BC(s32 index) {
    u16* ids;
    s32 i;

    if (index < 0x21) {
        ids = lbl_802805C0[index];
        for (i = 0; i < 4; i++) {
            if (!fn_800D4A60(*ids)) {
                return FALSE;
            }
            ids++;
        }
        return TRUE;
    }
    return FALSE;
}
