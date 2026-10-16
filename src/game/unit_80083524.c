#include "types.h"

typedef struct Unk80305210 {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
} Unk80305210;

extern u8 lbl_80316D78[0x3028];
extern Unk80305210 lbl_80305210;

void fn_80083524(void) {
    u8* bank = *(u8**)(lbl_80316D78 + 0x3008);
    lbl_80305210.unk0 = 0;
    lbl_80305210.unkC = 0;
    lbl_80305210.unk4 = 0;
    lbl_80305210.unk10 = 0;
    lbl_80305210.unk8 = 0;
    lbl_80305210.unk14 = 0;
    lbl_80305210.unk18 = (s32)bank + 0x2259000;
    lbl_80305210.unk1C = (s32)&lbl_80305210.unk1C;
    lbl_80305210.unk20 = (s32)&lbl_80305210.unk1C;
}
