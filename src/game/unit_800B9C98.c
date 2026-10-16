#include "types.h"

typedef struct Vec2i {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Vec2i;

typedef struct Unk800B9C98Box {
    /* 0x0 */ s16 unk0;
    /* 0x2 */ s16 unk2;
    /* 0x4 */ u16 unk4;
    /* 0x6 */ u16 unk6;
} Unk800B9C98Box;

s32 fn_800A3CD4(s32 x, s32 y);
s32 fn_800A3FAC(s32 x, s32 y);

BOOL fn_800B9C98(Vec2i* pos, s32 x, Unk800B9C98Box* box) {
    s32 offs[3];
    s32 dx;
    s32 dir;
    BOOL right;
    BOOL hit;
    s32 d;
    s32 step;
    s32 i;
    s32 tx;
    s32 ty;
    s32 r;

    offs[0] = 0;
    hit = FALSE;
    d = 0;
    dx = x - pos->x;
    offs[1] = box->unk6;
    dir = ((dx >> 31) << 1) + 1;
    offs[2] = -box->unk6;
    right = dx > 0;
    dx *= dir;
    do {
        d += 0x1000;
        if (d > dx) {
            d = dx;
        }
        step = d * dir;
        for (i = 0; i < 3; i++) {
            tx = pos->x + step;
            ty = pos->y + box->unk2 + offs[i];
            if (right) {
                r = fn_800A3CD4(tx, ty);
            } else {
                r = fn_800A3FAC(tx, ty);
            }
            if (r * dir < 0) {
                hit = TRUE;
            }
        }
    } while (!hit && d < dx);
    return hit;
}
