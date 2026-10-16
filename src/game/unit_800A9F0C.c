#include "types.h"

typedef struct Unk800A9F0CEntry {
    /* 0x00 */ u32 size;
    /* 0x04 */ u8 pad4[0xA - 0x4];
    /* 0x0A */ u16 flags;
    /* 0x0C */ u8 padC[0x10 - 0xC];
    /* 0x10 */ u16 width;
    /* 0x12 */ u8 format;
    /* 0x13 */ u8 pad13;
} Unk800A9F0CEntry;

typedef struct Unk800A9F0CSlot {
    /* 0x0 */ u8 pad0[0x2];
    /* 0x2 */ u16 unk2;
    /* 0x4 */ u8 is8 : 1;
    /* 0x4 */ u8 rest : 7;
    /* 0x5 */ u8 unk5;
    /* 0x6 */ u8 unk6;
    /* 0x7 */ u8 capacity;
    /* 0x8 */ u8 pad8;
    /* 0x9 */ u8 count;
    /* 0xA */ u8 padA[0xC - 0xA];
    /* 0xC */ Unk800A9F0CEntry* entries;
} Unk800A9F0CSlot;

typedef struct Unk800A9F0C {
    /* 0x000 */ u8 pad0[0x610];
    /* 0x610 */ Unk800A9F0CSlot slots[(0xE90 - 0x610) / 0x10];
    /* 0xE90 */ u8 slotIdx[1];
} Unk800A9F0C;

void fn_800A9F0C(Unk800A9F0C* m, Unk800A9F0CEntry* t, u32 idx, u16 arg) {
    u32 not4 = (t->format & 0x7F) != 4;
    u8 s = m->slotIdx[idx];
    Unk800A9F0CSlot* slot;
    Unk800A9F0CEntry* e;
    u32 n;
    u32 w;
    u32 max;

    if (s != 0xFF) {
        slot = &m->slots[s];
    } else {
        slot = NULL;
    }
    if (slot == NULL) {
        return;
    }
    e = t;
    max = 0;
    if (t->flags & 1) {
        n = t->size / 20;
    } else {
        n = t->size / 12;
    }
    for (; n != 0; n--, e++) {
        if ((u32)(e->format & 0x7F) == 4) {
            w = ((e->width + 0x1F) >> 5) & 0xFF;
        } else {
            w = ((e->width + 0x1FF) >> 9) & 0xFF;
        }
        if (w > (u8)max) {
            max = w;
        }
    }
    if ((u8)max > slot->capacity) {
        return;
    }
    slot->unk5 = 0xFF;
    slot->unk6 = 0xFF;
    if (t->flags & 1) {
        n = t->size / 20;
    } else {
        n = t->size / 12;
    }
    slot->count = n;
    slot->entries = t;
    slot->is8 = not4;
    slot->unk2 = arg;
}
