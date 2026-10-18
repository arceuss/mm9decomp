#include "types.h"

typedef struct Unk8031BF70Region {
    /* 0x00 */ u16 w;
    /* 0x02 */ u16 h;
    /* 0x04 */ s32 x;
    /* 0x08 */ s32 y;
    /* 0x0C */ u8 padC[0x18 - 0xC];
} Unk8031BF70Region;

typedef struct Unk8031BF70 {
    /* 0x000 */ u8 pad0[0x270];
    /* 0x270 */ u16* unk270;
    /* 0x274 */ u8 pad274[0x28E - 0x274];
    /* 0x28E */ u8 regionCount;
    /* 0x28F */ u8 pad28F[0x294 - 0x28F];
    /* 0x294 */ Unk8031BF70Region regions[16];
    /* 0x414 */ u8 pad414[0x8A4 - 0x414];
    /* 0x8A4 */ u16 unk8A4;
    /* 0x8A6 */ u8 pad8A6[2];
    /* 0x8A8 */ u16 grid[1];
} Unk8031BF70;

extern Unk8031BF70 lbl_8031BF70;

extern s32 (*lbl_8027D1D8[16])(s32, s32);
s32 fn_800A5248(s32 x, s32 y);

static inline s32 Region(s32 x, s32 y) {
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

s32 fn_800A3500(s32 x, s32 y) {
    s32 old = y;
    s32 d;
    s32 i;
    u16 type;
    s32 prev;

    for (i = 0; i < 16; i++) {
        type = lbl_8031BF70.unk270[lbl_8031BF70.grid[(x >> 12) + lbl_8031BF70.unk8A4 * (y >> 12)]] & 15;
        if (type == 0 || (s32)type == 2) {
            break;
        }
        if (type == 1) {
            y = (y & ~0xFFF) - 1;
        } else {
            d = lbl_8027D1D8[type](x & 0xFFF, y & 0xFFF);
            if (d == 0) {
                break;
            }
            prev = y;
            y += d;
            if (!((y ^ prev) & 0x1000)) {
                break;
            }
        }
    }
    if (i >= 16) {
        return 1;
    }
    return Region(x, y) - old;
}
