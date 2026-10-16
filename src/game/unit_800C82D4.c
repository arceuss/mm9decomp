#include "types.h"

typedef struct Unk8038DC58 {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ u8 unkC[0x128 - 0xC];
} Unk8038DC58;

extern Unk8038DC58 lbl_8038DC58;

u8 fn_800C82D4(void) {
    s32 count = 0;
    s32 i;
    s32 j;

    for (i = 0; i < 2; i++) {
        for (j = 0x61; j < 0x67; j++) {
            s32 idx = i * 6 + j;

            if (lbl_8038DC58.unkC[idx >> 3] & (1 << (idx & 7))) {
                count++;
            }
        }
    }
    return count >= 4;
}
