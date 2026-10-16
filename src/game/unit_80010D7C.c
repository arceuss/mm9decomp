#include "types.h"

typedef struct Vec2s32 {
    s32 x;
    s32 y;
} Vec2s32;

typedef struct Unk80010D7C_28 {
    /* 0x00 */ u8 pad0[0x14];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15[0x60 - 0x15];
    /* 0x60 */ Vec2s32 unk60;
    /* 0x68 */ u8 pad68[0xE8 - 0x68];
    /* 0xE8 */ Vec2s32 unkE8;
} Unk80010D7C_28;

typedef struct Unk80010D7C {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ struct Unk80010D7C* unkC;
    /* 0x10 */ u8 pad10[0x14 - 0x10];
    /* 0x14 */ u32 flags14;
    /* 0x18 */ u8 pad18[0x23 - 0x18];
    /* 0x23 */ u8 unk23_hi : 4;
    /* 0x23 */ u8 unk23_lo : 4;
    /* 0x24 */ u8 pad24[0x28 - 0x24];
    /* 0x28 */ Unk80010D7C_28* unk28;
} Unk80010D7C;

void fn_80010D7C(Unk80010D7C* obj) {
    Unk80010D7C_28* dst = obj->unk28;
    Unk80010D7C_28* src = obj->unkC->unk28;

    if ((obj->flags14 & 8) && dst->unk14 == 1 && obj->unk23_lo == 3) {
        dst->unkE8 = src->unk60;
    }
}
