#include "types.h"

typedef struct Vec2i {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Vec2i;

typedef struct Unk800809B8 {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ u16 unkC;
    /* 0x0E */ u8 padE[0x1D - 0xE];
    /* 0x1D */ u8 flags1D;
    /* 0x1E */ u8 pad1E[0x20 - 0x1E];
    /* 0x20 */ u8 unk20;
    /* 0x21 */ u8 pad21[0x26 - 0x21];
    /* 0x26 */ s16 t;
    /* 0x28 */ u8 pad28[0x38 - 0x28];
    /* 0x38 */ Vec2i target;
    /* 0x40 */ Vec2i cur;
    /* 0x48 */ u8 pad48[0x50 - 0x48];
    /* 0x50 */ Vec2i* focus;
    /* 0x54 */ u8 pad54[0x5C - 0x54];
    /* 0x5C */ s32 offX;
    /* 0x60 */ u8 pad60[0x64 - 0x60];
    /* 0x64 */ s32 offY;
    /* 0x68 */ u8 pad68[0x6C - 0x68];
    /* 0x6C */ s32 minX;
    /* 0x70 */ s32 maxX;
    /* 0x74 */ s32 minY;
    /* 0x78 */ s32 maxY;
} Unk800809B8;

void fn_8009E974(Vec2i* pos, Vec2i* off);
void fn_80080280(Unk800809B8* c, s32 mode);

void fn_800809B8(Unk800809B8* c) {
    u16 unused = c->unkC;
    s32 px;
    s32 py;
    s32 d;
    s32 nx;
    s32 ny;
    Vec2i off;
    Vec2i p;

    if (c->unk20 == 0) {
        c->t = 0;
        c->unk20++;
    }
    px = c->focus->x + c->offX;
    py = c->focus->y + c->offY;
    p = c->target;
    if ((d = c->target.x - px) > 0) {
        p.x -= d;
    }
    if ((d = c->target.x - px) < 0) {
        p.x -= d;
    }
    if ((d = c->target.y - py) > -0x1000) {
        p.y -= d + 0x1000;
    }
    if ((d = c->target.y - py) < -0x1800) {
        p.y -= d + 0x1800;
    }
    fn_8009E974(&p, &off);
    if (c->flags1D & 0x10) {
        nx = p.x;
    } else {
        nx = p.x + off.x;
    }
    ny = p.y + off.y;
    if (nx - 0x8000 < c->minX) {
        nx = c->minX + 0x8000;
    }
    if (nx + 0x8000 > c->maxX) {
        nx = c->maxX - 0x8000;
    }
    if (ny - 0x7000 < c->minY) {
        ny = c->minY + 0x7000;
    }
    if (ny + 0x7000 > c->maxY) {
        ny = c->maxY - 0x7000;
    }
    if (c->flags1D & 8) {
        c->target.y = ny;
        c->target.x = nx;
    } else {
        if (c->target.x + 0x400 < nx) {
            c->target.x += 0x400;
        } else if (c->target.x - 0x400 > nx) {
            c->target.x -= 0x400;
        } else {
            c->target.x = nx;
        }
        if (c->target.y + 0x380 < ny) {
            c->target.y += 0x380;
        } else if (c->target.y - 0x380 > ny) {
            c->target.y -= 0x380;
        } else {
            c->target.y = ny;
        }
    }
    fn_80080280(c, c->flags1D);
}
