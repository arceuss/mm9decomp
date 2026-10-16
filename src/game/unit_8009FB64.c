#include "types.h"

typedef struct Vec2i {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Vec2i;

typedef struct Unk8009FB64Ctx Unk8009FB64Ctx;

typedef struct Unk8009FB64Layer {
    /* 0x00 */ u8 pad0[0x4];
    /* 0x04 */ void (*draw)(struct Unk8009FB64Layer* layer, Unk8009FB64Ctx* ctx);
    /* 0x08 */ u8 pad8[0x2C - 0x8];
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ s32 unk30;
    /* 0x34 */ Vec2i pos;
    /* 0x3C */ u8 pad3C[0x94 - 0x3C];
} Unk8009FB64Layer;

typedef struct Unk8009FB64Cam {
    /* 0x00 */ u8 pad0[0x8];
    /* 0x08 */ s32 x;
    /* 0x0C */ s32 y;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
} Unk8009FB64Cam;

typedef struct Unk8009FB64Vtbl {
    /* 0x0 */ u8 pad0[0x8];
    /* 0x8 */ void (*update)(Unk8009FB64Cam* cam);
} Unk8009FB64Vtbl;

struct Unk8009FB64Ctx {
    /* 0x0 */ u8 pad0[0x4];
    /* 0x4 */ Unk8009FB64Vtbl* vtbl;
};

extern u8 lbl_8031BF70[];

s32 fn_8000EE1C(void* arg0);
s32 fn_8000EECC(void* arg0);
void fn_800E85D0(void* arg0, s32 arg1, s32 arg2);

void fn_8009FB64(void* arg0, Unk8009FB64Cam* cam) {
    Unk8009FB64Ctx* ctx = *(Unk8009FB64Ctx**)(lbl_8031BF70 + 0x288);
    Unk8009FB64Layer* layer;
    s32 i;
    Vec2i pos;
    Vec2i saved;
    s32 a;
    s32 b;

    ctx->vtbl->update(cam);
    layer = (Unk8009FB64Layer*)(lbl_8031BF70 + 0x20);
    pos.x = cam->x >> 8;
    pos.y = cam->y >> 8;
    for (i = 0; i < 4; i++, layer++) {
        layer->unk2C = cam->unk10;
        layer->unk30 = cam->unk14;
        saved = layer->pos;
        layer->pos = pos;
        if ((u32)layer->draw > 1) {
            layer->draw(layer, ctx);
        }
        layer->pos = saved;
    }
    a = fn_8000EE1C(*(void**)(lbl_8031BF70 + 0x7C));
    b = fn_8000EECC(*(void**)(lbl_8031BF70 + 0x7C));
    fn_800E85D0(lbl_8031BF70 + 0x4AED0, b, a);
    *(u16*)(lbl_8031BF70 + 0x4AEAE) = 0;
}
