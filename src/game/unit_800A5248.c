#include "types.h"

typedef struct Unk8031BF70Region {
    /* 0x00 */ u16 w;
    /* 0x02 */ u16 h;
    /* 0x04 */ s32 x;
    /* 0x08 */ s32 y;
    /* 0x0C */ u8 padC[0x18 - 0xC];
} Unk8031BF70Region;

typedef struct Unk8031BF70 {
    /* 0x000 */ u8 pad0[0x28E];
    /* 0x28E */ u8 regionCount;
    /* 0x28F */ u8 pad28F[0x294 - 0x28F];
    /* 0x294 */ Unk8031BF70Region regions[1];
} Unk8031BF70;

extern Unk8031BF70 lbl_8031BF70;

s32 fn_800A5248(s32 x, s32 y) {
    s32 i;
    s32 j;
    s32 top;

    for (i = 0; i < lbl_8031BF70.regionCount; i++) {
        if ((u32)(lbl_8031BF70.regions[i].w * 2) > (u32)((x - lbl_8031BF70.regions[i].x) + lbl_8031BF70.regions[i].w) &&
            (u32)(lbl_8031BF70.regions[i].h * 2) > (u32)(lbl_8031BF70.regions[i].h + (y - lbl_8031BF70.regions[i].y) - 1)) {
            top = lbl_8031BF70.regions[i].y - lbl_8031BF70.regions[i].h;
            for (j = 0; j < lbl_8031BF70.regionCount; j++) {
                if ((u32)(lbl_8031BF70.regions[j].w * 2) > (u32)((x - lbl_8031BF70.regions[j].x) + lbl_8031BF70.regions[j].w) &&
                    (u32)(lbl_8031BF70.regions[j].h * 2) > (u32)(lbl_8031BF70.regions[j].h + (top - lbl_8031BF70.regions[j].y) - 1)) {
                    return fn_800A5248(x, lbl_8031BF70.regions[j].y - lbl_8031BF70.regions[j].h);
                }
            }
            return top;
        }
    }
    return y;
}
