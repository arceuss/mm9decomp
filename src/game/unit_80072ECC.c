#include "types.h"
typedef struct Unk80072ECC {
    /* 0x00 */ u8 pad00[0x12];
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 pad13[0x60 - 0x13];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ u8 pad70[0xA0 - 0x70];
    /* 0xA0 */ u32 unkA0;
    /* 0xA4 */ u8 padA4[8];
    /* 0xAC */ void (*unkAC)(void*);
} Unk80072ECC;
extern u8 lbl_8026FAB0[];
extern void fn_80072CB4(void*);
extern void fn_800E9750(Unk80072ECC*, u16);
extern void fn_800E91F0(Unk80072ECC*, void*, s32);
extern void fn_800D5234(s32);
void fn_80072ECC(Unk80072ECC* p) {
    fn_800E9750(p, 0xFFFF);
    if ((p->unkA0 & 0x1000) && p->unk12 == 0) {
        fn_800D5234(0x3E);
        fn_800E91F0(p, lbl_8026FAB0 + 0x30, 0);
        p->unk12 = 1;
        p->unkAC = fn_80072CB4;
        p->unk68 = p->unk68 * -3 / 2;
        p->unk6C = p->unk6C * -3 / 2;
    }
    p->unk60 += p->unk68;
    p->unk64 += p->unk6C;
}
