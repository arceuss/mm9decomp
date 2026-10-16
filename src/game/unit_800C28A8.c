#include "types.h"

typedef struct Unk800C28A8 {
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
} Unk800C28A8;

typedef struct Unk800C28A8Entry {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ u32 unk10;
} Unk800C28A8Entry;

extern Unk800C28A8Entry* lbl_8027F228[];

void fn_800E9244(Unk800C28A8* work);

void fn_800C28A8(Unk800C28A8* work) {
    work->unk18 = lbl_8027F228[work->unk9]->unk10;
    work->unk10 = 4;
    work->unk11 = 0;
    work->unk12 = 0;
    work->unk13 = 0;
    fn_800E9244(work);
    work->unkA &= ~1;
}
