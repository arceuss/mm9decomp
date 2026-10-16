#include "types.h"

typedef struct Unk8038E738 {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ u8 pad4[0x8 - 0x4];
    /* 0x08 */ s16 unk8;
    /* 0x0A */ s16 unkA;
    /* 0x0C */ u8 unkC;
    /* 0x0D */ u8 unkD_hi : 4;
    /* 0x0D */ u8 unkD_lo : 4;
    /* 0x0E */ u8 padE[0x14 - 0xE];
    /* 0x14 */ u8 state;
    /* 0x15 */ u8 step;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 unk17;
    /* 0x18 */ u8 pad18[0x1F - 0x18];
    /* 0x1F */ u8 unk1F;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
} Unk8038E738;

extern Unk8038E738 lbl_8038E738;

void fn_800E5798(void) {
    lbl_8038E738.unk8 = 0;
    lbl_8038E738.unkD_hi = 0;
    lbl_8038E738.unkD_lo = 0;
    lbl_8038E738.unk1F = 0;
    lbl_8038E738.unkC = 0;
    lbl_8038E738.unk24 = lbl_8038E738.unk20;
    lbl_8038E738.unk28 = 0;
    lbl_8038E738.unk2C = 0;
    lbl_8038E738.state = 0;
    lbl_8038E738.step = 0;
    lbl_8038E738.unk16 = 0;
    lbl_8038E738.unk17 = 0;
    lbl_8038E738.unkA = 0;
}
