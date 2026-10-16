#include "types.h"

typedef struct Unk800B8FB4Pos {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Unk800B8FB4Pos;

typedef struct Unk800B8FB4Box {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
    /* 0x4 */ u16 w;
    /* 0x6 */ u16 h;
} Unk800B8FB4Box;

u8 fn_8009E8E4(s32 x, s32 y);

s32 fn_800B8FB4(Unk800B8FB4Pos* pos, void* arg1, Unk800B8FB4Box* box, u32 flags) {
    s32 x;
    s32 y;
    s32 oldY;
    s32 ofs = flags & 0xFFFF;
    if (((flags >> 16) & 3) == 0) {
        ofs += box->h + box->y;
    } else if (((flags >> 16) & 3) == 1) {
        ofs += box->h - box->y;
        ofs -= ofs * 2;
    }
    oldY = pos->y;
    x = pos->x;
    y = oldY + ofs;
    if (fn_8009E8E4(x, y)) {
        do {
            y /= 0xE000;
            y *= 0xE000;
            y -= 1;
        } while (fn_8009E8E4(x, y));
    }
    y -= ofs;
    if ((flags >> 19) & 1) {
        pos->y = y;
    }
    return y - oldY;
}
