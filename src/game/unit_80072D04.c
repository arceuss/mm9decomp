#include "types.h"
typedef struct Unk80072D04 {
    /* 0x00 */ u8 pad00[9];
    /* 0x09 */ u8 unk09;
    /* 0x0A */ u8 unk0A;
    /* 0x0B */ u8 pad0B[5];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u32 unk14;
    /* 0x18 */ void* unk18;
    /* 0x1C */ u8 pad1C[0x84 - 0x1C];
    /* 0x84 */ s32 unk84;
    /* 0x88 */ u8 pad88[0xAC - 0x88];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xCC - 0xB0];
    /* 0xCC */ u8 unkCC;
} Unk80072D04;
extern void** lbl_80270168[];
extern u8 lbl_8026FAB0[];
extern void fn_800E9A84(Unk80072D04*, s32);
extern void fn_800E9424(Unk80072D04*, s32);
extern void fn_800E91F0(Unk80072D04*, void*, s32);
extern void fn_800E946C(Unk80072D04*, s32);
extern void fn_800D5234(s32);
extern void fn_80072CB4(void*);
extern void fn_80072DCC(Unk80072D04*);
void fn_80072D04(Unk80072D04* p) {
    fn_800E9A84(p, 0x144);
    fn_800E9424(p, 0);
    p->unk0A |= 3;
    fn_800E91F0(p, lbl_8026FAB0, 0);
    p->unkAC = fn_80072CB4;
    fn_800E946C(p, 9);
    p->unk84 = 0xFF00;
    fn_800D5234(0x3D);
    p->unkCC = 0;
    p->unk18 = lbl_80270168[p->unk09][1];
    p->unk10 = 1; p->unk12 = 0; p->unk13 = 0; p->unk11 = 0;
    fn_80072DCC(p);
}
