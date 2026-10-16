#include "types.h"

typedef struct UnkScanPos {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} UnkScanPos;

typedef struct UnkScanBox {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
    /* 0x4 */ u16 w;
    /* 0x6 */ u16 h;
} UnkScanBox;

u32 fn_8009E894(s32 x, s32 y);

u16 fn_800B9BA8(UnkScanPos* pos, UnkScanBox* box, s32 dir) {
    s32 sign;
    s32 d;
    u16 bits;
    s32 y;
    s32 x;
    s32 cy;
    s32 rem;
    s32 h;

    sign = (dir == 1) * 2 - 1;
    x = pos->x + (box->w + box->x) * sign;
    y = box->y + pos->y;
    h = box->h;
    bits = fn_8009E894(x, y);
    for (rem = h, cy = y, d = h; rem > 0; rem -= 0x1000, d -= 0x1000) {
        cy = rem > 0x1000 ? cy + 0x1000 : cy + d;
        bits |= fn_8009E894(x, cy);
    }
    for (d = -h; h > 0; h -= 0x1000, d += 0x1000) {
        y = h > 0x1000 ? y - 0x1000 : y + d;
        bits |= fn_8009E894(x, y);
    }
    return bits;
}
