#ifndef GAME_WORK_802BDCC0_H
#define GAME_WORK_802BDCC0_H

#include "types.h"

// Large work area at the start of .bss (lbl_802BDCC0). The game reaches the
// 0xF0xx fields through addis +0x10000 with negative displacements.
// Only offsets touched by matched code are listed.
typedef struct Unk802BDCC0 {
    /* 0x0000 */ u8 pad0[0xF0A0];
    /* 0xF0A0 */ u8 unkF0A0; // index into lbl_80261B60, see fn_8000BFC4
    /* 0xF0A1 */ u8 unkF0A1;
    /* 0xF0A2 */ u8 padF0A2[0xF0A8 - 0xF0A2];
    /* 0xF0A8 */ s16 unkF0A8;
    /* 0xF0AA */ u8 unkF0AA;
    /* 0xF0AB */ u8 padF0AB;
    /* 0xF0AC */ s32 unkF0AC;
    /* 0xF0B0 */ u8 padF0B0[0xF0BC - 0xF0B0];
    /* 0xF0BC */ s16 unkF0BC;
    /* 0xF0BE */ s16 unkF0BE;
} Unk802BDCC0;

extern Unk802BDCC0 lbl_802BDCC0;

#endif
