#include "types.h"

typedef struct Unk80080E34Light {
    /* 0x0 */ u32 color;
    /* 0x4 */ s32 x;
    /* 0x8 */ s32 y;
} Unk80080E34Light;

typedef struct Unk80304EA8 {
    /* 0x000 */ u8 pad0[0x190];
    /* 0x190 */ Unk80080E34Light lights[(0x324 - 0x190) / 12];
    /* 0x31C */ u8 pad31C[0x324 - 0x31C];
    /* 0x324 */ u16 unk324;
    /* 0x326 */ u16 r;
    /* 0x328 */ u16 g;
    /* 0x32A */ u16 b;
} Unk80304EA8;

typedef struct Unk80080E34Pos {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Unk80080E34Pos;

extern Unk80304EA8 lbl_80304EA8;

void fn_80080E34(Unk80080E34Pos* pos, u32* out) {
    Unk80080E34Light* l = lbl_80304EA8.lights;
    s32 r = lbl_80304EA8.r;
    s32 g = lbl_80304EA8.g;
    s32 b = lbl_80304EA8.b;
    s32 dx;
    s32 dy;
    u32 c;
    s32 lr;
    s32 lg;
    s32 lb;

    for (; (c = l->color) != 0; l++) {
        dx = pos->x - l->x;
        dx = dx < 0 ? -dx : dx;
        dy = pos->y - l->y;
        dy = dy < 0 ? -dy : dy;
        if (dx > 0x18000 || dy > 0x15000) {
            continue;
        }
        lr = (c & 0xFF) << 8;
        lb = (c >> 8) & 0xFF00;
        lg = c & 0xFF00;
        if (dx > 0x8000 || dy > 0x7000) {
            dx = (0x18000 - dx) / 256;
            dy = (0x15000 - dy) / 0xE0;
            if (dy < dx) {
                dx = dy;
            }
            lr = (lr * dx) >> 8;
            lg = (lg * dx) >> 8;
            lb = (lb * dx) >> 8;
        }
        if (r < lr) {
            r = lr;
        }
        if (g < lg) {
            g = lg;
        }
        if (b < lb) {
            b = lb;
        }
    }
    if (r > 0x2000) {
        r = 0x2000;
    }
    if (g > 0x2000) {
        g = 0x2000;
    }
    if (b > 0x2000) {
        b = 0x2000;
    }
    lbl_80304EA8.r = (r * 7) >> 3;
    lbl_80304EA8.g = (g * 7) >> 3;
    lbl_80304EA8.b = (b * 7) >> 3;
    lbl_80304EA8.unk324 = 0;
    lbl_80304EA8.lights[0].color = 0;
    *out = ((b << 8) & 0xFFFF0000) | ((r >> 8) | (g & ~0xFF));
}
