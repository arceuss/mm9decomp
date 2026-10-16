#include "game/work_8031BF70.h"
extern s32 (*lbl_8027D1D8[])(s32, s32);
s32 fn_800A36F8(s32 x, s32 y) {
    s32 original = y;
    s32 count;
    u16 kind;
    s32 delta, old;
    for (count = 0; count < 16; count++) {
        kind = lbl_8031BF70.unk270[(u16)lbl_8031BF70.unk8A8[(x >> 12) + lbl_8031BF70.unk8A4 * (y >> 12)]] & 15;
        if (kind == 0) return y - original;
        if ((s32)kind == 2) return y - original;
        if (kind == 1) y = (y & ~0xFFF) - 1;
        else {
            delta = lbl_8027D1D8[kind](x & 0xFFF, y & 0xFFF);
            if (!delta) return y - original;
            old = y;
            y += delta;
            if (!((y ^ old) & 0x1000)) return y - original;
        }
    }
    return 1;
}
