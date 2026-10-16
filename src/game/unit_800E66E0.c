#include "types.h"

typedef struct Unk8039B180 {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ u8 unk4;
    /* 0x5 */ u8 unk5;
    /* 0x6 */ u8 pad6[0x8 - 0x6];
    /* 0x8 */ u8 unk8[1];
} Unk8039B180;

typedef struct Unk803051D8 {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 pad1[0x3 - 0x1];
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 pad4[0x38 - 0x4];
} Unk803051D8;

extern Unk8039B180 lbl_8039B180;
extern Unk803051D8 lbl_803051D8;

void fn_80024974(s32 arg0, s32 arg1, void* arg2, Unk8039B180* arg3);

void fn_800E66E0(u8 arg0) {
    fn_80024974(0, 0, lbl_8039B180.unk8, &lbl_8039B180);
    lbl_803051D8.unk3 |= 0x40;
    lbl_803051D8.unk0 &= ~0x30;
    lbl_8039B180.unk4 = 0;
    lbl_8039B180.unk0 = 0;
    lbl_8039B180.unk5 = arg0;
}
