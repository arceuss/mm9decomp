#include "types.h"
#include "game/work_8031BF70.h"

typedef struct Unk800B96E0Pos {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Unk800B96E0Pos;

typedef struct Unk800B96E0Rect {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
    /* 0x4 */ u16 w;
    /* 0x6 */ u16 h;
} Unk800B96E0Rect;

typedef struct Unk800B96E0Box {
    /* 0x00 */ Unk800B96E0Rect* rect;
    /* 0x04 */ u32 unk4;
    /* 0x08 */ u8 pad8[0x54 - 0x8];
    /* 0x54 */ u16 unk54;
} Unk800B96E0Box;

s32 fn_800A502C(u16 id);
void fn_800B7A28(void*, void*, void*, u32, u32, u32);

s32 fn_800B96E0(Unk800B96E0Pos* pos, Unk800B96E0Box* box, u32 dir) {
    s32 dx = 0;
    Unk800B96E0Pos prev = *pos;
    u16 id = fn_800A502C(box->unk54);
    u32 m;
    u32 side;

    if (id != 0xFFFF) {
        m = lbl_8031BF70.unk290[id].unk2 & 0x6000;
        if ((m == 0x4000) ^ (m == 0x2000)) {
            dx = lbl_8031BF70.unk290[id].unk8 - lbl_8031BF70.unk290[id].unk10;
            pos->x += dx;
            if (dx != 0) {
                if (((dir == 1) * 2 - 1) * ((dx >> 31) * 2 + 1) < 0) {
                    side = 3;
                } else {
                    side = 2;
                }
                fn_800B7A28(pos, &prev, box, (u32)box->rect, box->unk4, ((dir & 1) << 18) | (((side & 3) << 16) | 1) | 0x280000);
            }
        }
        pos->y = lbl_8031BF70.unk290[id].unkC - lbl_8031BF70.unk290[id].unk6 - 1 - (box->rect->h + box->rect->y);
        fn_800B7A28(pos, &prev, box, (u32)box->rect, box->unk4, ((dir & 1) << 18) | 0x290001);
    }
    return dx;
}
