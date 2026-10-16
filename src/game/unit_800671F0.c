#include "types.h"
#include "game/sound.h"
typedef struct Unk800671F0 {
    /* 0x00 */ u8 pad00[0x12];
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17[0x34 - 0x17];
    /* 0x34 */ struct Unk800671F0* unk34;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0xA0 - 0x68];
    /* 0xA0 */ u32 unkA0;
    /* 0xA4 */ u8 padA4[0xCA - 0xA4];
    /* 0xCA */ u8 unkCA;
} Unk800671F0;
extern void* lbl_804EE738;
extern Unk800671F0* fn_800E8C44(void*);
extern void fn_80042DA0(Unk800671F0*, s32);
extern void fn_800E946C(Unk800671F0*, s32);
extern void fn_800E9750(Unk800671F0*, u16);
extern void fn_800D5234(s32);
void fn_800671F0(Unk800671F0* p) {
    Unk800671F0* q;
    s32 a, b;
    switch (p->unk12) {
    case 0:
        fn_800E946C(p, 0);
        p->unkCA = 2;
        p->unk12++;
    case 1:
        if (p->unkA0 & 8) p->unk12++;
        break;
    case 2:
        fn_800E946C(p, 2);
        p->unk16 = 8;
        p->unk12++;
    case 3:
        if (p->unk16 == 0) p->unk12++;
        else p->unk16--;
        break;
    case 4:
        fn_800E946C(p, 1);
        a = p->unk60;
        b = p->unk64 - 0x1400;
        q = fn_800E8C44(lbl_804EE738);
        if (q != 0) {
            fn_80042DA0(q, 0x24);
            q->unk34 = p;
            q->unk60 = a;
            q->unk64 = b;
            q->unk14 = 1;
        }
        fn_800D5234(SE_EM_CANNON);
        p->unk16 = 30;
        p->unk12++;
    case 5:
        if (p->unk16 == 0) p->unk12++;
        else p->unk16--;
        break;
    case 6:
        fn_800E946C(p, 3);
        p->unk16 = 0;
        p->unk12++;
    case 7:
        if (p->unk16 == 0) {
            if (p->unkCA == 0) p->unk12 = 0;
            else { p->unkCA--; p->unk12 = 2; }
        } else p->unk16--;
        break;
    }
    fn_800E9750(p, 0xFFFF);
}
