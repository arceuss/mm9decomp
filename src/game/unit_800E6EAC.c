#include "types.h"

typedef struct Unk8039B190 {
    /* 0x00 */ u8* bufs[4];
    /* 0x10 */ u8 texObjs[4][0x20];
} Unk8039B190;

typedef struct Unk80301280Table {
    /* 0x0 */ u8 pad0[0x8];
    /* 0x8 */ u16 unk8[1];
} Unk80301280Table;

typedef struct Unk80301280 {
    /* 0x00 */ u8 pad0[0x40];
    /* 0x40 */ Unk80301280Table* unk40;
} Unk80301280;

extern Unk8039B190 lbl_8039B190;
extern Unk80301280 lbl_80301280;

// write-gather pipe; the GX vertex inlines all store through it
#define GX_WGPIPE_S16 (*(volatile s16*)0xCC008000)

void fn_80112FC4(void* tex, s32 map);
void fn_8011197C(s32 type, s32 fmt, u16 count);

static inline void GXPosition2s16(s16 x, s16 y) {
    GX_WGPIPE_S16 = x;
    GX_WGPIPE_S16 = y;
}

static inline void GXTexCoord2s16(s16 s, s16 t) {
    GX_WGPIPE_S16 = s;
    GX_WGPIPE_S16 = t;
}

void fn_800E6EAC(s32 id, s32 y, s32 u, s32 v) {
    u16 flags;
    u32 w;
    u32 h;
    s32 ss;
    s32 ts;
    s16 s0;
    s16 t0;
    s16 s1;
    s16 t1;

    fn_80112FC4(lbl_8039B190.texObjs[(id >> 4) & 0xF], 0);
    flags = lbl_80301280.unk40->unk8[id >> 4];
    w = 0x100 << ((flags >> 14) & 1);
    h = 0x100 << ((flags & 0xC000) >> 15);
    u = (s16)(u & (w - 1));
    v = (s16)(v & (h - 1));
    ss = 0xC - ((w >> 9) + 8);
    ts = 0xC - ((h >> 9) + 8);
    s0 = u << ss;
    t0 = v << ts;
    s1 = (s16)(u + 0x100) << ss;
    t1 = (s16)(v + 1) << ts;
    fn_8011197C(0xA8, 0, 2);
    GXPosition2s16(0, y + 9);
    GXTexCoord2s16(s0, t0);
    GXPosition2s16(0x100, y + 9);
    GXTexCoord2s16(s1, t1);
}
