#include "types.h"

typedef struct Unk800C2F8C {
    u8 pad0[0x9];
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u8 pad0C[0x18 - 0x0C];
    u32 unk18;
    u8 pad1C[0x20 - 0x1C];
    u8 unk20;
    u8 unk21;
    u8 pad22[0x2A - 0x22];
    u16 unk2A;
    u8 unk2C;
    u8 pad2D;
    u8 unk2E;
    u8 unk2F;
} Unk800C2F8C;

typedef struct Unk800C2F8CEntry {
    u32 unk0;
} Unk800C2F8CEntry;

extern Unk800C2F8CEntry* lbl_8027F3C8[];

void fn_800C2F8C(Unk800C2F8C* work, u8 idx) {
    work->unk9 = idx;
    work->unk18 = lbl_8027F3C8[idx]->unk0;
    work->unk2E = 0x10;
    work->unk2A = 0;
    work->unk2C = 0;
    work->unk2F = 0;
    work->unkB |= 0x20;
    work->unk21 = work->unk20;
}
