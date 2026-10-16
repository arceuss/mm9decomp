#include "types.h"
typedef struct Unk80074BE8 {
    /* 0x00 */ u8 pad00[0x9];
    /* 0x09 */ u8 unk09;
    /* 0x0A */ u8 unk0A;
    /* 0x0B */ u8 pad0B[0x5];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15[0x3];
    /* 0x18 */ void* unk18;
    /* 0x1C */ u8 pad1C[0x90];
    /* 0xAC */ void (*unkAC)(void*);
} Unk80074BE8;
extern void** lbl_80270168[];
extern u8 lbl_8026FC38[], lbl_804EE820[8];
extern void fn_800E9424(Unk80074BE8*, s32);
extern void fn_800E91F0(Unk80074BE8*, void*, s32);
extern void fn_80074BAC(void*);
extern void fn_80074C90(Unk80074BE8*);
void fn_80074BE8(Unk80074BE8* p) {
    fn_800E9424(p, 16);
    p->unk0A |= 3;
    fn_800E91F0(p, lbl_8026FC38, 0);
    p->unkAC = fn_80074BAC;
    p->unk18 = lbl_80270168[p->unk09][1];
    p->unk10 = 1; p->unk11 = 0; p->unk12 = 0; p->unk13 = 0;
    p->unk11 = lbl_804EE820[p->unk14];
    fn_80074C90(p);
}
