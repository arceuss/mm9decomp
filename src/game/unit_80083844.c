#include "types.h"

typedef struct Unk80083844Tex {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ u16 width;
    /* 0x12 */ u16 height;
    /* 0x14 */ u8 pad14[0x1E - 0x14];
    /* 0x1E */ u16 texWidth;
    /* 0x20 */ u16 texHeight;
} Unk80083844Tex;

// write-gather pipe; the GX vertex inlines all store through it
#define GX_WGPIPE_S16 (*(volatile s16*)0xCC008000)

void fn_8011197C(s32 type, s32 fmt, u16 count);

static inline void GXPosition3s16(s16 x, s16 y, s16 z) {
    GX_WGPIPE_S16 = x;
    GX_WGPIPE_S16 = y;
    GX_WGPIPE_S16 = z;
}

static inline void GXTexCoord2s16(s16 s, s16 t) {
    GX_WGPIPE_S16 = s;
    GX_WGPIPE_S16 = t;
}

void fn_80083844(Unk80083844Tex* tex, s16 x, s16 y, s16 w, s16 h, s16 z, s32 u, s32 v) {
    s16 x2 = x + w;
    s16 y2 = y + h;
    s16 s0 = (u << 12) / tex->texWidth;
    s16 s1 = ((u + tex->width) << 12) / tex->texWidth;
    s16 t0 = (v << 12) / tex->texHeight;
    s16 t1 = ((v + tex->height) << 12) / tex->texHeight;

    fn_8011197C(0x80, 0, 4);
    GXPosition3s16(x, y, z);
    GXTexCoord2s16(s0, t0);
    GXPosition3s16(x2, y, z);
    GXTexCoord2s16(s1, t0);
    GXPosition3s16(x2, y2, z);
    GXTexCoord2s16(s1, t1);
    GXPosition3s16(x, y2, z);
    GXTexCoord2s16(s0, t1);
}
