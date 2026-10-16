#include "types.h"

typedef struct Unk335C0 {
    /* 0x000 */ u8 pad000[0x864];
    /* 0x864 */ u16 unk864;
} Unk335C0;

extern Unk335C0 lbl_80319DA0;
extern u8 lbl_8026441C[];

extern void fn_800D5234(s32 a);

void fn_800335C0(u8* o) {
    s8 v = (s8)o[0x27A];
    u16 st = lbl_80319DA0.unk864;

    if (st & 1) {
        fn_800D5234(0);
        v--;
    } else if (st & 2) {
        fn_800D5234(0);
        v++;
    }
    if (v < 0) {
        v = 3;
    } else if (v > 3) {
        v = 0;
    }
    o[0x27A] = v;
    o[0x275] = *(lbl_8026441C + o[0x28A] * 6 + 3) + ((u8)v * 2);
}
