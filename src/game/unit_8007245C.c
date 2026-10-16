#include "types.h"

typedef struct Unk80304B68 {
    /* 0x00 */ u32 count;
    /* 0x04 */ u8 xs[8];
    /* 0x0C */ u8 ys[8];
    /* 0x14 */ u8 head;
    /* 0x15 */ u8 unk15;
} Unk80304B68;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x25C];
    /* 0x25C */ s32 camX;
    /* 0x260 */ s32 camY;
} Unk80304B90;

typedef struct Unk80316398 {
    /* 0x000 */ u8 pad0[0x935];
    /* 0x935 */ u8 unk935;
} Unk80316398;

extern Unk80304B68 lbl_80304B68;
extern Unk80304B90 lbl_80304B90;
extern Unk80316398 lbl_80316398;
extern u8 lbl_8027D2D8[];

BOOL fn_8007245C(void) {
    s32 rx = lbl_80304B90.camX >> 16;
    s32 ry = lbl_8027D2D8[lbl_80304B90.camY >> 12];
    u8 head = lbl_80304B68.head;
    u32 idx = head;
    s32 i;

    for (i = 0; i < 8; i++) {
        idx = (idx + 7) & 7;
        if (rx == lbl_80304B68.xs[idx] && ry == lbl_80304B68.ys[idx]) {
            break;
        }
    }
    if (i >= 8) {
        lbl_80304B68.xs[head] = rx;
        lbl_80304B68.ys[head] = ry;
        lbl_80304B68.head = (head + 1) & 7;
        lbl_80304B68.count++;
    }
    if (lbl_80304B68.count >= 99999) {
        lbl_80304B68.count = 99999;
    }
    lbl_80316398.unk935 = lbl_80304B68.unk15;
    return FALSE;
}
