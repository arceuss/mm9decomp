#include "types.h"

typedef struct Unk8037CC40Entry {
    /* 0x0 */ u8 pad0[0x8];
    /* 0x8 */ u8 pal;
    /* 0x9 */ u8 pad9[0x10 - 0x9];
} Unk8037CC40Entry;

typedef struct Unk8037CC40 {
    /* 0x0000 */ u8 pad0[0x1618];
    /* 0x1618 */ Unk8037CC40Entry entries[(0x1E98 - 0x1618) / 0x10];
    /* 0x1E98 */ u8 slots[0x1FDC - 0x1E98];
    /* 0x1FDC */ u8 unk1FDC;
} Unk8037CC40;

typedef struct Unk8027EBA8 {
    /* 0x0 */ u8 data[0x10];
} Unk8027EBA8;

extern Unk8037CC40 lbl_8037CC40;
extern Unk8027EBA8 lbl_8027EBA8[];

void fn_800BAFDC(void* dst, s32 src, s32 count);

static inline Unk8037CC40Entry* GetEntry(u8 slot) {
    if (slot == 0xFF) {
        return NULL;
    }
    return &lbl_8037CC40.entries[slot];
}

static inline u8 GetPal(u8 slot) {
    if (GetEntry(slot) != NULL) {
        return GetEntry(slot)->pal;
    }
    return 0;
}

void fn_800ABA48(s32 index, s32 obj) {
    fn_800BAFDC(&lbl_8027EBA8[index], GetPal(lbl_8037CC40.slots[obj]) * 32 + 0x200, 0x10);
    fn_800BAFDC(&lbl_8027EBA8[index], GetPal(lbl_8037CC40.unk1FDC) * 32 + 0x200, 8);
}
