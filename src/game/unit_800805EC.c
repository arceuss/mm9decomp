#include "types.h"

typedef struct Unk800805ECPos {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Unk800805ECPos;

typedef struct Unk800805EC {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ u16 unkC;
    /* 0x0E */ u8 padE[0x1D - 0xE];
    /* 0x1D */ u8 flags;
    /* 0x1E */ u8 pad1E[0x20 - 0x1E];
    /* 0x20 */ u8 unk20;
    /* 0x21 */ u8 pad21[0x26 - 0x21];
    /* 0x26 */ u16 unk26;
    /* 0x28 */ u8 pad28[0x38 - 0x28];
    /* 0x38 */ s32 x;
    /* 0x3C */ s32 y;
    /* 0x40 */ u8 pad40[0x50 - 0x40];
    /* 0x50 */ Unk800805ECPos* target;
    /* 0x54 */ s32 vx;
    /* 0x58 */ s32 vy;
    /* 0x5C */ s32 offX;
    /* 0x60 */ u8 pad60[0x64 - 0x60];
    /* 0x64 */ s32 offY;
} Unk800805EC;

void fn_8009E974(Unk800805ECPos* pos, Unk800805ECPos* adj, u16 id);
void fn_80080280(Unk800805EC* c, u8 flags);

static inline void Follow(s32* cur, s32 n, s32 v, s32 d) {
    s32 s = d != 0 ? ((d >> 31) * 2 + 1) : 0;
    s32 p = s * v;

    if (p <= 0) {
        *cur = n;
    } else if (d * s >= p) {
        *cur = n - v;
    }
}

void fn_800805EC(Unk800805EC* c) {
    Unk800805ECPos adj;
    Unk800805ECPos pos;
    s32 dx;
    s32 dy;
    s32 nx;
    s32 ny;
    u8 f;
    s32 d;
    u16 id = c->unkC;

    if (c->unk20 == 0) {
        c->unk26 = 0;
        c->unk20++;
    }
    dx = c->x - (c->target->x + c->offX);
    dy = c->y - (c->target->y + c->offY);
    pos.x = c->x;
    pos.y = c->y;
    if (dx > 0) {
        pos.x = c->x - dx;
    }
    if (dx < 0) {
        pos.x -= dx;
    }
    if (dy > -0x800) {
        pos.y -= dy + 0x800;
    }
    if (dy < -0x800) {
        pos.y -= dy + 0x800;
    }
    if (!(c->flags & 8)) {
        if (!(c->flags & 0x40)) {
            if (pos.x >= c->x + 0x8000) {
                pos.x = c->x + 0x7FFF;
            }
            if (pos.x <= c->x - 0x8000) {
                pos.x = c->x - 0x7FFF;
            }
        }
        if (!(c->flags & 0x80)) {
            if (pos.y >= c->y + 0x7000) {
                pos.y = c->y + 0x6FFF;
            }
            if (pos.y <= c->y - 0x7000) {
                pos.y = c->y - 0x6FFF;
            }
        }
    }
    fn_8009E974(&pos, &adj, id);
    nx = pos.x + adj.x;
    ny = pos.y + adj.y;
    if (c->flags & 8) {
        c->x = nx;
        c->y = ny;
    }
    f = c->flags;
    if (f & 0x40) {
        if (c->x + 0x400 < nx) {
            c->x += 0x400;
        } else if (c->x - 0x400 > nx) {
            c->x -= 0x400;
        } else {
            c->x = nx;
            c->flags = f & ~0x40;
        }
    } else if (f & 0x80) {
        if (c->y + 0x380 < ny) {
            c->y += 0x380;
        } else if (c->y - 0x380 > ny) {
            c->y -= 0x380;
        } else {
            c->y = ny;
            c->flags = f & 0x7F;
        }
    } else {
        if (f & 8) {
            c->vx = 0;
            c->vy = 0;
        }
        if (adj.x != 0) {
            d = nx - c->x;
            if (adj.x * d >= 0) {
                c->x = nx;
            } else {
                Follow(&c->x, nx, c->vx, d);
            }
        } else {
            Follow(&c->x, nx, c->vx, nx - c->x);
        }
        if (adj.y != 0) {
            d = ny - c->y;
            if (adj.y * d >= 0) {
                c->y = ny;
            } else {
                Follow(&c->y, ny, c->vy, d);
            }
        } else {
            Follow(&c->y, ny, c->vy, ny - c->y);
        }
    }
    c->vx = nx - c->x;
    c->vy = ny - c->y;
    fn_80080280(c, c->flags);
}
