#include "types.h"

typedef struct Unk800D5E50 {
    /* 0x00 */ u8 pad0[0x20];
    /* 0x20 */ s16 x;
    /* 0x22 */ s16 y;
    /* 0x24 */ s16 w;
    /* 0x26 */ s16 h;
    /* 0x28 */ f32 u0;
    /* 0x2C */ f32 u1;
    /* 0x30 */ f32 v0;
    /* 0x34 */ f32 v1;
    /* 0x38 */ u8 depth;
} Unk800D5E50;

// write-gather pipe; the GX vertex inlines all store through it
#define GX_WGPIPE_U16 (*(volatile u16*)0xCC008000)
#define GX_WGPIPE_S16 (*(volatile s16*)0xCC008000)
#define GX_WGPIPE_F32 (*(volatile f32*)0xCC008000)

void fn_801108E4(void);
void fn_80112FC4(void* tex, s32 map);
void fn_80110918(s32 fmt, s32 attr, s32 cnt, s32 type, s32 frac);
void fn_801104A4(s32 attr, s32 type);
void fn_80110D4C(s32 dst, s32 type, s32 src, s32 mtx, s32 norm, s32 pt);
void fn_80113BB0(s32 arg0, s32 arg1);
void fn_801140B0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void fn_80110F74(s32 arg0);
void fn_801127DC(s32 arg0);
void fn_80112800(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
void fn_8011197C(s32 type, s32 fmt, u16 count);

static inline void GXPosition3s16(s16 x, s16 y, s16 z) {
    GX_WGPIPE_S16 = x;
    GX_WGPIPE_S16 = y;
    GX_WGPIPE_S16 = z;
}

static inline void GXColor1u16(u16 c) {
    GX_WGPIPE_U16 = c;
}

static inline void GXTexCoord2f32(f32 s, f32 t) {
    GX_WGPIPE_F32 = s;
    GX_WGPIPE_F32 = t;
}

void fn_800D5E50(Unk800D5E50* p, u32 level) {
    u16 color;
    s16 x;
    s16 y;
    s16 w;
    s16 h;
    s16 z;

    fn_801108E4();
    fn_80112FC4(p, 0);
    fn_80110918(0, 9, 1, 3, 0);
    fn_801104A4(9, 1);
    fn_80110918(0, 0xB, 0, 0, 0);
    fn_801104A4(0xB, 1);
    fn_80110918(0, 0xD, 1, 4, 0);
    fn_801104A4(0xD, 1);
    fn_80110D4C(0, 1, 4, 0x3C, 0, 0x7D);
    if (level >= 0x20) {
        color = 0xFFFF;
    } else {
        color = ((level & 0x1F) << 11) | ((level & 0x1F) << 6) | (level & 0x1F);
    }
    fn_80113BB0(0, 0);
    fn_801140B0(0, 0, 0, 4);
    fn_80110F74(1);
    fn_801127DC(1);
    fn_80112800(4, 0, 1, 1, 0, 0, 2);
    z = p->depth * 100 / 4;
    w = p->w;
    h = p->h;
    x = p->x;
    y = p->y;
    fn_8011197C(0x80, 0, 4);
    GXPosition3s16(x - (w >> 1), y + ((h & 1) + (h >> 1)), z);
    GXColor1u16(color);
    GXTexCoord2f32(p->u0, p->v1);
    GXPosition3s16(x - (w >> 1), y - (h >> 1), z);
    GXColor1u16(color);
    GXTexCoord2f32(p->u0, p->v0);
    GXPosition3s16(x + ((w & 1) + (w >> 1)), y - (h >> 1), z);
    GXColor1u16(color);
    GXTexCoord2f32(p->u1, p->v0);
    GXPosition3s16(x + ((w & 1) + (w >> 1)), y + ((h & 1) + (h >> 1)), z);
    GXColor1u16(color);
    GXTexCoord2f32(p->u1, p->v1);
}
