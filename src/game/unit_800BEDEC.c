#include "types.h"

typedef struct UnkB8skip {
    /* 0x00 */ u8 pad0[0x60];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
} UnkB8skip;

typedef struct UnkBEDEC {
    /* 0x00 */ u8 pad0[0x34];
    /* 0x34 */ UnkB8skip* unk34;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0xAC - 0x68];
    /* 0xAC */ void* unkAC;
    /* 0xB0 */ u8 padB0[0xCC - 0xB0];
    /* 0xCC */ u8 unkCC;
    /* 0xCD */ u8 padCD[0xCF - 0xCD];
    /* 0xCF */ u8 unkCF;
    /* 0xD0 */ u8 unkD0;
} UnkBEDEC;

extern u8 lbl_8027EFE0[0x48];

void fn_800E91F0(void*, void*, s32);
void fn_800D5234(s32);
void fn_800BEB40(void*, s32);

void fn_800BF8A4(void);

void fn_800BEDEC(UnkBEDEC* rec) {
    UnkB8skip* f = rec->unk34;
    s32 i;
    fn_800D5234(0x2A);
    rec->unk60 = f->unk60;
    rec->unk64 = f->unk64 - 0xA00;
    fn_800E91F0(rec, lbl_8027EFE0, 0);
    rec->unkAC = fn_800BF8A4;
    rec->unkCC = 0;
    rec->unkCF = 1;
    for (i = 0; i < 4; i++) {
        fn_800BEB40(rec, i);
    }
    rec->unkD0 = 2;
}
