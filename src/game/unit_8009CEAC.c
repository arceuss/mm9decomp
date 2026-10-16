#include "types.h"

typedef struct Unk8009CEAC_28 {
    /* 0x00 */ u8 pad0[0x8];
    /* 0x08 */ s8 unk8;
    /* 0x09 */ u8 pad9[0xC8 - 0x9];
    /* 0xC8 */ struct Unk8009CEAC_28* unkC8;
} Unk8009CEAC_28;

typedef struct Unk8009CEAC {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ struct Unk8009CEAC* unkC;
    /* 0x10 */ u8 pad10[0x14 - 0x10];
    /* 0x14 */ u32 flags14;
    /* 0x18 */ u8 pad18[0x28 - 0x18];
    /* 0x28 */ Unk8009CEAC_28* unk28;
} Unk8009CEAC;

void fn_8009CEAC(Unk8009CEAC* obj) {
    Unk8009CEAC_28* dst = obj->unk28;
    Unk8009CEAC_28* src = obj->unkC->unk28;

    if ((obj->flags14 & 4) && src->unk8 == 0) {
        dst->unkC8 = src;
    }
}
