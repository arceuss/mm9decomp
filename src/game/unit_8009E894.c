#include "game/work_8031BF70.h"

u16 fn_8009E894(s32 x, s32 y) {
    u32 tx = x >> 12;
    u32 ty = y >> 12;

    if (tx > 0x7EF || ty > 0x6F1) {
        return 1;
    }
    return lbl_8031BF70.unk270[(u16)lbl_8031BF70.unk8A8[tx + lbl_8031BF70.unk8A4 * ty]];
}
