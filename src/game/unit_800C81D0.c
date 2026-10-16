#include "types.h"

typedef struct Unk8038DC58 {
    /* 0x00 */ u8 pad0[0x34];
    /* 0x34 */ u8 unk34[10];
} Unk8038DC58;

extern Unk8038DC58 lbl_8038DC58;
extern u8 lbl_8027F740[];

BOOL fn_800C81D0(void) {
    s32 i;

    for (i = 0; i < 10; i++) {
        if (lbl_8038DC58.unk34[i] > lbl_8027F740[i]) {
            return FALSE;
        }
    }
    return TRUE;
}
