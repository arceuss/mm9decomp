#include "game/work_8031BF70.h"

typedef struct Unk80301280_40 {
    /* 0x0 */ u32 unk0;
    /* 0x4 */ u8 pad4[0x8 - 0x4];
    /* 0x8 */ u16 unk8;
    /* 0xA */ u16 unkA;
    /* 0xC */ u16 unkC;
    /* 0xE */ u16 unkE;
} Unk80301280_40;

typedef struct Unk80301280 {
    /* 0x00 */ u8 pad0[0x40];
    /* 0x40 */ Unk80301280_40* unk40;
    /* 0x44 */ u8 pad44[0x48 - 0x44];
} Unk80301280;

extern Unk80301280 lbl_80301280;

void fn_8009E1B0(void) {
    Unk80301280_40* src = lbl_80301280.unk40;

    lbl_8031BF70.unk898 = (src->unk0 >> 8) & 0xF;
    lbl_8031BF70.unk89A = src->unk8;
    lbl_8031BF70.unk89C = src->unkA;
    lbl_8031BF70.unk89E = src->unkC;
    lbl_8031BF70.unk8A0 = src->unkE;
}
