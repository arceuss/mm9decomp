#include "types.h"

typedef struct Unk800B748C {
    /* 0x000 */ u8 pad0[0x14];
    /* 0x014 */ u8 player;
    /* 0x015 */ u8 pad15[0x190 - 0x15];
    /* 0x190 */ u16 held;
    /* 0x192 */ u16 prev;
    /* 0x194 */ u16 pressed;
    /* 0x196 */ u16 released;
    /* 0x198 */ u16 trig;
} Unk800B748C;

typedef struct Unk8038E140 {
    /* 0x000 */ u32 flags;
    /* 0x004 */ u8 pad4[0x140 - 0x4];
} Unk8038E140;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x2A0];
    /* 0x2A0 */ u16 buttons[(0x300 - 0x2A0) / 2];
} Unk80304B90;

typedef struct Unk80319DA0Pad {
    /* 0x000 */ u8 pad0[0x860];
    /* 0x860 */ u32 trig;
    /* 0x864 */ u8 pad864[0x86C - 0x864];
} Unk80319DA0Pad;

typedef struct Unk80319DA0 {
    /* 0x0000 */ Unk80319DA0Pad pads[4];
    /* 0x21B0 */ u8 pad21B0[0x21C0 - 0x21B0];
} Unk80319DA0;

extern Unk8038E140 lbl_8038E140;
extern Unk80304B90 lbl_80304B90;
extern u16 lbl_8027EA68[2][6];
extern Unk80319DA0 lbl_80319DA0;

void fn_800B748C(Unk800B748C* obj) {
    u16 prev = obj->held;
    s32 alt;
    u16* map;
    u16 bits;
    u16 held;
    u16 trig;
    u16 i;

    obj->prev = prev;
    if (!(lbl_8038E140.flags & 8)) {
        alt = 0;
    } else {
        alt = 1;
    }
    map = lbl_8027EA68[alt];
    bits = lbl_80304B90.buttons[obj->player];
    held = 0;
    i = 6;
    do {
        i--;
        held |= ((bits & map[i]) != 0) << i;
    } while (i != 0);
    if (lbl_80304B90.buttons[obj->player] == 0xFFFF) {
        held = 0;
    }
    obj->held = held;
    bits = lbl_80319DA0.pads[obj->player].trig;
    trig = 0;
    i = 6;
    do {
        i--;
        trig |= ((bits & map[i]) != 0) << i;
    } while (i != 0);
    if (lbl_80304B90.buttons[obj->player] == 0xFFFF) {
        trig = 0;
    }
    obj->trig = trig;
    obj->pressed = held & (held ^ prev);
    obj->released = prev & (held ^ prev);
}
