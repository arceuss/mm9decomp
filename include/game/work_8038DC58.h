#ifndef GAME_WORK_8038DC58_H
#define GAME_WORK_8038DC58_H

#include "types.h"

// 0x128-byte .bss block. The 0x84 bytes at unkC are copied out wholesale by
// fn_800C7A4C, and fn_800C7C24/fn_800C7994 set individual bits in them
// (bit n of the table lives at unkC[(n + 8) / 8]), so treat unkC as a byte/bit
// array until the meaning of each bit is known.
typedef struct Unk8038DC58Callback {
    /* 0x0 */ u8 pad0[0x4];
    /* 0x4 */ void (*func)(struct Unk8038DC58Callback* self, void* arg);
} Unk8038DC58Callback;

typedef struct Unk8038DC58 {
    /* 0x000 */ u8 unk0;
    /* 0x001 */ u8 unk1;
    /* 0x002 */ u8 unk2;
    /* 0x003 */ u8 unk3;
    /* 0x004 */ u8 unk4[0xC - 0x4];
    /* 0x00C */ u8 unkC[0x33 - 0xC];
    /* 0x033 */ u8 unk33;
    /* 0x034 */ u8 pad34[0x4A - 0x34];
    /* 0x04A */ u16 unk4A;
    /* 0x04C */ u16 unk4C;
    /* 0x04E */ u16 unk4E;
    /* 0x050 */ u8 pad50[0x68 - 0x50];
    /* 0x068 */ u32 unk68; // compared against constants by fn_800C7D54/fn_800C7D80/fn_800C7DAC
    /* 0x06C */ u8 pad6C[0x90 - 0x6C];
    /* 0x090 */ u8 unk90[0xAE - 0x90];
    /* 0x0AE */ u16 unkAE;
    /* 0x0B0 */ u8 padB0[0xF4 - 0xB0];
    /* 0x0F4 */ s32 unkF4;
    /* 0x0F8 */ s32 unkF8;
    /* 0x0FC */ u8 padFC[0x108 - 0xFC];
    /* 0x108 */ Unk8038DC58Callback unk108;
    /* 0x110 */ u8 pad110[0x120 - 0x110];
    /* 0x120 */ u8 unk120;
    /* 0x121 */ u8 pad121[0x128 - 0x121];
} Unk8038DC58;

extern Unk8038DC58 lbl_8038DC58;

#endif
