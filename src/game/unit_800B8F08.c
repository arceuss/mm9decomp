#include "types.h"

typedef struct Unk800B8F08Pos {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Unk800B8F08Pos;

typedef struct Unk800B8F08Box {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
    /* 0x4 */ u16 w;
    /* 0x6 */ u16 h;
} Unk800B8F08Box;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x260];
    /* 0x260 */ s32 unk260;
    /* 0x264 */ u8 pad264[0x300 - 0x264];
} Unk80304B90;

extern Unk80304B90 lbl_80304B90;

s32 fn_800B8F08(Unk800B8F08Pos* pos, void* arg1, Unk800B8F08Box* box, u32 flags) {
    s32 limit;
    s32 ofs = flags & 0xFFFF;
    s32 y;
    s32 oldY;
    if (((flags >> 16) & 3) == 0) {
        ofs += box->h + box->y;
    } else if (((flags >> 16) & 3) == 1) {
        ofs += box->h - box->y;
        ofs -= ofs * 2;
    }
    oldY = pos->y;
    y = oldY + ofs;
    limit = lbl_80304B90.unk260 - 0x7000;
    if (limit > y) {
        do {
            y /= 0xE000;
            y += 1;
            y *= 0xE000;
        } while (limit > y);
    }
    y -= ofs;
    if ((flags >> 19) & 1) {
        pos->y = y;
    }
    return y - oldY;
}
