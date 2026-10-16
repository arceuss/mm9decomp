#include "types.h"

typedef struct Unk42CF8 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 padA[0x10 - 0xA];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 pad14[0x18 - 0x14];
    /* 0x18 */ s32 unk18;
} Unk42CF8;

extern u8 lbl_80268B00[0xC0];

void fn_80042CF8(Unk42CF8* rec, u8 v) {
    s32 idx = rec->unk9;
    void* entry;
    entry = *(void**)(lbl_80268B00 + idx * 4);
    rec->unk18 = *(u32*)((u8*)entry + v * 4);
    rec->unk10 = v;
    rec->unk11 = 0;
    rec->unk12 = 0;
    rec->unk13 = 0;
}
