#include "types.h"

typedef struct Unk800A576C {
    /* 0x00 */ struct Unk800A576C* next;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 pad6[0x8 - 0x6];
    /* 0x08 */ u8* unk8;
    /* 0x0C */ void* unkC;
    /* 0x10 */ u8 pad10[0x12 - 0x10];
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 pad14[0x28 - 0x14];
    /* 0x28 */ s16 unk28;
    /* 0x2A */ s16 unk2A;
} Unk800A576C;

typedef struct Unk8036CF50 {
    /* 0x0000 */ u8 pad0[0xEFDC];
    /* 0xEFDC */ Unk800A576C* freeList;
} Unk8036CF50;

extern Unk8036CF50 lbl_8036CF50;

void fn_800A576C(void) {
    lbl_8036CF50.freeList = (Unk800A576C*)&lbl_8036CF50.freeList;
}
