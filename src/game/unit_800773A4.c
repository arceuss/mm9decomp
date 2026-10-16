#include "types.h"

typedef struct Unk800773A4 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 kind;
    /* 0x0A */ u8 padA[0x10 - 0xA];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 pad14[0x17 - 0x14];
    /* 0x17 */ u8 unk17;
    /* 0x18 */ void* unk18;
    /* 0x1C */ u8 pad1C[0xA0 - 0x1C];
    /* 0xA0 */ u32 hitFlags;
    /* 0xA4 */ u8 padA4[0xAB - 0xA4];
    /* 0xAB */ u8 hitHi : 4;
    /* 0xAB */ u8 hitType : 4;
} Unk800773A4;

extern void** lbl_80270168[];

BOOL fn_800773A4(Unk800773A4* obj) {
    if (obj->state != 1 && obj->hitType == 3) {
        obj->state = 1;
        obj->step = 0;
        return FALSE;
    }
    if (obj->state != 2 && obj->hitType == 5) {
        obj->state = 2;
        obj->step = 0;
        return FALSE;
    }
    if ((obj->hitFlags & 1) && obj->hitType == 8) {
        obj->unk18 = lbl_80270168[obj->kind][2];
        obj->unk10 = 2;
        obj->unk13 = 0;
        obj->state = 1;
        obj->step = 0;
        return TRUE;
    }
    if ((obj->hitFlags & 0x80000) || (obj->hitFlags & 0x1000) || (obj->hitFlags & 1)) {
        obj->unk18 = lbl_80270168[obj->kind][2];
        obj->unk10 = 2;
        obj->unk13 = 0;
        obj->state = 0;
        obj->step = 0;
        return TRUE;
    }
    if (obj->unk17 != 0 && (obj->hitFlags & 4)) {
        obj->unk18 = lbl_80270168[obj->kind][2];
        obj->unk10 = 2;
        obj->unk13 = 0;
        obj->state = 0;
        obj->step = 0;
        return TRUE;
    }
    return FALSE;
}
