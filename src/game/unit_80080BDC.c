#include "types.h"

typedef struct Unk80304EA8 {
    /* 0x000 */ u32 unk0;
    /* 0x004 */ u32 unk4;
    /* 0x008 */ u8 pad8[0x190 - 0x8];
    /* 0x190 */ u32 unk190;
    /* 0x194 */ u8 pad194[0x31C - 0x194];
    /* 0x31C */ u16 unk31C;
    /* 0x31E */ u16 unk31E;
    /* 0x320 */ u32 unk320;
    /* 0x324 */ u16 unk324;
    /* 0x326 */ u16 unk326;
    /* 0x328 */ u16 unk328;
    /* 0x32A */ u16 unk32A;
} Unk80304EA8;

extern Unk80304EA8 lbl_80304EA8;

void fn_80080BDC(void) {
    lbl_80304EA8.unk31C = 0;
    lbl_80304EA8.unk4 = 0;
    lbl_80304EA8.unk324 = 0;
    lbl_80304EA8.unk190 = 0;
}
