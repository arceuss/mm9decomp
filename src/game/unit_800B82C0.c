#include "types.h"

typedef struct Unk800B82C0Pos {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Unk800B82C0Pos;

typedef struct Unk800B82C0Rect {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
    /* 0x4 */ u16 w;
    /* 0x6 */ u16 h;
} Unk800B82C0Rect;

typedef struct Unk800B82C0Obj {
    /* 0x00 */ u8 pad0[0x4];
    /* 0x04 */ Unk800B82C0Rect* rect;
    /* 0x08 */ u8 pad8[0x54 - 0x8];
    /* 0x54 */ u16 unk54;
} Unk800B82C0Obj;

s32 fn_800A502C(u16 id);
u32 fn_8009E894(s32 x, s32 y);

s32 fn_800B82C0(Unk800B82C0Pos* a, Unk800B82C0Pos* b, Unk800B82C0Obj* obj, Unk800B82C0Rect* rect, s32 x, s32 top,
                u32 attr, s32 dy, u32 flags) {
    s32 ay = a->y;
    s32 by = b->y;
    s32 bx = b->x;
    s32 diff = ay - by;
    u32 kind = attr >> 21;
    s32 lim = (u16)attr + 0x1000;

    if ((flags & 0x400) == 0x400) {
        if (kind == 0 && rect->h + rect->y + ay <= top + dy) {
            return dy;
        }
        return 1;
    }
    if ((flags & 0xF) - 3 <= 1) {
        if (kind == 1 || (u16)fn_800A502C(obj->unk54) != 0xFFFF) {
            if (diff >= 0 && top + dy > by + (obj->rect->y + obj->rect->h)) {
                return dy;
            }
            return 0;
        }
        if ((fn_8009E894(bx + (x - a->x), by) & 0xF) - 3 <= 1) {
            return 0;
        }
        if (diff < 0) {
            return 0;
        }
    }
    if (dy <= -lim) {
        return 0;
    }
    return dy;
}
