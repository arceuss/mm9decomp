#include "types.h"
typedef struct Unk8006CA38 {
    /* 0x00 */ u8 pad00[0x14];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15[0x34 - 0x15];
    /* 0x34 */ void* unk34;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0xC8 - 0x68];
    /* 0xC8 */ u8 unkC8;
    /* 0xC9 */ u8 unkC9;
} Unk8006CA38;
extern void* lbl_804EE738;
extern Unk8006CA38* fn_800E8C44(void*);
extern void fn_80042DA0(Unk8006CA38*, s32);
Unk8006CA38* fn_8006CA38(void* a, s32 b, s32 c, u8 d, u8 e, u8 f) {
    Unk8006CA38* p = fn_800E8C44(lbl_804EE738);
    if (p) {
        fn_80042DA0(p, 0x29);
        p->unk34 = a; p->unk60 = b; p->unk64 = c;
        p->unk14 = d; p->unkC8 = e; p->unkC9 = f;
    }
    return p;
}
