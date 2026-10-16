#include "types.h"

typedef struct Unk7950 {
    /* 0x00 */ u8 pad0[0x18C];
    /* 0x18C */ u16 unk18C;
    /* 0x18E */ u8 pad18E[0x198 - 0x18E];
    /* 0x198 */ u16 unk198;
} Unk7950;

s32 fn_800B7950(Unk7950* rec) {
    s32 mask = 0;
    if (rec->unk198 & 0x10) {
        mask |= 0x40;
    }
    return rec->unk18C & (mask | ~0x40);
}
