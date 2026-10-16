#include "types.h"

typedef struct Unk80383E70 {
    /* 0x0000 */ u8* unk0;
    /* 0x0004 */ u8 unk4[0x800];
    /* 0x0804 */ u8 unk804[0x800];
    /* 0x1004 */ u8 unk1004[0x800];
    /* 0x1804 */ u8 unk1804[0x800];
    /* 0x2004 */ u8 pad2004[0x2018 - 0x2004];
    /* 0x2018 */ u8 unk2018[0x7488 - 0x2018];
} Unk80383E70;

extern Unk80383E70 lbl_80383E70;

void fn_8009C120(void* dst, void* src, s32 size);

void fn_800AA4BC(void) {
    fn_8009C120(lbl_80383E70.unk4, lbl_80383E70.unk1004, sizeof(lbl_80383E70.unk4));
    fn_8009C120(lbl_80383E70.unk804, lbl_80383E70.unk1804, sizeof(lbl_80383E70.unk804));
}
