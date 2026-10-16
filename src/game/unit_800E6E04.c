#include "types.h"

typedef struct Unk8039B190 {
    /* 0x00 */ s32 unk0[4];
    /* 0x10 */ u8 pad10[0x90 - 0x10];
    /* 0x90 */ u8 unk90[4];
    /* 0x94 */ s32 unk94[7];
} Unk8039B190;

extern Unk8039B190 lbl_8039B190;
extern s32 lbl_80281E48[4];

typedef struct Unk80316D28 {
    /* 0x0 */ u8 pad0[0x3];
    /* 0x3 */ u8 unk3;
    /* 0x4 */ u8 unk4;
    /* 0x5 */ u8 pad5[0x10 - 0x5];
} Unk80316D28;

extern Unk80316D28 lbl_80316D28;

void fn_800E6E04(void) {
    s32 i;
    u32 j;

    if (lbl_80316D28.unk3 != 0) {
        return;
    }
    if (lbl_80316D28.unk4 >= 2) {
        return;
    }
    for (i = 0; i < 4; i++) {
        j = lbl_80281E48[i] >> 4;
        lbl_8039B190.unk90[j] = 0;
        lbl_8039B190.unk94[j] = 0;
    }
}
