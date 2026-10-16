#ifndef GAME_ANIM_H
#define GAME_ANIM_H

#include "types.h"

// Frame-sequence player embedded in objects at +0x78 (fn_800E946C passes
// obj + 0x78 to fn_800C9EEC). `data` starts with a u16 offset table indexed by
// sequence id; each sequence is [u8, u8 count-1, then 2-byte entries]. An entry
// whose second byte is -1 ends the sequence, -2 jumps (first byte = target).
typedef struct AnimSeqEntry {
    /* 0x0 */ u8 unk0;
    /* 0x1 */ s8 unk1;
} AnimSeqEntry;

typedef struct AnimPlayer {
    /* 0x0 */ u8* data;
    /* 0x4 */ u8 seq;
    /* 0x5 */ u8 frame;
    /* 0x6 */ u8 count;
    /* 0x7 */ u8 state;
    /* 0x8 */ u8 pad8;
    /* 0x9 */ u8 unk9;
    /* 0xA */ s16 timer;
} AnimPlayer;

#endif
