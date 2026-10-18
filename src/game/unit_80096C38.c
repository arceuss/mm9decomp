#include "types.h"

typedef struct Unk80096C38 {
    /* 0x00 */ s8 cursor;
    /* 0x01 */ u8 pad1;
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 pad3[0x1C - 0x3];
    /* 0x1C */ u16 mask;
} Unk80096C38;

typedef struct Unk80316D78 {
    /* 0x0000 */ u8 pad0[0x3004];
    /* 0x3004 */ u8* unk3004;
} Unk80316D78;

extern Unk80316D78 lbl_80316D78;

#define MENU ((Unk80096C38*)(lbl_80316D78.unk3004 + 0xD41000))

void fn_80096C38(void) {
    Unk80096C38* m = MENU;
    s32 c = m->cursor;
    u8 side;
    s8 idx;
    s32 i;
    s32 wrap;
    s32 q;

    if (m->unk2 != 0) {
        if ((u8)c <= 1) {
            if (c != 0) {
                c--;
            } else {
                c = 1;
            }
        } else {
            c = c == 3 ? 4 : (s8)(c - 1);
        }
        m->cursor = c;
        return;
    }
    q = c / 6;
    side = (u8)((u8)(c + 6) / 6) % 2;
    wrap = 0;
    idx = (u8)(c - q * 6 + side * 6);
    for (i = 0; i < 6; i++, idx++) {
        if ((side == 0 && idx == 6) || (side != 0 && idx == 11)) {
            wrap = 1;
            break;
        }
        if (m->mask & (1 << idx)) {
            m->cursor = idx;
            break;
        }
    }
    if (wrap) {
        m = MENU;
        idx = q;
        for (i = 0; i < 6; i++, idx++) {
            if (m->mask & (1 << idx)) {
                m->cursor = idx;
                return;
            }
        }
    }
}
