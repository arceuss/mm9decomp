#include "types.h"
typedef struct Unk8006DF4C {
    /* 0x00 */ u8 pad00[0xA];
    /* 0x0A */ u8 unk0A;
    /* 0x0B */ u8 pad0B[7];
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 pad13[3];
    /* 0x16 */ u8 unk16;
} Unk8006DF4C;
extern Unk8006DF4C* lbl_804EE984;
extern void fn_8006DB44(Unk8006DF4C*, s32, s32);
void fn_8006DF4C(Unk8006DF4C* p) {
    if (p->unk12 == 0) { p->unk16 = 1; p->unk12++; }
    if (--p->unk16 == 0) {
        fn_8006DB44(p, 1, ((lbl_804EE984->unk0A >> 4) & 1) ^ 1);
        p->unk16 = 192;
    }
}
