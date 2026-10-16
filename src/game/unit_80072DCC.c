#include "types.h"
typedef struct Unk80072DCC {
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
} Unk80072DCC;
extern u8 lbl_803051D8[];
extern void** lbl_80270168[];
extern void (*lbl_8026FAA4[])(Unk80072DCC*);
extern void fn_800E9244(Unk80072DCC*);
extern s32 fn_80073318(Unk80072DCC*);
void fn_80072DCC(Unk80072DCC* p) {
    if (lbl_803051D8[2] & 0x20) {
        p->unk0A &= ~1; p->unk0A &= 0xFD;
        fn_800E9244(p);
        p->unk18 = lbl_80270168[p->unk09][3];
        p->unk10 = 3; p->unk11 = 0; p->unk12 = 0; p->unk13 = 0;
        return;
    }
    if (fn_80073318(p)) {
        p->unk0A &= ~1;
        fn_800E9244(p);
        p->unk18 = lbl_80270168[p->unk09][4];
        p->unk10 = 4; p->unk11 = 0; p->unk12 = 0; p->unk13 = 0;
    } else lbl_8026FAA4[p->unk11](p);
}
