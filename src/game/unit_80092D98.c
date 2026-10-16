#include "types.h"

typedef struct Unk92D98 {
    /* 0x0000 */ u8 pad0[0x1008];
    /* 0x1008 */ u8 unk1008;
    /* 0x1009 */ u8 pad1009[0x2247 - 0x1009];
    /* 0x2247 */ u8 unk2247;
    /* 0x2248 */ u8 unk2248;
    /* 0x2249 */ u8 pad2249[0x224D - 0x2249];
    /* 0x224D */ u8 unk224D;
    /* 0x224E */ u8 unk224E;
    /* 0x224F */ u8 unk224F;
    /* 0x2250 */ u8 unk2250;
    /* 0x2251 */ u8 unk2251;
    /* 0x2252 */ u8 unk2252;
} Unk92D98;

extern u8 lbl_803140C0[];

void fn_80092D98(Unk92D98* p) {
    switch (p->unk1008) {
    case 0:
        lbl_803140C0[0x21E0]++;
        return;
    case 1:
        p->unk224D++;
        return;
    case 2:
        p->unk224E++;
        return;
    case 3:
        p->unk224F++;
        return;
    case 4:
        p->unk2250++;
        return;
    case 5:
        p->unk2247 |= 0x80;
        return;
    case 6:
        p->unk2251++;
        return;
    case 7:
        p->unk2252++;
        return;
    case 8:
        if (p->unk2248 & 1) p->unk2248 &= ~1;
        else p->unk2248 |= 1;
        return;
    case 9:
        if (p->unk2247 & 0x20) p->unk2247 &= ~0x20;
        else p->unk2247 |= 0x20;
        return;
    }
}
