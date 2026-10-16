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

u16 fn_800B9AB8(UnkScanPos* pos, UnkScanBox* box, s32 dir) {
    s32 sign = (dir == 1) * 2 - 1;
    s32 x = pos->x + (box->w - box->x) * sign;
    s32 y = box->y + pos->y;
    s32 h = box->h;
    u16 bits = fn_8009E894(x, y);
    s32 rem;
    s32 cy;
    s32 d;

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
