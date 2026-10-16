#include "types.h"

typedef struct Unk80083BD8Glyph {
    /* 0x00 */ u8 pad0[0x4];
    /* 0x04 */ s8 left;
    /* 0x05 */ u8 width;
    /* 0x06 */ u8 pad6;
    /* 0x07 */ u8 height;
    /* 0x08 */ u8 pad8[0xC - 0x8];
    /* 0x0C */ u16 texWidth;
    /* 0x0E */ u16 texHeight;
    /* 0x10 */ u16 u;
    /* 0x12 */ u16 v;
} Unk80083BD8Glyph;

typedef struct Unk80083BD8Info {
    /* 0x0 */ u8 cellWidth;
    /* 0x1 */ u8 cellHeight;
} Unk80083BD8Info;

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

void fn_80083BD8(Unk80083BD8Glyph* glyph, Unk80083BD8Info* info, s16 x, s16 y, s32 w, s32 h, s16 z) {
    s16 x1 = x + glyph->left * w / info->cellWidth;
    s16 x2 = x1 + glyph->width * w / info->cellWidth;
    s16 y2 = y + glyph->height * h / info->cellHeight;
    s16 s0 = (glyph->u << 12) / glyph->texWidth;
    s16 s1 = ((glyph->u + glyph->width) << 12) / glyph->texWidth;
    s16 t0 = (glyph->v << 12) / glyph->texHeight;
    s16 t1 = ((glyph->v + glyph->height) << 12) / glyph->texHeight;

    fn_8011197C(0x80, 0, 4);
    GXPosition3s16(x1, y, z);
    GXTexCoord2s16(s0, t0);
    GXPosition3s16(x2, y, z);
    GXTexCoord2s16(s1, t0);
    GXPosition3s16(x2, y2, z);
    GXTexCoord2s16(s1, t1);
    GXPosition3s16(x1, y2, z);
    GXTexCoord2s16(s0, t1);
}
