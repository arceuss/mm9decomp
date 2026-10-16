#include "types.h"

typedef struct Unk800BCE84_28 {
    /* 0x00 */ u8 pad0[0xC8];
    /* 0xC8 */ u8 unkC8;
} Unk800BCE84_28;

typedef struct Unk800BCE84 {
    /* 0x00 */ u8 pad0[0x14];
    /* 0x14 */ u32 flags14;
    /* 0x18 */ u8 pad18[0x28 - 0x18];
    /* 0x28 */ Unk800BCE84_28* unk28;
} Unk800BCE84;

void fn_800BCE84(Unk800BCE84* hit) {
    u32 flags = hit->flags14;

    if (!(flags & 0x1000) && ((flags & 4) || (flags & 0x20))) {
        hit->unk28->unkC8 = 1;
    }
}
