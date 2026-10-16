#include "types.h"

typedef struct Unk800B93B8Pos {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Unk800B93B8Pos;

typedef struct Unk800B93B8Box {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
    /* 0x4 */ u16 w;
    /* 0x6 */ u16 h;
} Unk800B93B8Box;

u32 fn_8009E894(s32 x, s32 y);

u16 fn_800B93B8(Unk800B93B8Pos* pos, Unk800B93B8Box* box, u32 flags) {
    s32 y = pos->y;
    s32 ofs;
    u32 side = (flags >> 16) & 3;
    u32 tile;
    u16 result;

    if (side == 1) {
        ofs = box->y;
    } else {
        ofs = box->h + box->y;
    }
    y += ofs;
    tile = fn_8009E894(pos->x, y);
    result = tile;
    if ((tile & 0xF) != 2 && (tile & 0xF) != 3) {
        result = 0;
        if ((flags >> 19) & 1) {
            y &= ~0xFFF;
            pos->y = (side == 1 ? y + 0x1000 : y - 1) - ofs;
        }
    }
    return result;
}
