#include "types.h"

typedef struct Unk800C7608 {
    /* 0x00 */ u8 pad0[0x23];
    /* 0x23 */ u8 hitHi : 4;
    /* 0x23 */ u8 hitType : 4;
} Unk800C7608;

typedef struct Unk8038DC58 {
    /* 0x00 */ u8 pad0[0x15];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17[0x19 - 0x17];
    /* 0x19 */ u8 unk19;
} Unk8038DC58;

extern Unk8038DC58 lbl_8038DC58;

void fn_800C7608(Unk800C7608* obj) {
    if (obj->hitHi != 1) {
        lbl_8038DC58.unk19 |= 0x80;
    }
    if (obj->hitType != 0) {
        lbl_8038DC58.unk19 |= 0x40;
    }
    if (obj->hitType == 1) {
        lbl_8038DC58.unk15 |= 0x20;
    }
    if (obj->hitType == 2) {
        lbl_8038DC58.unk15 |= 0x40;
    }
    if (obj->hitType == 3) {
        lbl_8038DC58.unk15 |= 0x80;
    }
    if (obj->hitType == 4) {
        lbl_8038DC58.unk16 |= 1;
    }
    if (obj->hitType == 5) {
        lbl_8038DC58.unk16 |= 2;
    }
    if (obj->hitType == 6) {
        lbl_8038DC58.unk16 |= 4;
    }
    if (obj->hitType == 7) {
        lbl_8038DC58.unk16 |= 8;
    }
    if (obj->hitType == 8) {
        lbl_8038DC58.unk16 |= 0x10;
    }
}
