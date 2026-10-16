#include "types.h"

typedef struct Unk800C1618Sub {
    /* 0x00 */ u8 pad0[0x1F8];
    /* 0x1F8 */ u8 unk1F8;
} Unk800C1618Sub;

typedef struct Unk800C1618 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 unkA;
    /* 0x0B */ u8 pad0B[0x10 - 0x0B];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 pad14[0x18 - 0x14];
    /* 0x18 */ u32 unk18;
    /* 0x1C */ u8 pad1C[0x34 - 0x1C];
    /* 0x34 */ Unk800C1618Sub* unk34;
    /* 0x38 */ u8 pad38[0xCB - 0x38];
    /* 0xCB */ u8 unkCB;
    /* 0xCC */ u8 unkCC;
} Unk800C1618;

typedef struct Unk800C1618Entry {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ u32 unk10;
} Unk800C1618Entry;

typedef struct Unk803051D8 {
    /* 0x00 */ u8 pad0[0xB];
    /* 0x0B */ u8 unkB;
} Unk803051D8;

extern Unk800C1618Entry* lbl_8027F228[];
extern Unk803051D8 lbl_803051D8;

void fn_800E9244(Unk800C1618* work);

void fn_800C1618(Unk800C1618* work) {
    if (work->unkCB == 0) {
        lbl_803051D8.unkB++;
    }
    work->unk18 = lbl_8027F228[work->unk9]->unk10;
    work->unk10 = 4;
    work->unk11 = 0;
    work->unk12 = 0;
    work->unk13 = 0;
    fn_800E9244(work);
    work->unkA &= ~1;
}
