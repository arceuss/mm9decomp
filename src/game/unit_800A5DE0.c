#include "types.h"

typedef struct Unk8036CF50 {
    /* 0x0000 */ u8 pad0[0x97A8];
    /* 0x97A8 */ u8 unk97A8[0xEFA8 - 0x97A8];
    /* 0xEFA8 */ u32 unkEFA8;
    /* 0xEFAC */ u16* unkEFAC[2];
    /* 0xEFB4 */ u8* unkEFB4[2];
    /* 0xEFBC */ u8 padEFBC[0xEFE0 - 0xEFBC];
} Unk8036CF50;

extern Unk8036CF50 lbl_8036CF50;

u8* fn_800A5DE0(s32 bank, u16 index) {
    return lbl_8036CF50.unkEFB4[bank] + lbl_8036CF50.unkEFAC[bank][index];
}
