#include "types.h"

typedef struct Unk80097724Gfx {
    /* 0x0000 */ u8 pad0[0x1000];
    /* 0x1000 */ u8 weapon;
    /* 0x1001 */ u8 pad1001[0x1028 - 0x1001];
    /* 0x1028 */ u16 palette;
} Unk80097724Gfx;

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
    /* 0x1618 */ Unk8037CC40Slot slots[(0x1FDF - 0x1618) / 0x10];
    /* 0x1FD8 */ u8 pad1FD8[0x1FDF - 0x1FD8];
    /* 0x1FDF */ u8 current;
} Unk8037CC40;

typedef struct Unk80097724 {
    /* 0x0 */ u8 pad0[0x2];
    /* 0x2 */ u8 unk2;
    /* 0x3 */ u8 unk3;
} Unk80097724;

extern Unk80316D78 lbl_80316D78;
extern Unk8037CC40 lbl_8037CC40;
extern void* lbl_804EE984;
extern u32 lbl_80274360[];
extern u8 lbl_8027EBA8[][0x10];

BOOL fn_800B58F8(void* player, s32 arg1);
void fn_800BAFDC(void* src, u32 dst, s32 size);

#define GFX ((Unk80097724Gfx*)(lbl_80316D78.unk3004 + 0xD40000))

static inline Unk8037CC40Slot* CurSlot(void) {
    Unk8037CC40Slot* p = NULL;

    if (lbl_8037CC40.current != 0xFF) {
        p = &lbl_8037CC40.slots[lbl_8037CC40.current];
    }
    return p;
}

void fn_80097724(Unk80097724* obj) {
    u8 w = GFX->weapon;
    u32 idx;
    u8* src;
    u32 n;

    if (w == 4) {
        w = 5;
    } else if (w == 5) {
        w = 4;
    }
    GFX->palette = w;
    if (fn_800B58F8(lbl_804EE984, 2) && GFX->palette == 0) {
        idx = 0x10;
    } else {
        idx = lbl_80274360[GFX->palette];
    }
    src = lbl_8027EBA8[idx];
    if (CurSlot() != NULL) {
        n = CurSlot()->unk8;
    } else {
        n = 0;
    }
    fn_800BAFDC(src, (n << 5) + 0x200, 8);
    obj->unk2 = 2;
    obj->unk3 = 0;
}
