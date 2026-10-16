#include "game/work_8031BF70.h"

extern u8 lbl_8027D2D8[];

// probably a static helper in the original file; mwcc inlined it here
static inline u8 GetAttr(s32 x, s32 y) {
    u8* map;
    u32 attr;

    if (x < 0 || y < 0 || x >= 0x7F0000 || y >= 0x6F2000) {
        return 0xF;
    }
    map = lbl_8031BF70.unk288->unkF4;
    attr = map[(x >> 16) + (lbl_8027D2D8[y >> 12] << map[0]) + 4] & 0xF;
    if (attr == 0xF) {
        attr <<= 4;
    }
    return attr;
}

u8 fn_8009E8E4(s32 x, s32 y) {
    return GetAttr(x, y) == 0xF0;
}
