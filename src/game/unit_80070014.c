#include "types.h"
typedef struct Unk80070014 {
    /* 0x00 */ u8 pad00[8];
    /* 0x08 */ s8 unk08;
    /* 0x09 */ u8 unk09;
    /* 0x0A */ u8 pad0A[7];
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
} Unk80070014;
extern void (*lbl_80268878[])(Unk80070014*);
extern void fn_800C7C24(s32, s32, s32);
void fn_80070014(Unk80070014* p) {
    if (p->unk12 == 0) {
        fn_800C7C24(p->unk08, p->unk09, p->unk14);
        p->unk12++;
    }
    lbl_80268878[p->unk11](p);
}
