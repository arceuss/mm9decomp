#include "types.h"

typedef struct UnkAD {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 unkA;
    /* 0x0B */ u8 padB[0x60 - 0xB];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
} UnkAD;

void fn_800E9244(void*);
void fn_80042CF8(void*, s32);

typedef struct Unk40AD0 {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
} Unk40AD0;

void fn_80040AD0(s32, Unk40AD0*, s32, s32);

void fn_8006A318(UnkAD* rec) {
    Unk40AD0 tmp;
    tmp.unk0 = rec->unk60;
    tmp.unk4 = rec->unk64;
    fn_80040AD0(2, &tmp, 0, 0);
    fn_800E9244(rec);
    rec->unkA &= ~1;
    fn_80042CF8(rec, 4);
}
