#include "types.h"
typedef struct Unk8006DB44 {
    /* 0x00 */ u8 pad00[0xA];
    /* 0x0A */ u8 unk0A;
    /* 0x0B */ u8 pad0B[9];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0x34 - 0x16];
    /* 0x34 */ struct Unk8006DB44* unk34;
    /* 0x38 */ u8 pad38[0x54 - 0x38];
    /* 0x54 */ u32 unk54a:21;
                 u32 unk54b:1;
                 u32 unk54c:10;
    /* 0x58 */ u8 pad58[8];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0xD2 - 0x68];
    /* 0xD2 */ u8 unkD2;
} Unk8006DB44;
extern void* lbl_804EE738;
extern u8 lbl_80304B90[];
extern Unk8006DB44* fn_800E8C44(void*);
extern void fn_80042DA0(Unk8006DB44*, s32);
Unk8006DB44* fn_8006DB44(Unk8006DB44* p, u8 a, u8 b) {
    Unk8006DB44* q = fn_800E8C44(lbl_804EE738);
    if (q) {
        fn_80042DA0(q, 0x2A);
        q->unk34 = p; q->unk14 = a; q->unk15 = b; q->unkD2 = p->unkD2;
        if (a == 1) {
            if (b == 0) q->unk60 = *(s32*)(lbl_80304B90 + 0x25C) + 0x7FFF;
            else q->unk60 = *(s32*)(lbl_80304B90 + 0x25C) - 0x8000;
            q->unk64 = p->unk64;
        } else if (a == 2) {
            u32 f = (p->unk0A >> 4) & 1;
            if (f) q->unk0A |= 0x10; else q->unk0A &= 0xEF;
            q->unk54b = f;
            q->unk60 = p->unk60; q->unk64 = p->unk64 + 0xA00;
        } else if (a == 3) {
            q->unk60 = p->unk60; q->unk64 = p->unk64;
        }
    }
    return q;
}
