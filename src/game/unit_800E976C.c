#include "types.h"

typedef struct Unk8037CC40Slot {
    /* 0x0 */ u8 pad0[0x8];
    /* 0x8 */ u8 unk8;
    /* 0x9 */ u8 pad9[0x10 - 0x9];
} Unk8037CC40Slot;

typedef struct Unk8037CC40 {
    /* 0x0000 */ u8 pad0[0x1618];
    /* 0x1618 */ Unk8037CC40Slot slots[(0x1E98 - 0x1618) / 0x10];
    /* 0x1E98 */ u8 slotIndex[0x7230 - 0x1E98];
} Unk8037CC40;

typedef struct Unk800E976C {
    /* 0x00 */ u8 pad0[0xB];
    /* 0x0B */ u8 flagsB;
    /* 0x0C */ u8 padC[0x26 - 0xC];
    /* 0x26 */ u16 unk26;
    /* 0x28 */ u8 pad28[0x2C - 0x28];
    /* 0x2C */ u8 unk2C;
    /* 0x2D */ u8 unk2D;
} Unk800E976C;

extern Unk8037CC40 lbl_8037CC40;

static inline Unk8037CC40Slot* GetSlot(u8 slot) {
    if (slot == 0xFF) {
        return NULL;
    }
    return &lbl_8037CC40.slots[slot];
}

u8 fn_800E976C(Unk800E976C* obj) {
    u8 base;
    u8 slot;

    if (obj->flagsB & 0x40) {
        return obj->unk2D;
    }
    base = obj->unk2C;
    slot = lbl_8037CC40.slotIndex[obj->unk26];
    return base + (GetSlot(slot) != NULL ? GetSlot(slot)->unk8 : 0);
}
