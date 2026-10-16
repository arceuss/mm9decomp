#include "types.h"

typedef struct Unk490C {
    /* 0x00 */ u8 pad0[0x104];
    /* 0x104 */ u32 unk104;
    /* 0x108 */ u8 pad108[0x188 - 0x108];
    /* 0x188 */ u16 unk188;
} Unk490C;

s32 fn_800B490C(Unk490C* rec) {
    if (rec->unk104 & 0x800) {
        return 0;
    }
    return (rec->unk188 & 0xC) != 0;
}
