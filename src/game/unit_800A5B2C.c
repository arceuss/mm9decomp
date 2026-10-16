#include "types.h"

typedef struct Unk800A5B2C {
    /* 0x00 */ struct Unk800A5B2C* next;
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
} Unk800A5B2C;

typedef struct Unk8036CF50 {
    /* 0x0000 */ u8 pad0[0xEFDC];
    /* 0xEFDC */ Unk800A5B2C* freeList;
} Unk8036CF50;

extern Unk8036CF50 lbl_8036CF50;

extern u8 lbl_8027E190[];

void fn_800E8520(s32 value, void* dst, s32 size);
void fn_800BAFDC(void* src, void* dst, s32 size);

void fn_800A5B2C(Unk800A5B2C* p) {
    s32 size = p->unk4 * 8;
    s32 total = size * (p->unk12 * p->unk13 + 1);

    fn_800E8520(0, p->unk8 + total, total);
    fn_800E8520(0, p->unk8, size);
    fn_800BAFDC(lbl_8027E190, p->unkC, 0xC);
    p->unk5 = 0;
    p->unk28 = 0;
    p->unk2A = 0;
    if (p->next == NULL) {
        p->next = lbl_8036CF50.freeList;
        lbl_8036CF50.freeList = p;
    }
}
