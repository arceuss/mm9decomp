#include "types.h"

typedef struct Unk800B98BCPos {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Unk800B98BCPos;

typedef struct Unk800B98BCRect {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
    /* 0x4 */ u16 w;
    /* 0x6 */ u16 h;
} Unk800B98BCRect;

s32 fn_8009E894(s32 x, s32 y);

s32 fn_800B98BC(Unk800B98BCPos* pos, Unk800B98BCRect* rect, s32 dir) {
    s32 s = (dir == 1) * 2 - 1;
    s32 x = rect->x * s + pos->x;
    s32 y = pos->y + rect->y + rect->h;
    s32 w = rect->w;
    s32 res = (u16)fn_8009E894(x, y);
    s32 rem;
    s32 px;

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
