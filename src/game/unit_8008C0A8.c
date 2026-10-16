#include "types.h"

typedef struct Unk8008C0A8Slot {
    /* 0x000 */ u32 data[0x134 / 4];
} Unk8008C0A8Slot;

typedef struct Unk803056C0 {
    /* 0x000 */ u8 pad0[0x14];
    /* 0x014 */ Unk8008C0A8Slot slot;
    /* 0x148 */ u8 pad148[0x180 - 0x148];
} Unk803056C0;

typedef struct Unk803140C0 {
    /* 0x0000 */ u8 pad0[0x220];
    /* 0x0220 */ u8 valid;
    /* 0x0221 */ u8 loaded;
    /* 0x0222 */ u16 count;
    /* 0x0224 */ Unk8008C0A8Slot slots[8];
} Unk803140C0;

extern Unk803140C0 lbl_803140C0;
extern Unk803056C0 lbl_803056C0;

s32 fn_8000C2F4(u8 slot, void* buf, u32 size);
s32 fn_8000C864(u8 slot, u32 size, void* buf);

static inline s32 Read(u8 slot) {
    if (slot == 8) {
        return fn_8000C2F4(slot, &lbl_803056C0, 0x180);
    }
    return fn_8000C2F4(slot, &lbl_803056C0, 0x180);
}

void fn_8008C0A8(void) {
    u32 i;

    lbl_803140C0.count = 0;
    lbl_803140C0.valid = 0;
    lbl_803140C0.loaded = 0;
    for (i = 0; i < 8; i++) {
        if (Read(i) != 0) {
            continue;
        }
        if (fn_8000C864(i, 0x134, &lbl_803056C0)) {
            lbl_803140C0.valid |= 1 << (u8)i;
        }
        if (lbl_803140C0.valid & (1 << (u8)i)) {
            lbl_803140C0.slots[(u8)i] = lbl_803056C0.slot;
            lbl_803140C0.loaded |= 1 << (u8)i;
            lbl_803140C0.count++;
        }
    }
}
