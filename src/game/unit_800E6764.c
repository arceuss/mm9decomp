#include "types.h"

typedef struct Unk803051D8 {
    /* 0x00 */ u8 flags0;
    /* 0x01 */ u8 pad1[0x38 - 0x1];
} Unk803051D8;

typedef struct Unk8039B180 {
    /* 0x0 */ u32 unk0;
    /* 0x4 */ u8 pad4[0x10 - 0x4];
} Unk8039B180;

extern Unk803051D8 lbl_803051D8;
extern Unk8039B180 lbl_8039B180;

BOOL fn_800E6764(void) {
    if (!(lbl_803051D8.flags0 & 0x10)) {
        if (++lbl_8039B180.unk0 >= 36000) {
            lbl_8039B180.unk0 = 36000;
            return TRUE;
        }
    }
    return FALSE;
}
