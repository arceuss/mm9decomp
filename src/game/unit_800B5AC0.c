#include "types.h"

typedef struct UnkB5AC0 {
    /* 0x00 */ u8 pad0[0x2];
    /* 0x02 */ u16 unk2;
    /* 0x04 */ u16 unk4;
    /* 0x06 */ u16 unk6;
    /* 0x08 */ u16 unk8;
    /* 0x0A */ u16 unkA;
    /* 0x0C */ u16 unkC;
    /* 0x0E */ u16 unkE;
    /* 0x10 */ u16 unk10;
    /* 0x12 */ u16 unk12;
    /* 0x14 */ u16 unk14;
    /* 0x16 */ u16 unk16;
} UnkB5AC0;

void fn_800B5AC0(UnkB5AC0* rec) {
    rec->unk2 = 0x1C00;
    rec->unk4 = 0x1C00;
    rec->unk6 = 0x1C00;
    rec->unk8 = 0x1C00;
    rec->unkA = 0x1C00;
    rec->unkC = 0x1C00;
    rec->unkE = 0x1C00;
    rec->unk10 = 0x1C00;
    rec->unk12 = 0x1C00;
    rec->unk14 = 0x1C00;
    rec->unk16 = 0x1C00;
}
