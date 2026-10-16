#include "types.h"
typedef struct Unk800623D4 {
    /* 0x00 */ u8 pad00[0xA];
    /* 0x0A */ u8 unk0A;
    /* 0x0B */ u8 pad0B[6];
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 pad13[3];
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17[0x54 - 0x17];
    /* 0x54 */ u32 unk54a:21;
                 u32 unk54b:1;
                 u32 unk54c:10;
    /* 0x58 */ u8 pad58[8];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ s32 unk70;
    /* 0x74 */ s32 unk74;
} Unk800623D4;
extern u8 lbl_80304B90[];
extern void (*lbl_8026790C[])(Unk800623D4*);
extern void fn_800E9244(Unk800623D4*);
extern void fn_800E946C(Unk800623D4*, s32);
extern u32 fn_80080484(void*, void*, s32);
extern void fn_80042CF8(Unk800623D4*, s32);
extern void fn_800E9758(Unk800623D4*);
void fn_800623D4(Unk800623D4* p) {
    u8 flag;
    switch (p->unk12) {
    case 0:
        fn_800E946C(p, 0);
        fn_800E9244(p);
        p->unk16 = 16;
        p->unk74 = -0x20;
        p->unk6C = 0;
        p->unk12++;
    case 1:
        p->unk64 += p->unk6C;
        if (fn_80080484(lbl_80304B90 + 0x21C, &p->unk60, 1) > 0x1000) {
            fn_80042CF8(p, 2);
            p->unk11 = 1;
            lbl_8026790C[p->unk11](p);
            return;
        }
        p->unk6C += p->unk74;
        if (p->unk6C < -0x700) p->unk6C = -0x700;
        if (--p->unk16 == 0) {
            flag = !((p->unk0A >> 4) & 1);
            if (flag) p->unk0A |= 0x10; else p->unk0A &= 0xEF;
            p->unk54b = flag;
            p->unk16 = 16;
        }
        fn_800E9758(p);
        break;
    }
}
