#include "types.h"

typedef struct Unk800B75D0 {
    /* 0x000 */ u8 pad0[0x14];
    /* 0x014 */ u8 unk14;
    /* 0x015 */ u8 pad15[0x188 - 0x15];
    /* 0x188 */ u16 held;
    /* 0x18A */ u16 prevHeld;
    /* 0x18C */ u16 pressed;
    /* 0x18E */ u16 released;
    /* 0x190 */ u16 raw;
} Unk800B75D0;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x2A0];
    /* 0x2A0 */ u16 unk2A0[4];
    /* 0x2A8 */ u8 pad2A8[0x300 - 0x2A8];
} Unk80304B90;

extern Unk80304B90 lbl_80304B90;

void fn_800B75D0(Unk800B75D0* p) {
    u16 prev = p->held;
    u16 cur;
    u16 forced;
    u16 changed;

    p->prevHeld = prev;
    cur = p->raw;
    forced = lbl_80304B90.unk2A0[p->unk14];
    if (forced & 0x8000) {
        if (forced != 0xFFFF) {
            cur &= 0xF;
            if (forced & 0x1000) {
                cur |= 0x80;
            }
            if (forced & 0x2000) {
                cur |= 0x100;
            }
            if (forced & 0x1000) {
                cur |= 0x200;
            }
            cur |= prev & 0x50;
        } else {
            cur = 0;
        }
    } else {
        cur |= (cur & 0x10) ? 0x40 : 0;
    }
    changed = cur ^ prev;
    p->held = cur;
    p->pressed = cur & changed;
    p->released = prev & changed;
}
