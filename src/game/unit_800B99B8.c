#include "types.h"

typedef struct Unk800B99B8Pos {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Unk800B99B8Pos;

typedef struct Unk800B99B8Rect {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
    /* 0x4 */ u16 w;
    /* 0x6 */ u16 h;
} Unk800B99B8Rect;

s32 fn_8009E894(s32 x, s32 y);

s32 fn_800B99B8(Unk800B99B8Pos* pos, Unk800B99B8Rect* rect, s32 dir) {
    s32 res;
    s32 rem;
    s32 px;
    s32 y;
    s32 x;
    s32 w;
    s32 s;

    s = (dir == 1) * 2 - 1;
    x = rect->x * s + pos->x;
    y = -(rect->h - rect->y) + pos->y;
    w = rect->w;
    res = (u16)fn_8009E894(x, y);
    for (rem = w, px = x; rem > 0; rem -= 0x1000) {
        if (rem > 0x1000) {
            px += s * 0x1000;
        } else {
            px += rem * s;
        }
        res |= (u16)fn_8009E894(px, y);
    }
    s = -s;
    for (; w > 0; w -= 0x1000) {
        if (w > 0x1000) {
            x += s * 0x1000;
        } else {
            x += w * s;
        }
        res |= (u16)fn_8009E894(x, y);
    }
    return res;
}
