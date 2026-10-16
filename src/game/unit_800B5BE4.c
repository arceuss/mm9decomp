#include "types.h"

typedef struct Unk803051D8 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 unkA;
    /* 0x0B */ u8 padB[0x18 - 0xB];
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[0x38 - 0x1C];
} Unk803051D8;

extern Unk803051D8 lbl_803051D8;

s32 fn_800B5BE4(void) {
    return lbl_803051D8.unk18;
}
