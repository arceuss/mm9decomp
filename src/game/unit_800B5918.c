#include "types.h"

typedef struct UnkPlayer {
    /* 0x000 */ u8 pad0[0x9];
    /* 0x009 */ u8 unk9;
    /* 0x00A */ u8 padA[0xB6 - 0xA];
    /* 0x0B6 */ s16 hp;
    /* 0x0B8 */ u8 padB8[0x124 - 0xB8];
    /* 0x124 */ u32 unk124;
} UnkPlayer;

u32 fn_800B5918(UnkPlayer* p, u32 mask) {
    p->unk124 |= mask;
    return p->unk124 & mask;
}
