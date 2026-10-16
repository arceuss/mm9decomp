#include "types.h"
#include "game/sound.h"

typedef struct Unk3345C {
    /* 0x000 */ u8 pad000[0x864];
    /* 0x864 */ u16 unk864;
} Unk3345C;

extern Unk3345C lbl_80319DA0;
extern u8 lbl_8026441C[];

extern void fn_800D5234(s32 a);

void fn_8003345C(u8* o) {
    s8 v = (s8)o[0x277];
    u16 st = lbl_80319DA0.unk864;

    if (st & 1) {
        fn_800D5234(SE_CURSOR);
        v--;
    } else if (st & 2) {
        fn_800D5234(SE_CURSOR);
        v++;
    }
    if (v < 0) {
        v = 5;
    } else if (v > 5) {
        v = 0;
    }
    o[0x277] = v;
    o[0x275] = lbl_8026441C[o[0x28A] * 6] + ((u8)v * 2);
}
