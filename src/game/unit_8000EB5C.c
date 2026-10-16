#include "types.h"

typedef struct Unk80301280Mode {
    /* 0x0 */ u32 flags;
    /* 0x4 */ u32 unk4;
    /* 0x8 */ u16 entries[4];
} Unk80301280Mode;

typedef struct Unk80301280 {
    /* 0x00 */ u32 flags;
    /* 0x04 */ u8 pad4[0x40 - 0x4];
    /* 0x40 */ Unk80301280Mode* mode;
    /* 0x44 */ u8 pad44[0x48 - 0x44];
} Unk80301280;

extern Unk80301280 lbl_80301280;

void fn_8009C04C(u32 value, void* dst, u32 size);

static inline void InitEntry(u16 index, u16 value) {
    lbl_80301280.mode->entries[index] = value;
    lbl_80301280.mode->entries[index] &= ~0x3C;
    lbl_80301280.mode->entries[index] &= 0xFF7B;
    lbl_80301280.mode->entries[index] |= 4;
}

void fn_8000EB5C(void) {
    fn_8009C04C(0, &lbl_80301280, 0x40);
    lbl_80301280.mode = (Unk80301280Mode*)&lbl_80301280;
    lbl_80301280.flags = (lbl_80301280.flags & ~0x3F000000) | 0x40000000;
    lbl_80301280.mode->flags &= ~7;
    lbl_80301280.mode->flags &= ~0xF00;
    InitEntry(0, 0x4001);
    InitEntry(1, 0x4200);
    InitEntry(2, 0x4401);
    InitEntry(3, 0x4601);
}
