#include "game/work_8038DC58.h"

void fn_800C7594(u8 v) {
    u8 a;

    lbl_8038DC58.unk4C = 0;
    lbl_8038DC58.unk33 = v;
    a = lbl_8038DC58.unkC[0x16 - 0xC];
    lbl_8038DC58.unkC[0x19 - 0xC] &= 0x1F;
    lbl_8038DC58.unkC[0x15 - 0xC] &= 0x1F;
    lbl_8038DC58.unkC[0x16 - 0xC] = a & 0xE0;
}
