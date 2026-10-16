#include "types.h"
typedef struct Unk8006DECC {
    /* 0x00 */ u8 pad00[8];
    /* 0x08 */ s8 unk08;
    /* 0x09 */ u8 unk09;
    /* 0x0A */ u8 pad0A[7];
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
} Unk8006DECC;
extern void (*lbl_802686E8[])(Unk8006DECC*);
extern void fn_800C7C24(s32, s32, s32);
void fn_8006DECC(Unk8006DECC* p) {
    if (p->unk12 == 0) {
        if (p->unk14 == 1) fn_800C7C24(p->unk08, p->unk09, p->unk14);
        p->unk12++;
    }
    lbl_802686E8[p->unk11](p);
}
