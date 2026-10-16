#include "types.h"
typedef struct Unk80061650 {
    /* 0x00 */ u8 pad00[0xC];
    /* 0x0C */ u8 unk0C;
    /* 0x0D */ u8 pad0D[3];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 pad13[3];
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17[0x2E - 0x17];
    /* 0x2E */ u8 unk2E;
    /* 0x2F */ u8 pad2F[5];
    /* 0x34 */ struct Unk80061650* unk34;
    /* 0x38 */ u8 pad38[0x50-0x38];
    /* 0x50 */ u32 unk50a:30;
                 u32 unk50b:2;
    /* 0x54 */ u8 pad54[0x64-0x54];
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0x7F-0x68];
    /* 0x7F */ u8 unk7F;
    /* 0x80 */ u8 pad80[0xA0-0x80];
    /* 0xA0 */ u32 unkA0;
    /* 0xA4 */ u8 padA4[0xB6-0xA4];
    /* 0xB6 */ s16 unkB6;
} Unk80061650;
extern void fn_80042D30(Unk80061650*);
extern void fn_800E946C(Unk80061650*, s32);
extern void fn_800E9750(Unk80061650*, u16);
extern void fn_800E9AA0(Unk80061650*, s32, s32);
extern void fn_800E9C90(Unk80061650*);
void fn_80061650(Unk80061650* p) {
    Unk80061650* q = p->unk34;
    if (q->unk10 == 4) { fn_80042D30(p); return; }
    p->unk64 = q->unk64 - 0x2800;
    switch (p->unk12) {
    case 0:
        fn_800E946C(p, 0x1D);
        p->unk0C |= 0x10;
        p->unk50b = 2;
        p->unk2E = 0x11;
        p->unk12++;
    case 1:
        fn_800E9750(p, 0xFFFF);
        if ((q->unkA0 & 0x200) || q->unkB6 == 0) p->unk12 = 4;
        else if (q->unkA0 & 1) p->unk12++;
        break;
    case 2:
        fn_800E946C(p, 0x1F);
        p->unk12++;
    case 3:
        if (p->unk7F == 3) p->unk12 = 0;
        fn_800E9750(p, 0xFFFF);
        break;
    case 4:
        fn_800E946C(p, 0x1E);
        p->unk16 = 0x30;
        p->unk12++;
    case 5:
        fn_800E9750(p, 0xFFFF);
        if (p->unk16 == 0) p->unk12++; else p->unk16--;
        break;
    case 6:
        fn_800E9AA0(p, 3, 0);
        p->unk12++;
    case 7:
        fn_800E9750(p, 0xFFFF);
        fn_800E9C90(p);
        break;
    }
}
