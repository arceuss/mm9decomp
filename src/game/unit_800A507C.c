#include "types.h"
#include "game/work_8031BF70.h"

extern BOOL (*lbl_8027D1D8[16])(s32 x, s32 y);

s32 fn_800A507C(s32 x, s32 y) {
    u32 tx = x >> 12;
    u32 ty = y >> 12;
    u16 attr;

    if (tx >= 0x7F0 || ty >= 0x6F2) {
        return 0;
    }
    attr = lbl_8031BF70.unk270[(u16)lbl_8031BF70.unk8A8[tx + lbl_8031BF70.unk8A4 * ty]];
    if (lbl_8027D1D8[attr & 0xF](x & 0xFFF, y & 0xFFF)) {
        if (attr & 0x2000) {
            return lbl_8031BF70.unk4AEB4;
        }
        if (attr & 0x4000) {
            return lbl_8031BF70.unk4AEB0;
        }
    }
    return 0;
}
