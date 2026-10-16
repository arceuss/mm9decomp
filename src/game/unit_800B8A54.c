#include "types.h"

extern u8 lbl_8031BF70[];

s32 fn_800B8A54(u8* a, u8* b, s32 c, s32 d, s32 e, u32 index, u32 best) {
    u8* t = lbl_8031BF70 + index * 0x18;
    s32 v = *(s32*)(t + 0x29C) - *(u16*)(t + 0x296);
    if (best == 0xFFFF || v < *(s32*)(b + 0x4)) {
        *(s32*)(b + 0x4) = v;
        best = index;
    } else if (v == *(s32*)(b + 0x4)) {
        u8* t2 = lbl_8031BF70 + best * 0x18;
        s32 av = *(s32*)a;
        s32 dx = av - *(s32*)(t + 0x298);
        s32 dy = av - *(s32*)(t2 + 0x298);
        if (dx * dx < dy * dy) {
            best = index;
        }
    }
    return best;
}
