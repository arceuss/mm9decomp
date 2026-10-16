#include "types.h"

typedef struct Unk80304EA8 {
    /* 0x000 */ u8 pad0[0x31C];
    /* 0x31C */ u16 unk31C;
} Unk80304EA8;

extern Unk80304EA8 lbl_80304EA8;

void fn_80080BFC(s32 a, s32* b) {
    u16 n;
    s32* rec;
    s32 zero;
    if (a == 0) {
        return;
    }
    n = lbl_80304EA8.unk31C;
    if (n >= 0x20) {
        return;
    }
    rec = (s32*)((u8*)&lbl_80304EA8 + n * 0xC);
    rec[2] = b[0];
    ++n;
    rec[3] = b[1];
    rec[1] = a;
    zero = 0;
    ((s32*)((u8*)&lbl_80304EA8 + n * 0xC))[1] = zero;
    lbl_80304EA8.unk31C = n;
}
