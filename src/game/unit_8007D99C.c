#include "types.h"

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x4];
    /* 0x004 */ void* unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00C */ u8 unkC;
    /* 0x00D */ u8 padD[0x124 - 0xD];
    /* 0x124 */ u8 unk124[0x2D8 - 0x124];
    /* 0x2D8 */ u8 unk2D8[0x28];
} Unk80304B90;

extern Unk80304B90 lbl_80304B90;

void fn_8009C120(void* dst, void* src, u32 size);
void fn_80080FE0(void* arg0, void* arg1);

void fn_8007D99C(void* dst, void* arg1, s32 arg2) {
    lbl_80304B90.unk4 = arg1;
    lbl_80304B90.unk8 = arg2;
    fn_8009C120(dst, lbl_80304B90.unk2D8, 0x28);
    fn_80080FE0(lbl_80304B90.unk124, arg1);
}
