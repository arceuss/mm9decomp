#include "types.h"

typedef struct Vec2i {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Vec2i;

typedef struct Unk80080280 {
    /* 0x00 */ u8 pad0[0x1D];
    /* 0x1D */ u8 flags1D;
    /* 0x1E */ u8 pad1E[0x26 - 0x1E];
    /* 0x26 */ s16 t;
    /* 0x28 */ u8 pad28[0x38 - 0x28];
    /* 0x38 */ Vec2i target;
    /* 0x40 */ Vec2i cur;
} Unk80080280;

void fn_80080280(Unk80080280* c, s32 mode) {
    s32 d;
    s32 t;

    switch (mode) {
    default:
        c->flags1D &= ~8;
    case 0:
        c->cur = c->target;
        return;
    case 1:
        d = c->target.x - c->cur.x;
        if (d > 0) {
            c->cur.x += (d + 0x1F) >> 5;
        } else {
            c->cur.x -= (0x1F - d) >> 5;
        }
        d = c->target.y - c->cur.y;
        if (d > 0) {
            c->cur.y += (d + 0x1F) >> 5;
        } else {
            c->cur.y -= (0x1F - d) >> 5;
        }
        return;
    case 2:
        if (c->t >= 0x3FF) {
            c->cur = c->target;
            return;
        }
        t = ++c->t;
        c->cur.x = ((c->cur.x >> 2) * (0x400 - t) + (c->target.x >> 2) * t) / 256;
        c->cur.y = ((c->cur.y >> 2) * (0x400 - t) + (c->target.y >> 2) * t) / 256;
        if ((u32)(c->cur.x - c->target.x + 0x80) <= 0x100) {
            c->cur.x = c->target.x;
        }
        if ((u32)(c->cur.y - c->target.y + 0x80) <= 0x100) {
            c->cur.y = c->target.y;
        }
        return;
    case 4:
        if (c->t >= 0xFF) {
            c->cur = c->target;
            return;
        }
        t = ++c->t;
        c->cur.x = (c->cur.x * (0x100 - t) + c->target.x * t) / 256;
        c->cur.y = (c->cur.y * (0x100 - t) + c->target.y * t) / 256;
        if ((u32)(c->cur.x - c->target.x + 0x80) <= 0x100) {
            c->cur.x = c->target.x;
        }
        if ((u32)(c->cur.y - c->target.y + 0x80) <= 0x100) {
            c->cur.y = c->target.y;
        }
        return;
    }
}
