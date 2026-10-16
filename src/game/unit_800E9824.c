#include "types.h"

typedef struct Unk800E9824 {
    /* 0x00 */ u8 pad0[0x8];
    /* 0x08 */ s8 unk8;
    /* 0x09 */ u8 pad9[0xB - 0x9];
    /* 0x0B */ u8 flagsB;
    /* 0x0C */ u8 flagsC;
    /* 0x0D */ u8 unkD;
    /* 0x0E */ u8 unkE;
    /* 0x0F */ u8 padF[0x20 - 0xF];
    /* 0x20 */ u8 unk20;
    /* 0x21 */ u8 pad21[0x28 - 0x21];
    /* 0x28 */ s16 unk28;
    /* 0x2A */ u8 pad2A[0x2D - 0x2A];
    /* 0x2D */ u8 unk2D;
    /* 0x2E */ u8 pad2E[0x50 - 0x2E];
    /* 0x50 */ u32 unk50_hi : 16;
    /* 0x50 */ u32 unk50_b : 8;
    /* 0x50 */ u32 unk50_lo : 8;
} Unk800E9824;

void fn_800E9824(Unk800E9824* obj) {
    obj->flagsB |= 8;
}
