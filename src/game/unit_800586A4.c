#include "types.h"
typedef struct Unk800586A4 {
    /* 0x00 */ u8 pad00[0x12];
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 pad13[3];
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 unk17;
    /* 0x18 */ u8 pad18[0x60 - 0x18];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ s32 unk70;
    /* 0x74 */ s32 unk74;
    /* 0x78 */ u8 pad78[0x10];
    /* 0x88 */ u8 unk88[1];
} Unk800586A4;
extern u8 lbl_80304B90[], lbl_80266B20[], lbl_80266AF0[];
extern u32 fn_80080484(void*, void*, s32);
extern void fn_80042D30(Unk800586A4*);
extern void fn_800E946C(Unk800586A4*, s32);
extern void fn_800E9750(Unk800586A4*, u16);
extern void fn_8009996C(void*, void*);
extern void fn_80072BDC(s32*, s32, s32);
void fn_800586A4(Unk800586A4* p) {
    s32 v[2];
    if (fn_80080484(lbl_80304B90 + 0x21C, &p->unk60, 1) > 0x1000) { fn_80042D30(p); return; }
    switch (p->unk12) {
    case 0:
        fn_800E946C(p, 0);
        p->unk70 = p->unk64;
        p->unk6C = -0x2C0;
        p->unk12++;
    case 1:
        p->unk64 += p->unk6C;
        if (p->unk64 <= p->unk70 - p->unk74) p->unk12++;
        break;
    case 2:
        p->unk16 = 4; p->unk17 = 0; p->unk12++;
    case 3:
        if (p->unk16 == 0) {
            if (p->unk17 == 0) {
                fn_800E946C(p, 1);
                fn_8009996C(p->unk88, lbl_80266B20);
                p->unk16 = 8; p->unk17++;
            } else p->unk12++;
        } else p->unk16--;
        break;
    case 4:
        v[0] = p->unk60 - 0xC00; v[1] = p->unk64;
        fn_80072BDC(v, 0x240, 0);
        v[0] = p->unk60 + 0xC00;
        fn_80072BDC(v, 0x240, 0x80);
        p->unk16 = 8; p->unk17 = 0; p->unk12++;
    case 5:
        if (p->unk16 == 0) p->unk12++; else p->unk16--;
        break;
    case 6:
        fn_800E946C(p, 0);
        fn_8009996C(p->unk88, lbl_80266AF0);
        p->unk6C = 0x180; p->unk16 = 0x40; p->unk12++;
    case 7:
        p->unk64 += p->unk6C;
        if (p->unk16 == 0) {
            if (p->unk64 < *(s32*)(lbl_80304B90 + 0x260) + 0x6FFF) p->unk12 = 2;
        } else p->unk16--;
        break;
    }
    fn_800E9750(p, 0xFFFF);
}
