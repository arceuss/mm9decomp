#include "types.h"

typedef struct Unk800B8B44 {
    /* 0x00 */ u8 pad0[0x1C];
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 hit[3][2];
    /* 0x3C */ u8 pad3C[0x44 - 0x3C];
    /* 0x44 */ u16 tile[4];
    /* 0x4C */ u16 flags[4];
} Unk800B8B44;

static inline u32 SolidFlag(u32 f, u32 tile) {
    if ((tile & 0x800) == 0x800) {
        f |= 0x800;
    } else {
        f |= 1;
    }
    return f;
}

static inline u32 SlopeBit(u32 f, u32 slope) {
    if (slope == 0x4000) {
        f |= 0x4000;
    } else {
        f |= 0x2000;
    }
    return f;
}

static inline u32 TileFlags(u32 tile, s32 axis) {
    u32 f;
    u32 slope;

    if (axis == 0) {
        f = SolidFlag(0, tile);
        slope = tile & 0x6000;
        if ((slope == 0x4000) ^ (slope == 0x2000)) {
            f = SlopeBit(f, slope);
        }
    } else if (axis == 1) {
        f = SolidFlag(0, tile);
    } else {
        f = SolidFlag(0, tile);
    }
    return f;
}

u16 fn_800B8B44(Unk800B8B44* c, s32 x, s32 y, u32 tile, s32 axis) {
    u16 old = c->flags[axis];
    u16 f = TileFlags(tile, axis);

    if (axis == 0 && (f & 0x6000) && !(old & 0x6000)) {
        c->unk1C = x;
        c->unk20 = y;
    }
    f |= old;
    c->flags[axis] = f;
    if (c->tile[axis] == 0) {
        c->tile[axis] = tile;
        c->hit[axis][0] = x;
        c->hit[axis][1] = y;
    }
    return f;
}
