#include "types.h"

typedef struct Unk80281D48Pair {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
} Unk80281D48Pair;

typedef struct Unk8038E3A8 {
    /* 0x000 */ u8 pad0[0x36C];
    /* 0x36C */ Unk80281D48Pair unk36C[4];
} Unk8038E3A8;

typedef struct Unk8036CF50 {
    /* 0x0000 */ s32 unk0;
    /* 0x0004 */ u8 pad4[0xEFE0 - 0x4];
} Unk8036CF50;

extern Unk80281D48Pair lbl_80281D48[][4];
extern Unk8038E3A8 lbl_8038E3A8;
extern Unk8036CF50 lbl_8036CF50;

void fn_800E5654(void) {
    Unk80281D48Pair* src = lbl_80281D48[lbl_8036CF50.unk0];
    s32 i;

    for (i = 0; i < 4; i++) {
        lbl_8038E3A8.unk36C[i].unk0 = src->unk0;
        src++;
    }
}
