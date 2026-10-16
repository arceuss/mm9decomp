#include "types.h"

typedef struct Vec2i {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Vec2i;

typedef struct Unk800E689CSrc {
    /* 0x0 */ Vec2i* a;
    /* 0x4 */ Vec2i* b;
    /* 0x8 */ u8 pad8[0xC - 0x8];
    /* 0xC */ u16 unkC;
} Unk800E689CSrc;

typedef struct Unk800E689C {
    /* 0x00 */ Vec2i a;
    /* 0x08 */ Vec2i center;
    /* 0x10 */ Vec2i b;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u16 unk1C;
} Unk800E689C;

void fn_800E689C(Unk800E689C* out, Unk800E689CSrc* src, s32 arg2) {
    if (src != NULL) {
        out->a.x = src->a->x;
        out->a.y = src->a->y;
        out->center.x = ((src->a->x >> 8) + (src->b->x >> 8) - 0x80) << 8;
        out->center.y = ((src->a->y >> 8) + (src->b->y >> 8) - 0x70) << 8;
        out->b.x = src->b->x;
        out->b.y = src->b->y;
        out->unk1C = src->unkC;
    } else {
        out->a.y = 0;
        out->a.x = 0;
        out->center.y = 0;
        out->center.x = 0;
        out->b.y = 0;
        out->b.x = 0;
        out->unk1C = 0x100;
    }
    out->unk18 = arg2;
}
