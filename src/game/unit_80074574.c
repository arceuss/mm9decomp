#include "types.h"
typedef struct Unk80074574 {
    /* 0x00 */ u8 pad00[0x12];
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 pad13[0x4D];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ u8 pad70[0x18];
    /* 0x88 */ u8 unk88[1];
} Unk80074574;
extern u8 lbl_8026FBE8[];
extern void fn_800E946C(Unk80074574*, s32);
extern void fn_800E9750(Unk80074574*, u16);
extern void fn_8009996C(void*, void*);
void fn_80074574(Unk80074574* p) {
    switch (p->unk12) {
    case 0:
        fn_800E946C(p, 3); fn_8009996C(p->unk88, lbl_8026FBE8); p->unk12++;
    case 1:
        fn_800E9750(p, 0xFFFF);
        p->unk60 += p->unk68; p->unk64 += p->unk6C;
        break;
    }
}
