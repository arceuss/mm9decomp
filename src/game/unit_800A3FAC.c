#include "game/work_8031BF70.h"
extern s32 (*lbl_8027D298[])(s32, s32);
s32 fn_800A3FAC(s32 x, s32 y) {
    s32 original = x;
    s32 count;
    u16 kind;
    s32 delta, old;
    for (count = 0; count < 16; count++) {
        kind = lbl_8031BF70.unk270[(u16)lbl_8031BF70.unk8A8[(x >> 12) + lbl_8031BF70.unk8A4 * (y >> 12)]] & 15;
        if (kind == 0) return x - original;
        if (kind == 1) x = (x + 0x1000) & ~0xFFF;
        else {
            delta = lbl_8027D298[kind](y & 0xFFF, 0xFFF - (x & 0xFFF));
            if (!delta) return x - original;
            old = x;
            x -= delta;
            if (!((x ^ old) & 0x1000)) return x - original;
        }
    }
    return -1;
}
