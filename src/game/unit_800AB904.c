#include "types.h"

typedef struct Unk80316D78 {
    /* 0x0000 */ u8 pad0[0x3004];
    /* 0x3004 */ u8* unk3004;
} Unk80316D78;

typedef struct Unk8037CC40Slot {
    /* 0x0 */ u8 pad0[0x8];
    /* 0x8 */ u8 unk8;
    /* 0x9 */ u8 pad9[0x10 - 0x9];
} Unk8037CC40Slot;

typedef struct Unk8037CC40 {
    /* 0x0000 */ u8 pad0[0x1618];
    /* 0x1618 */ Unk8037CC40Slot slots[(0x1FD8 - 0x1618) / 0x10];
    /* 0x1FD8 */ u8 slotA;
    /* 0x1FD9 */ u8 pad1FD9[0x1FDC - 0x1FD9];
    /* 0x1FDC */ u8 slotB;
} Unk8037CC40;

typedef struct Unk80383E70 {
    /* 0x0 */ u8* buf;
    /* 0x4 */ u8 pad4[0x7488 - 0x4];
} Unk80383E70;

extern Unk80316D78 lbl_80316D78;
extern Unk8037CC40 lbl_8037CC40;
extern Unk80383E70 lbl_80383E70;
extern void* lbl_8027EB48[3];
extern u8 lbl_8027EBA8[][0x10];

void fn_800A7E88(void* arg0);
void fn_800BAFDC(void* src, u32 dst, s32 size);

static inline Unk8037CC40Slot* Slot(u8 idx) {
    Unk8037CC40Slot* p = NULL;

    if (idx != 0xFF) {
        p = &lbl_8037CC40.slots[idx];
    }
    return p;
}

void fn_800AB904(s32 id) {
    u8* saved = lbl_80383E70.buf;
    u8* src;

    lbl_80383E70.buf = lbl_80316D78.unk3004 + 0xC29000;
    fn_800A7E88(lbl_8027EB48[id]);
    lbl_80383E70.buf = saved;
    src = lbl_8027EBA8[0];
    fn_800BAFDC(src, (Slot(lbl_8037CC40.slotA) != NULL ? Slot(lbl_8037CC40.slotA)->unk8 : 0) * 32 + 0x200, 0x10);
    src = lbl_8027EBA8[0];
    fn_800BAFDC(src, (Slot(lbl_8037CC40.slotB) != NULL ? Slot(lbl_8037CC40.slotB)->unk8 : 0) * 32 + 0x200, 8);
}
