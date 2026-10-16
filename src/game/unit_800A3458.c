#include "game/work_8031BF70.h"

extern BOOL (*lbl_8027D1D8[])(s32 x, s32 y);

u16 fn_800A3458(s32 x, s32 y) {
    u16 attr = lbl_8031BF70.unk270[(u16)lbl_8031BF70.unk8A8[(x >> 12) + lbl_8031BF70.unk8A4 * (y >> 12)]];
    u16 kind = attr & 0xF;

    if (kind == 0) {
        return 0;
    }
    if (kind == 1) {
        return attr;
    }
    return lbl_8027D1D8[kind](x & 0xFFF, y & 0xFFF) ? attr : 0;
}
