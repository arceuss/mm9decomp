#include "types.h"

typedef struct Unk8009FC6CPos {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Unk8009FC6CPos;

typedef struct Unk8009FC6CInfo {
    /* 0x0 */ u8 pad0[0x4];
    /* 0x4 */ u16 w;
    /* 0x6 */ u16 h;
} Unk8009FC6CInfo;

typedef struct Unk8009FC6CMap {
    /* 0x0 */ u16 shift;
    /* 0x2 */ u8 pad2[0x8 - 0x2];
    /* 0x8 */ u16 cells[1];
} Unk8009FC6CMap;

typedef struct Unk8009FC6CPair {
    /* 0x0 */ s32 a;
    /* 0x4 */ s32 b;
} Unk8009FC6CPair;

typedef struct Unk8009FC6CCtx {
    /* 0x00 */ u8 pad0[0x24];
    /* 0x24 */ u32 unk24;
    /* 0x28 */ s32 unk28[4];
    /* 0x38 */ s32 unk38[4];
    /* 0x48 */ s32 unk48[4];
    /* 0x58 */ s32 unk58[4];
    /* 0x68 */ s32 unk68[4];
    /* 0x78 */ s32 unk78[4];
    /* 0x88 */ Unk8009FC6CPair unk88[4];
    /* 0xA8 */ Unk8009FC6CPair unkA8[4];
    /* 0xC8 */ Unk8009FC6CInfo* info;
    /* 0xCC */ u8 padCC[0xEC - 0xCC];
    /* 0xEC */ u32* tbl;
    /* 0xF0 */ Unk8009FC6CMap* map;
} Unk8009FC6CCtx;

typedef struct Unk8009FC6C {
    /* 0x00 */ u32 a;
    /* 0x04 */ u32 b;
    /* 0x08 */ void (*func)(struct Unk8009FC6C* obj, Unk8009FC6CCtx* ctx);
    /* 0x0C */ u16 layer;
    /* 0x0E */ u8 unkE;
    /* 0x0F */ u8 unkF;
    /* 0x10 */ u16 unk10;
    /* 0x12 */ u16 unk12;
    /* 0x14 */ u8 pad14[0x34 - 0x14];
    /* 0x34 */ s32 x;
    /* 0x38 */ s32 y;
    /* 0x3C */ s32 px;
    /* 0x40 */ s32 py;
    /* 0x44 */ s32 unk44;
    /* 0x48 */ s32 unk48;
    /* 0x4C */ s32 unk4C;
    /* 0x50 */ s32 unk50;
    /* 0x54 */ s32 unk54;
    /* 0x58 */ s32 unk58;
    /* 0x5C */ s32 unk5C;
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ s32 unk70;
} Unk8009FC6C;

typedef struct Unk80301280 {
    /* 0x00 */ u8 pad0[0x40];
    /* 0x40 */ u32* unk40;
} Unk80301280;

extern Unk80301280 lbl_80301280;
extern u8 lbl_8027D2D8[];

void fn_8000EE80(s32 a, s32 b, s32 c);

void fn_8009FC6C(Unk8009FC6C* obj, Unk8009FC6CCtx* ctx, Unk8009FC6CPos* pos) {
    u32 layer;
    u32 a;
    u32 b;
    u32 c;
    u32 tx;
    u32 ty;
    int n;
    u32 v;
    u32 i;

    obj->px = obj->x;
    obj->py = obj->y;
    obj->unk54 = obj->unk4C;
    obj->unk58 = obj->unk50;
    layer = obj->layer;
    obj->x = pos->x >> 8;
    obj->y = pos->y >> 8;
    tx = obj->x >> 8;
    ty = lbl_8027D2D8[obj->y >> 4];
    if (tx >= ctx->info->w || ty >= ctx->info->h) {
        a = obj->a;
        b = obj->b;
        c = (u32)obj->func;
    } else {
        i = tx + (ty << ctx->map->shift) + 4;
        v = ((u16*)ctx->map)[i] >> ((3 - layer) * 4);
        n = (v & 0xF) * 4 - (v & 0xF);
        a = ctx->tbl[n];
        b = ctx->tbl[n + 1];
        c = ctx->tbl[n + 2];
    }
    if (obj->a == a && obj->b == b) {
        return;
    }
    if (obj->func != NULL) {
        obj->func(obj, ctx);
    }
    *lbl_80301280.unk40 = (*lbl_80301280.unk40 & ~7) | ctx->unk24;
    obj->a = a;
    obj->b = b;
    obj->func = (void (*)(Unk8009FC6C*, Unk8009FC6CCtx*))c;
    obj->unk5C = ctx->unk28[layer];
    obj->unk60 = ctx->unk38[layer];
    obj->unk64 = ctx->unk48[layer];
    obj->unk68 = ctx->unk58[layer];
    obj->unk6C = ctx->unk68[layer];
    obj->unk70 = ctx->unk78[layer];
    obj->unk44 = ctx->unk88[layer].a;
    obj->unk48 = ctx->unk88[layer].b;
    obj->unk4C = ctx->unkA8[layer].a;
    obj->unk50 = ctx->unkA8[layer].b;
    if (a != 0 || b != 0) {
        *(u16*)&((u8*)lbl_80301280.unk40)[(obj->unk5C >> 4) * 2 + 8] =
            obj->unk68 | (obj->unk60 | (obj->unk5C <= 0x12 ? obj->unk70 : 0x2000)) | 0x4040;
        fn_8000EE80(obj->unk5C, obj->unk6C, obj->unk64);
        *lbl_80301280.unk40 |= (obj->unk5C & 0xF) << 8;
    } else {
        *lbl_80301280.unk40 &= ((obj->unk5C & 0xF) << 8) ^ 0xFFFFFFFF;
    }
    obj->px = obj->py = 0x80000001;
    obj->unk54 = obj->unk58 = 0x80000001;
    obj->unkE = obj->unkF = 0;
    obj->unk10 = obj->unk12 = 0;
}
