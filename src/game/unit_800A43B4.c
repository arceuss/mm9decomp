#include "game/work_8031BF70.h"
extern s32 (*lbl_8027D1D8[])(s32, s32);
extern s32 fn_800A36F8(s32, s32);
s32 fn_800A43B4(s32 x, s32 y) {
    s32 row = y >> 12;
    s32 count, delta;
    u16 kind;
    for (count = 0; count < 0x80; count++) {
        if ((u32)row >= 0x700) break;
        kind = lbl_8031BF70.unk270[(u16)lbl_8031BF70.unk8A8[(x >> 12) + lbl_8031BF70.unk8A4 * row]] & 15;
        if (lbl_8027D1D8[kind](x & 0xFFF, y & 0xFFF) && (s32)kind != 2) break;
        y = (count & 1) ? y + 1 : ((y + 0x1000) & ~0xFFF) - 1;
        row = y >> 12;
    }
    if (count >= 0x80) return 0x7FFFFFFF;
    delta = fn_800A36F8(x, y);
    return delta > 0 ? 0 : y + delta;
}
