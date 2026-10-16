#include "types.h"

typedef struct Unk8043CD28 {
    /* 0x000 */ u8 pad0[0x8];
    /* 0x008 */ u8* unk8;
    /* 0x00C */ u8 padC[0x2D4 - 0xC];
    /* 0x2D4 */ s32 unk2D4;
    /* 0x2D8 */ s32 unk2D8;
    /* 0x2DC */ u8 pad2DC[0x2E2 - 0x2DC];
    /* 0x2E2 */ u8 unk2E2;
    /* 0x2E3 */ u8 pad2E3[0x2E5 - 0x2E3];
    /* 0x2E5 */ u8 unk2E5;
    /* 0x2E6 */ u8 pad2E6[0x2];
} Unk8043CD28;

extern Unk8043CD28 lbl_8043CD28;

void fn_800EB060(s32 a, s32 b) {
    lbl_8043CD28.unk2D4 = a;
    lbl_8043CD28.unk2D8 = b;
}
