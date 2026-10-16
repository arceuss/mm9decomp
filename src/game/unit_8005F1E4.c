#include "types.h"
typedef struct Unk8005F1E4 {
    /* 0x00 */ u8 pad00[8];
    /* 0x08 */ s8 unk08;
    /* 0x09 */ u8 unk09;
    /* 0x0A */ u8 unk0A;
    /* 0x0B */ u8 pad0B[6];
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 pad12[2];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15[0x60 - 0x15];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ u8 pad64[0xAC - 0x64];
    /* 0xAC */ void (*unkAC)(void*);
} Unk8005F1E4;
typedef void (*Unk8005F1E4Func)(Unk8005F1E4*);
extern u8 lbl_803051D8[], lbl_80304B90[], lbl_80267338[], lbl_804EE7E8[8];
extern void fn_80042CF8(Unk8005F1E4*, s32);
extern void fn_80042D30(Unk8005F1E4*);
extern void fn_800E9424(Unk8005F1E4*, s32);
extern void fn_800E91F0(Unk8005F1E4*, void*, s32);
extern void fn_8005F124(void*);
extern u8 fn_8005FA68(Unk8005F1E4*);
extern void fn_800C7C24(s32, s32, s32);
void fn_8005F1E4(Unk8005F1E4* p) {
    u8* data = lbl_80267338;
    fn_80042CF8(p, 1);
    p->unk11 = lbl_804EE7E8[p->unk14];
    p->unk0A |= 3;
    fn_800E9424(p, 0x2B);
    fn_800E91F0(p, data + 0x40, 1);
    p->unkAC = fn_8005F124;
    p->unk60 = *(s32*)(lbl_80304B90 + 0x25C) - 0x9400;
    if (lbl_803051D8[2] & 0x20) { fn_80042D30(p); return; }
    if (fn_8005FA68(p)) {
        fn_800C7C24(p->unk08, p->unk09, 0);
        ((Unk8005F1E4Func*)(data + 0x2C))[p->unk11](p);
    } else {
        ((Unk8005F1E4Func*)(data + 0x14))[p->unk11](p);
        ((Unk8005F1E4Func*)(data + 0x20))[p->unk11](p);
    }
}
