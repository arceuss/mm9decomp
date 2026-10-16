#include "types.h"

typedef struct Rec800C2D34 {
    /* 0x00 */ u8 pad0[0x20];
    /* 0x20 */ u8 unk20;
    /* 0x21 */ u8 pad21[0xD8 - 0x21];
} Rec800C2D34;

extern u8 lbl_804EE982;
extern void* lbl_804EE878;

void fn_800E8ABC(void* a, s32 t, Rec800C2D34* b, s32 stride, s32 count);

void fn_8009C130(void* a, Rec800C2D34* b, s16 c) {
    s16 i;

    fn_800E8ABC(a, 10, b, 0xD8, c);
    for (i = 0; i < c; i++) {
        b[i].unk20 = lbl_804EE982 + i;
    }
    lbl_804EE878 = a;
    lbl_804EE982 += c;
}
