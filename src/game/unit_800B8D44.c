#include "types.h"

typedef struct Unk800B8D44A {
    /* 0x0 */ u8 pad0[0x4];
    /* 0x4 */ s32 y;
} Unk800B8D44A;

typedef struct Unk800B8D44B {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ s32 top;
    /* 0x14 */ u8 pad14[0x18 - 0x14];
    /* 0x18 */ s32 bottom;
} Unk800B8D44B;

typedef struct Unk800B8D44C {
    /* 0x0 */ u8 pad0[0x2];
    /* 0x2 */ s16 offset;
    /* 0x4 */ u8 pad4[0x6 - 0x4];
    /* 0x6 */ u16 half;
} Unk800B8D44C;

s32 fn_800B8D44(Unk800B8D44A* a, Unk800B8D44B* b, Unk800B8D44C* c, u32 flags) {
    s32 dir = (flags >> 16) & 3;
    s32 margin = flags & 0xFFFF;
    s32 lo;
    s32 range;
    s32 d;
    s32 hi;

    if (b->top >= b->bottom) {
        return 0;
    }
    lo = b->top + (c->half - c->offset);
    hi = b->bottom - (c->half + c->offset);
    lo += margin;
    hi -= margin;
    range = hi - lo;
    d = a->y - lo;
    if ((u32)d <= (u32)range) {
        d = 0;
    } else {
        if (d > range) {
            d -= range;
        }
        if (dir == 0) {
            if (d < 0) {
                d = 0;
            }
        } else if (d > 0) {
            d = 0;
        }
        if (flags & 0x80000) {
            a->y -= d;
        }
    }
    return d;
}
