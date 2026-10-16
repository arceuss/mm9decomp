#include "types.h"

typedef struct Unk8031BF70 {
    /* 0x00000 */ u8 pad000[0x284];
    /* 0x00284 */ s32 unk284;
    /* 0x00288 */ u8 pad288[0x4CEE0 - 0x288];
    /* 0x4CEE0 */ u32 unk4CEE0;
    /* 0x4CEE4 */ u32 unk4CEE4;
    /* 0x4CEE8 */ u8 pad4CEE8[0x4CEEC - 0x4CEE8];
    /* 0x4CEEC */ s32 unk4CEEC;
} Unk8031BF70;

typedef struct UnkA0C4C {
    /* 0x0 */ u8 pad000[0xE];
    /* 0xE */ u8 unkE;
} UnkA0C4C;

extern Unk8031BF70 lbl_8031BF70;
extern u32 lbl_804EE984;

extern void fn_800B60CC(u32, s32);

void fn_800A0C4C(UnkA0C4C* p) {
    if (p->unkE == 0) {
        lbl_8031BF70.unk4CEE0 = 4;
        lbl_8031BF70.unk4CEE4 = 1;
        p->unkE++;
    }
    if (lbl_8031BF70.unk284 < 0x2A000) {
        lbl_8031BF70.unk4CEEC = -0x80;
    } else {
        lbl_8031BF70.unk4CEEC = 0x80;
    }
    fn_800B60CC(lbl_804EE984, lbl_8031BF70.unk4CEEC);
}
