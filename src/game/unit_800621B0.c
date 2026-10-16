#include "types.h"
typedef struct Unk800621B0 {
    /* 0x00 */ u8 pad00[0x12];
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14a:4;
                 u8 unk14b:4;
    /* 0x15 */ u8 pad15[0x60 - 0x15];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ u8 pad6C[0xC8 - 0x6C];
    /* 0xC8 */ u8 unkC8;
} Unk800621B0;
extern u8 lbl_804ECBC8[8];
extern void fn_800E946C(Unk800621B0*, s32);
extern void fn_800E9750(Unk800621B0*, u16);
extern void fn_80062774(Unk800621B0*);
void fn_800621B0(Unk800621B0* p) {
    switch (p->unk12) {
    case 0:
        fn_800E946C(p, lbl_804ECBC8[p->unk14a]);
        p->unk12++;
    case 1:
        switch (p->unkC8) {
        case 0: p->unk60 += p->unk68; break;
        case 1: p->unk60 -= p->unk68; break;
        case 2: p->unk64 -= p->unk68; break;
        case 3: p->unk64 += p->unk68; break;
        }
        fn_80062774(p);
        fn_800E9750(p, 0xFFFF);
        break;
    }
}
