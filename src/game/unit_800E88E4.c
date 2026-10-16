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

s32 fn_800E88E4(Vec2i* out, Vec2i* pos) {
    u32 i;

    for (i = 0; i < 9; i++) {
        if ((u32)(lbl_80281EB0[i].pos.x - pos->x + 0x2000) <= 0x2000 &&
            (u32)(lbl_80281EB0[i].pos.y - pos->y + 0x2000) <= 0x2000) {
            break;
        }
    }
    if (i == 9) {
        return -1;
    }
    out->x = lbl_80281EB0[i].out.x;
    out->y = lbl_80281EB0[i].out.y;
    return i;
}
