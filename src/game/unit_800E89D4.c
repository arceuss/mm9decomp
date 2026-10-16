#include "types.h"

typedef struct Vec2i {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Vec2i;

typedef struct Unk80281EB0 {
    /* 0x0 */ Vec2i pos;
    /* 0x8 */ Vec2i out;
} Unk80281EB0;

extern Unk80281EB0 lbl_80281EB0[9];

s32 fn_800E89D4(Vec2i* out, Vec2i* pos) {
    u32 i;
    u32 x;
    u32 y;

    for (i = 0; i < 9; i++) {
        x = lbl_80281EB0[i].out.x - lbl_80281EB0[i].out.x % 0x10000;
        y = lbl_80281EB0[i].out.y - lbl_80281EB0[i].out.y % 0xE000;
        if (pos->x - x <= 0x10000 && pos->y - y <= 0xE000) {
            break;
        }
    }
    if (i == 9) {
        return -1;
    }
    out->x = lbl_80281EB0[i].pos.x;
    out->y = lbl_80281EB0[i].pos.y;
    return i;
}
