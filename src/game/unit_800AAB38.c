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

s32 fn_801E263C(s32 arg0, s32 arg1, void* arg2);
void fn_800AB27C(void);

s32 fn_800AAB38(s32 arg0, s32 arg1) {
    s32 result = fn_801E263C(arg1, arg0, lbl_80383E70.unk2018);

    fn_800AB27C();
    return result;
}
