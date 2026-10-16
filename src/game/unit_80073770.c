#include "types.h"
typedef struct Unk80073770 {
    /* 0x00 */ u8 pad00[0x9];
    /* 0x09 */ u8 unk09;
    /* 0x0A */ u8 unk0A;
    /* 0x0B */ u8 pad0B[0x5];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15[0x1];
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17[0x1];
    /* 0x18 */ void* unk18;
    /* 0x1C */ u8 pad1C[0x44];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ u8 pad64[0x4];
    /* 0x68 */ s32 unk68;
    /* 0x6C */ u8 pad6C[0x11];
    /* 0x7D */ u8 unk7D;
} Unk80073770;
extern u32 lbl_804EE988;
extern void** lbl_80270168[];
extern void fn_800E946C(Unk80073770*, s32);
extern void fn_800E9750(Unk80073770*, u16);
extern void fn_80073B24(Unk80073770*);
void fn_80073770(Unk80073770* p) {
    u32 r;
    switch (p->unk12) {
    case 0:
        fn_800E946C(p, 1);
        r = lbl_804EE988 * 214013 + 2531011;
        lbl_804EE988 = r & 0x7FFFFFFF;
        p->unk7D = ((r >> 16) & 0x7FFF) % 3;
        p->unk16 = 16;
        p->unk68 = ((((p->unk0A >> 4) & 1) * 2) - 1) << 9;
        p->unk12++;
    case 1:
        p->unk60 += p->unk68;
        if (p->unk16 == 0) {
            p->unk18 = lbl_80270168[p->unk09][2];
            p->unk10 = 2; p->unk13 = 0; p->unk11 = 0; p->unk12 = 0;
            fn_80073B24(p);
        } else {
            p->unk16--; fn_800E9750(p, 0xFFFF);
        }
        break;
    }
}
