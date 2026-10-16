#include "types.h"
typedef struct Unk800754A8 {
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
} Unk800754A8;
extern u8 lbl_803051D8[];
extern void** lbl_80270168[];
extern void (*lbl_8026FCAC[])(Unk800754A8*);
extern void fn_800E9244(Unk800754A8*);
extern s32 fn_80075BF4(Unk800754A8*);
void fn_800754A8(Unk800754A8* p) {
    if (lbl_803051D8[2] & 0x20) {
        p->unk0A &= ~1; p->unk0A &= 0xFD;
        fn_800E9244(p);
        p->unk18 = lbl_80270168[p->unk09][3];
        p->unk10 = 3; p->unk11 = 0; p->unk12 = 0; p->unk13 = 0;
        return;
    }
    if (fn_80075BF4(p)) {
        fn_800E9244(p); p->unk0A &= ~1;
        p->unk18 = lbl_80270168[p->unk09][4];
        p->unk10 = 4; p->unk11 = 0; p->unk12 = 0; p->unk13 = 0;
    } else lbl_8026FCAC[p->unk11](p);
}
