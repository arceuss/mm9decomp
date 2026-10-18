#include "types.h"

typedef struct Unk800E7C10 {
    /* 0x0 */ struct {
        u32 pad : 24;
        u32 sx : 3;
        u32 sy : 3;
        u32 pad2 : 2;
    } fmt;
    /* 0x4 */ struct {
        s32 a : 10;
        s32 b : 10;
        u32 c : 1;
        u32 d : 1;
        u32 pad : 10;
    } pos;
} Unk800E7C10;

#define GX_WRITE_S16(v) (*(volatile s16*)0xCC008000 = (v))

void fn_80112FC4(void* tex, s32 id);
void fn_8011197C(s32 prim, s32 fmt, u16 n);

void fn_800E7C10(Unk800E7C10* t, void* tex, s32 p) {
    s32 one;
    s32 sx;
    s32 sy;
    s32 b;
    s32 a;
    s16 x0;
    s16 y0;
    s16 y1;
    s16 x1;

    fn_80112FC4(tex, 0);
    one = 1;
    sx = t->fmt.sx + 3;
    sy = t->fmt.sy + 3;
    a = t->pos.a + p;
    b = t->pos.b;
    x0 = p + (one << sx) * t->pos.c;
    y0 = (one << sy) * t->pos.d;
    y1 = y0 + (one << sy);
    x1 = x0 + 1;
    x0 <<= 12 - sx;
    y0 <<= 12 - sy;
    y1 <<= 12 - sy;
    x1 <<= 12 - sx;
    fn_8011197C(0xA8, 0, 2);
    GX_WRITE_S16(b);
    GX_WRITE_S16(a + 9);
    GX_WRITE_S16(y0);
    GX_WRITE_S16(x0);
    GX_WRITE_S16(b + (one << (t->fmt.sy + 3)));
    GX_WRITE_S16(a + 9);
    GX_WRITE_S16(y1);
    GX_WRITE_S16(x1);
}
