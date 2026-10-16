#include "types.h"

typedef struct Unk80073BE0 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 kind;
    /* 0x0A */ u8 padA[0x10 - 0xA];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 pad14[0x18 - 0x14];
    /* 0x18 */ void* unk18;
    /* 0x1C */ u8 pad1C[0x34 - 0x1C];
    /* 0x34 */ struct Unk80073BE0* parent;
    /* 0x38 */ u8 pad38[0xA0 - 0x38];
    /* 0xA0 */ u32 hitFlags;
    /* 0xA4 */ u8 padA4[0xAB - 0xA4];
    /* 0xAB */ u8 hitHi : 4;
    /* 0xAB */ u8 hitType : 4;
} Unk80073BE0;

extern void** lbl_80270168[];

static inline void Die(Unk80073BE0* obj) {
    obj->unk18 = lbl_80270168[obj->kind][2];
    obj->unk10 = 2;
    obj->unk13 = 0;
    obj->state = 0;
    obj->step = 0;
}

BOOL fn_80073BE0(Unk80073BE0* obj) {
    if (obj->state != 1 && obj->hitType == 3) {
        obj->state = 1;
        obj->step = 0;
        return FALSE;
    }
    if (obj->state != 2 && obj->hitType == 5) {
        Die(obj);
        return TRUE;
    }
    if ((obj->hitFlags & 0x100) || (obj->hitFlags & 0x80000)) {
        Die(obj);
        return TRUE;
    }
    if (obj->parent->unk10 >= 2) {
        Die(obj);
        return TRUE;
    }
    if (obj->parent->state == 3) {
        Die(obj);
        return TRUE;
    }
    return FALSE;
}
