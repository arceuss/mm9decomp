#include "types.h"
typedef struct Unk80069AC0 {
    /* 0x00 */ u8 pad00[0xA];
    /* 0x0A */ u8 unk0A;
    /* 0x0B */ u8 pad0B[5];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 pad12[0x34 - 0x12];
    /* 0x34 */ struct Unk80069AC0* unk34;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
} Unk80069AC0;
extern u8 lbl_803051D8[];
extern void (*lbl_802680DC[])(Unk80069AC0*);
extern void fn_80042CF8(Unk80069AC0*, s32);
extern void fn_80042D30(Unk80069AC0*);
extern void fn_800E9244(Unk80069AC0*);
extern void fn_80040AD0(s32, s32*, s32, s32);
extern s32 fn_8006A384(Unk80069AC0*);
void fn_80069AC0(Unk80069AC0* p) {
    if (p->unk34->unk10 >= 2) {
        s32 v[2];
        fn_80042CF8(p, 2);
        v[0] = p->unk60; v[1] = p->unk64;
        fn_80040AD0(2, v, 0, 0);
        fn_800E9244(p); p->unk0A &= ~1; fn_80042CF8(p, 4);
        return;
    }
    if (lbl_803051D8[2] & 0x20) { fn_80042D30(p); return; }
    if (fn_8006A384(p)) {
        s32 v[2];
        v[0] = p->unk60; v[1] = p->unk64;
        fn_80040AD0(2, v, 0, 0);
        fn_800E9244(p); p->unk0A &= ~1; fn_80042CF8(p, 4);
    } else lbl_802680DC[p->unk11](p);
}
