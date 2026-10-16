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

u16 fn_800B5990(UnkPlayer* p) {
    return p->energy[p->weapon];
}
