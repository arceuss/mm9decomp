#include "types.h"

typedef struct Unk8037C358 {
    /* 0x0 */ u16 unk0;
    /* 0x2 */ u8 pad2[0x10 - 0x2];
} Unk8037C358;

extern Unk8037C358 lbl_8037C358[8];

void fn_800A6888(void) {
    s32 i;

    for (i = 0; i < 8; i++) {
        lbl_8037C358[i].unk0 = 0;
    }
}
