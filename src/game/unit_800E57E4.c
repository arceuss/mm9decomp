#include "types.h"

typedef struct Unk8038E738 {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ u8 pad4[0x8 - 0x4];
    /* 0x08 */ s16 unk8;
    /* 0x0A */ s16 unkA;
    /* 0x0C */ u8 unkC;
    /* 0x0D */ u8 flagsD;
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

extern void (*lbl_804ED3F0[2])(s16* arg);

void fn_800E57E4(void) {
    lbl_8038E738.unk0++;
    lbl_804ED3F0[lbl_8038E738.state](&lbl_8038E738.unk8);
}
