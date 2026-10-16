#include "game/work_8038DC58.h"

typedef struct Unk803140C0 {
    /* 0x0000 */ u8 pad0[0x227C];
    /* 0x227C */ u8 unk227C;
    /* 0x227D */ u8 pad227D[0x2298 - 0x227D];
} Unk803140C0;

extern Unk803140C0 lbl_803140C0;
extern u16 lbl_8027F6F4[0x25];

void fn_800C675C(s32 arg);

void fn_800C7C24(u8 hi, u8 lo, s32 arg2) {
    u16 id;
    s32 i;

    id = (hi << 8) | lo;
    if (lbl_803140C0.unk227C != 0) {
        return;
    }
    for (i = 0; i < 0x25; i++) {
        if (id == lbl_8027F6F4[i] && (id != 0x600 || i != 0 || arg2 == 0)) {
            lbl_8038DC58.unkC[(i + 8) >> 3] |= 1 << ((i + 8) & 7);
            break;
        }
    }
    if (lbl_8038DC58.unkAE + 1 <= 1000) {
        lbl_8038DC58.unkAE++;
    }
    fn_800C675C(2);
}
