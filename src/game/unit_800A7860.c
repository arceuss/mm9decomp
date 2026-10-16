#include "types.h"

typedef struct Unk80316D78 {
    /* 0x0000 */ u8 pad0[0x3004];
    /* 0x3004 */ u8* unk3004;
    /* 0x3008 */ u8 pad3008[0x3028 - 0x3008];
} Unk80316D78;

extern Unk80316D78 lbl_80316D78;

typedef struct Unk8037CC40 {
    /* 0x0000 */ u8 pad0[0x1008];
    /* 0x1008 */ u8 unk1008[0x7230 - 0x1008];
} Unk8037CC40;

typedef struct Unk80383E70 {
    /* 0x0000 */ u8* unk0;
    /* 0x0004 */ u8 pad4[0x7488 - 0x4];
} Unk80383E70;

extern Unk8037CC40 lbl_8037CC40;
extern Unk80383E70 lbl_80383E70;

void fn_800A80F8(void* work, s32 size);

void fn_800A7860(void) {
    fn_800A80F8(lbl_8037CC40.unk1008, 0x1000);
    lbl_80383E70.unk0 = lbl_80316D78.unk3004 + 0xC75000;
}
