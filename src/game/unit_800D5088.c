#include "types.h"

typedef struct Unk8038E028 {
    /* 0x0 */ u8 unk0;
    /* 0x1 */ u8 unk1;
    /* 0x2 */ u8 unk2;
    /* 0x3 */ u8 pad3;
    /* 0x4 */ u16 unk4[5];
} Unk8038E028;

extern Unk8038E028 lbl_8038E028;

void fn_800D5088(void) {
    s32 i;

    for (i = 0; i < 5; i++) {
        lbl_8038E028.unk4[i] = 0xFFFF;
    }
    lbl_8038E028.unk1 = 0;
    lbl_8038E028.unk0 = 0;
    lbl_8038E028.unk2 = 0;
}
