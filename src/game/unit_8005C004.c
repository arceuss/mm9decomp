#include "types.h"
typedef struct Unk8005C004 {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ struct Unk8005C004* unk04;
    /* 0x08 */ u8 unk08;
    /* 0x09 */ u8 unk09;
    /* 0x0A */ u8 pad0A[8];
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 unk17;
    /* 0x18 */ u8 pad18[0x60 - 0x18];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0x7C - 0x68];
    /* 0x7C */ u8 unk7C;
    /* 0x7D */ u8 unk7D;
    /* 0x7E */ u8 unk7E;
    /* 0x7F */ u8 unk7F;
    /* 0x80 */ u8 pad80[8];
    /* 0x88 */ u8 unk88[0x40];
    /* 0xC8 */ u8 unkC8;
} Unk8005C004;
typedef struct Unk8005C004Pool {
    /* 0x00 */ u8 pad00[0xC];
    /* 0x0C */ Unk8005C004* cur;
    /* 0x10 */ u32 unk10;
    /* 0x14 */ Unk8005C004 head;
} Unk8005C004Pool;
extern Unk8005C004Pool* lbl_804EE738;
extern Unk8005C004* lbl_804EE984;
extern u8 lbl_804ECAF4[4], lbl_804ECAF8[4], lbl_804ECAFC[4];
extern u8 lbl_80266DE0[], lbl_80266E10[];
extern void fn_800E946C(Unk8005C004*, s32);
extern void fn_800E947C(Unk8005C004*, s32, s32, s32);
extern void fn_800E9750(Unk8005C004*, u16);
extern void fn_8009996C(void*, void*);
extern void fn_800E8BD0(Unk8005C004Pool*);
extern Unk8005C004* fn_800E8C44(Unk8005C004Pool*);
extern void fn_80042DA0(Unk8005C004*, s32);
void fn_8005C004(Unk8005C004* p) {
    u8 count;
    Unk8005C004 *q, *saved;
    s32 distance;
    switch (p->unk12) {
    case 0:
        fn_800E946C(p, lbl_804ECAF4[p->unk14]);
        fn_8009996C(p->unk88, lbl_80266DE0);
        p->unk12++;
    case 1:
        fn_800E9750(p, 0xFFFF);
        distance = p->unk60 - lbl_804EE984->unk60;
        if ((distance < 0 ? -distance : distance) > 0x6000) break;
        count = 0;
        saved = lbl_804EE738->cur;
        fn_800E8BD0(lbl_804EE738);
        while ((q = lbl_804EE738->cur = lbl_804EE738->cur->unk04) != &lbl_804EE738->head) {
            if (q->unk09 == 0x1A && q->unk14 == 3) count++;
        }
        lbl_804EE738->cur = saved;
        if (count < 3) p->unk12++;
        break;
    case 2:
        fn_800E946C(p, lbl_804ECAF8[p->unk14]);
        p->unk12++;
    case 3:
        fn_800E9750(p, 0xFFFF);
        if (p->unk7D == 2) {
            Unk8005C004* spawned;
            fn_8009996C(p->unk88, lbl_80266E10);
            spawned = fn_800E8C44(lbl_804EE738);
            if (spawned) {
                fn_80042DA0(spawned, 0x1A);
                spawned->unk60 = p->unk60;
                spawned->unk64 = p->unk64 - 0x1400;
                spawned->unkC8 = p->unk14;
                spawned->unk14 = 3;
            }
            p->unk12++;
        }
        break;
    case 4:
        fn_800E947C(p, lbl_804ECAF8[p->unk14], 2, 0);
        p->unk16 = 60;
        p->unk12++;
    case 5:
        fn_800E9750(p, 0xFFFF);
        if (--p->unk16 == 0) p->unk12++;
        break;
    case 6:
        fn_800E946C(p, lbl_804ECAFC[p->unk14]);
        p->unk16 = 60;
        p->unk17 = 0;
        p->unk12++;
    case 7:
        if (p->unk7D == 1 && p->unk17 == 0) fn_8009996C(p->unk88, lbl_80266DE0);
        if (p->unk7F == 3 && p->unk7C != lbl_804ECAF4[p->unk14]) fn_800E946C(p, lbl_804ECAF4[p->unk14]);
        fn_800E9750(p, 0xFFFF);
        if (--p->unk16 == 0) p->unk12 = 0;
        break;
    }
}
