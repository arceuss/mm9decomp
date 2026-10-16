#include "types.h"

typedef struct Unk42CF8 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 unkA;
    /* 0x0B */ u8 unkB;
    /* 0x0C */ u8 padC[0x10 - 0xC];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 pad14[0x18 - 0x14];
    /* 0x18 */ s32 unk18;
} Unk42CF8;

extern u8 lbl_80265138[0xC0];

void fn_80040C38(void*);

void fn_80040BF4(Unk42CF8* rec) {
    s32 idx;
    void* entry;
    rec->unkA = rec->unkA | 1;
    idx = rec->unk9;
    entry = *(void**)(lbl_80265138 + idx * 4);
    rec->unk18 = *(u32*)((u8*)entry + 4);
    rec->unk10 = 1;
    rec->unk11 = 0;
    rec->unk12 = 0;
    rec->unk13 = 0;
    fn_80040C38(rec);
}
