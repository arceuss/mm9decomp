#include "types.h"

typedef struct Unk8037C428 {
    /* 0x000 */ u8 unk0[0x800];
    /* 0x800 */ u8* unk800;
    /* 0x804 */ s32 unk804;
    /* 0x808 */ u8* unk808;
    /* 0x80C */ u8* unk80C;
    /* 0x810 */ u8* unk810;
    /* 0x814 */ u8 pad814[0x818 - 0x814];
} Unk8037C428;

extern Unk8037C428 lbl_8037C428;

void fn_800A77C4(void) {
    lbl_8037C428.unk800 = lbl_8037C428.unk0;
    lbl_8037C428.unk808 = lbl_8037C428.unk0;
    lbl_8037C428.unk80C = lbl_8037C428.unk0;
    lbl_8037C428.unk810 = lbl_8037C428.unk0 + sizeof(lbl_8037C428.unk0);
}
