#include "game/work_8038DC58.h"

extern u16 lbl_8027F404[];

void fn_800C75D0(void) {
    s32 v = lbl_8027F404[2];
    s32 c = lbl_8038DC58.unk4C;

    v = (c < v - 1) ? c + 1 : v;
    lbl_8038DC58.unk4C = v;
}
