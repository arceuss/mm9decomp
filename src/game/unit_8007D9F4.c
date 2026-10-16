#include "types.h"

typedef struct Unk80304B90 {
    /* 0x000 */ void* unk0;
    /* 0x004 */ u8 pad4[0x8 - 0x4];
    /* 0x008 */ void* unk8;
    /* 0x00C */ u8 padC[0x10 - 0xC];
    /* 0x010 */ u8 unk10[0x124 - 0x10];
    /* 0x124 */ u8 unk124;
    /* 0x125 */ u8 unk125;
    /* 0x126 */ u8 pad126[0x2D8 - 0x126];
    /* 0x2D8 */ u32 unk2D8[0x300 / 4 - 0x2D8 / 4];
} Unk80304B90;

extern Unk80304B90 lbl_80304B90;

void fn_8007D9F4(void* p) {
    lbl_80304B90.unk0 = p;
}
