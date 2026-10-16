#include "types.h"

typedef struct Unk800C0458Sub {
    /* 0x000 */ u8 pad0[0x1F8];
    /* 0x1F8 */ u8 unk1F8;
} Unk800C0458Sub;

typedef struct Unk800C0458 {
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
    /* 0x34 */ Unk800C0458Sub* unk34;
    /* 0x38 */ u8 pad38[0xC8 - 0x38];
    /* 0xC8 */ u8 unkC8;
} Unk800C0458;

typedef struct Unk800C0458Entry {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ u32 unk10;
} Unk800C0458Entry;

extern Unk800C0458Entry* lbl_8027F228[];

void fn_800E9244(Unk800C0458* work);

void fn_800C0458(Unk800C0458* work) {
    Unk800C0458Sub* sub;
    s32 v;

    work->unk18 = lbl_8027F228[work->unk9]->unk10;
    work->unk10 = 4;
    work->unk11 = 0;
    work->unk12 = 0;
    work->unk13 = 0;
    fn_800E9244(work);
    work->unkA &= ~1;
    sub = work->unk34;
    v = sub->unk1F8;
    v -= work->unkC8;
    if (v < 0) {
        v = 0;
    }
    sub->unk1F8 = v;
}
