#include "types.h"
#include "game/work_8031BF70.h"

typedef struct Unk800B9458Pos {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Unk800B9458Pos;

typedef struct Unk800B9458Rect {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
    /* 0x4 */ u16 w;
    /* 0x6 */ u16 h;
} Unk800B9458Rect;

s32 fn_8009E894(s32 x, s32 y);

s32 fn_800B9458(Unk800B9458Pos* pos, Unk800B9458Rect* rect, s32 height) {
    s32 below = 0;
    s32 sum = 0;
    s32 h = height;
    s32 x;
    s32 y;
    s32 bot;
    s32 top;
    s32 end;
    s32 pct;
    u32 t;

    if (h == 0) {
        h = rect->h * 2;
    }
    bot = pos->y + rect->h;
    bot = rect->y + bot;
    x = pos->x;
    top = bot - h;
    if (bot >= lbl_8031BF70.unk4AEB8) {
        below = bot - lbl_8031BF70.unk4AEB8;
        if (top >= lbl_8031BF70.unk4AEB8) {
            below = h;
        }
    }
    if (below != h) {
        y = bot + 0x1000;
        do {
        do {
            y -= 0x1000;
            if (y < top) {
                y = top;
            }
            t = fn_8009E894(x, y) & 0x8000;
        } while (t != 0x8000 && y > top);
        if (t == 0x8000) {
            end = y & ~0xFFF;
            end += 0xFFF;
            if (end > bot) {
                end = bot;
            }
            do {
                y -= 0x1000;
                if (y < top) {
                    y = top - 1;
                }
                t = fn_8009E894(x, y) & 0x8000;
            } while (t == 0x8000 && y >= top);
            pct = y;
            if (t != 0x8000) {
                pct = y + 0x1000;
            }
            pct &= ~0xFFF;
            if (pct < top) {
                pct = top - 1;
            }
            sum += end - pct;
        }
        } while (y > top);
    }
    if (below > sum) {
        sum = below;
    }
    pct = sum * 100;
    pct /= h;
    if (pct >= 100) {
        return 100;
    }
    if (pct == 0 && sum > 0) {
        return 1;
    }
    return pct;
}
