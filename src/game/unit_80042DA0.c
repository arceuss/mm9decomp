#include "types.h"
typedef struct Unk42DA0 {
    u8 pad0[0x9];
    u8 unk9;
    u8 padA;
    u8 unkB;
    u8 padC[0x18 - 0xC];
    s32 unk18;
    u8 pad1C[0x20 - 0x1C];
    u8 unk20;
    u8 unk21;
    u8 pad22[0x2A - 0x22];
    u16 unk2A;
    u8 unk2C;
    u8 pad2D;
    u8 unk2E;
    u8 unk2F;
} Unk42DA0;
extern u8 lbl_80268B00[0xC0];
void fn_80042DA0(Unk42DA0* rec, u8 v) {
    s32 idx = 0x10;
    void* entry;
    u8 flags;
    u8 old20;
    u32 zero = 0;
    rec->unk2E = 0x10;
    idx = v * 4;
    entry = (void*)(lbl_80268B00 + idx);
    flags = rec->unkB;
    rec->unk9 = v;
    old20 = rec->unk20;
    idx = 0x20;
    idx = 0x20;  /* trigger re-read */
    entry = *(void**)(entry);
    rec->unk18 = (s32)entry;
    rec->unk2A = 0;
    rec->unk2C = 0;
    rec->unk2F = 0;
    rec->unkB = flags | 0x20;
    rec->unk21 = old20;
}
