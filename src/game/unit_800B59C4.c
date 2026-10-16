#include "types.h"

typedef struct UnkPlayer {
    /* 0x000 */ u8 pad0[0x10C];
    /* 0x10C */ u8 weapon;
    /* 0x10D */ u8 pad10D[0x112 - 0x10D];
    /* 0x112 */ u8 unk112;
    /* 0x113 */ u8 pad113[0x14C - 0x113];
    /* 0x14C */ u8 unk14C;
    /* 0x14D */ u8 pad14D;
    /* 0x14E */ u16 energy[16];
} UnkPlayer;

typedef struct Unk803051D8 {
    /* 0x00 */ u8 pad0[0x3];
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 pad4[0x38 - 0x4];
} Unk803051D8;

extern Unk803051D8 lbl_803051D8;
extern u8 lbl_8027E8E0[];

u32 fn_800B59C4(UnkPlayer* p) {
    u32 weapon = p->weapon;
    s32 cur = p->energy[weapon];
    s32 min;
    s32 i;

    if ((lbl_803051D8.unk3 & 0x80) && cur >= 0x1C00) {
        min = 0x1C00;
        for (i = 0; i < 11; i++) {
            if (p->energy[lbl_8027E8E0[i]] < min) {
                min = p->energy[lbl_8027E8E0[i]];
                weapon = lbl_8027E8E0[i];
            }
        }
    }
    p->unk112 = weapon;
    return weapon;
}
