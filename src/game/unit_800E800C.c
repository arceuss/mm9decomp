#include "types.h"

typedef struct Unk803BB320_58 {
    /* 0x0 */ u8 pad0[0x10];
} Unk803BB320_58;

typedef struct Unk803BB320 {
    /* 0x0000 */ u8 pad0[0xC];
    /* 0x000C */ s32 unkC;
    /* 0x0010 */ u8 pad10[0x58 - 0x10];
    /* 0x0058 */ Unk803BB320_58 unk58[4];
    /* 0x0098 */ u8 pad98[0x1760 - 0x98];
} Unk803BB320;

extern Unk803BB320 lbl_803BB320;

Unk803BB320_58* fn_800E800C(s32 index) {
    return &lbl_803BB320.unk58[index];
}
