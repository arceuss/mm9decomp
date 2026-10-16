#include "types.h"

typedef struct Unk800B7E34Pos {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Unk800B7E34Pos;

typedef struct Unk800B7E34Box {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
    /* 0x4 */ u16 w;
    /* 0x6 */ u16 h;
} Unk800B7E34Box;

s32 fn_800A36F8(s32 x, s32 y);
u16 fn_8009E894(s32 x, s32 y);
s32 fn_800B82C0(Unk800B7E34Pos* pos, void* obj, void* ctx, Unk800B7E34Box* box, s32 x, s32 y, u32 flags, s32 d,
                u32 tile);
u32 fn_800B8B44(void* ctx, s32 x, s32 y, u32 tile, s32 arg4);

u32 fn_800B7E34(Unk800B7E34Pos* pos, void* obj, void* ctx, Unk800B7E34Box* box, u32 flags) {
    s32 dir = ((flags >> 17) & 2) - 1;
    s32 offs[3];
    s32 y;
    s32 x;
    s32 d;
    u32 ret;
    u32 res;
    s32 i;
    s32* off;

    offs[0] = 0;
    offs[1] = box->w * dir;
    offs[2] = box->w * -dir;
    y = pos->y + box->h + box->y + (flags & 0xFFFF);
    ret = 0;
    res = 0;
    for (i = 0, off = offs; i < 3; i++, off++) {
        if (ret != 0) {
            continue;
        }
        x = pos->x + box->x + *off;
        d = fn_800A36F8(x, y);
        if (d < 0) {
            ret = fn_8009E894(x, y);
            d = fn_800B82C0(pos, obj, ctx, box, x, y, flags, d, ret);
            if (d < 0) {
                res |= fn_800B8B44(ctx, x, y, ret, 0);
                if (flags & 0x80000) {
                    y += d;
                    flags &= ~0x80000;
                    pos->y = y - (box->h + box->y);
                }
            }
        }
        if (flags & 0x100000) {
            ret = 0;
        }
    }
    if (flags & 0x100000) {
        ret = res;
    }
    return ret;
}
