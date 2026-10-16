#include "types.h"

typedef struct Unk8031BF70 {
    /* 0x00000 */ u8 pad000[0x284];
    /* 0x00284 */ s32 unk284;
    /* 0x00288 */ u8 pad288[0x4CEE0 - 0x288];
    /* 0x4CEE0 */ u32 unk4CEE0;
    /* 0x4CEE4 */ u32 unk4CEE4;
} Unk8031BF70;

typedef struct UnkA0D08 {
    /* 0x0 */ u8 pad000[0xE];
    /* 0xE */ u8 unkE;
} UnkA0D08;

extern Unk8031BF70 lbl_8031BF70;
extern u8 lbl_804ECDE8[4];

void fn_800A0D08(UnkA0D08* p) {
    s32 x;
    u32 n;
    if (p->unkE == 0) {
        p->unkE = p->unkE + 1;
    }
    x = lbl_8031BF70.unk284 + 0x6000;
    x -= 0x2A000;
    if (x <= 0) {
        n = 0;
    } else if (x >= 0xC000) {
        n = 3;
    } else {
        n = x / 0x3000u;
    }
    lbl_8031BF70.unk4CEE0 = lbl_804ECDE8[n];
    if (n < 2) {
        lbl_8031BF70.unk4CEE4 = 0;
    } else {
        lbl_8031BF70.unk4CEE4 = 2;
    }
}
