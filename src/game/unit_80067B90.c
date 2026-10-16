#include "types.h"
typedef struct Unk80067B90 {
    /* 0x00 */ u8 pad00[0x14];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15[2];
    /* 0x17 */ u8 unk17;
    /* 0x18 */ u8 pad18[0x34 - 0x18];
    /* 0x34 */ void* unk34;
    /* 0x38 */ u8 pad38[0xC8 - 0x38];
    /* 0xC8 */ u16 unkC8;
    /* 0xCA */ u8 unkCA;
    /* 0xCB */ u8 unkCB;
} Unk80067B90;
extern void* lbl_804EE738;
extern Unk80067B90* fn_800E8C44(void*);
extern void fn_80042DA0(Unk80067B90*, s32);
Unk80067B90* fn_80067B90(void* a, u8 b, u8 c, u8 d, u16 e, u8 f) {
    Unk80067B90* p = fn_800E8C44(lbl_804EE738);
    if (p != 0) {
        fn_80042DA0(p, 0x25);
        p->unk34 = a;
        p->unk14 = b;
        p->unkCA = c;
        p->unkC8 = e;
        p->unk17 = f;
        p->unkCB = d;
    }
    return p;
}
