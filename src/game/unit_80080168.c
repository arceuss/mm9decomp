#include "types.h"

typedef struct Unk80080168 {
    /* 0x00 */ u8 pad0[0x18];
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 unk1C;
    /* 0x1D */ u8 pad1D;
    /* 0x1E */ s16 unk1E;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s16 unk24;
} Unk80080168;

extern s32 lbl_802727E8[];

void fn_80080168(Unk80080168* work, s32 index) {
    work->unk1C = index;
    work->unk20 = 0;
    work->unk24 = 0;
    work->unk1E = 0;
    work->unk18 = lbl_802727E8[index];
}
