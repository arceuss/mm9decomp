#include "types.h"

typedef struct Unk8039B190 {
    /* 0x00 */ u8 pad0[0x92];
    /* 0x92 */ u8 unk92;
    /* 0x93 */ u8 unk93;
    /* 0x94 */ u8 pad94[0x9C - 0x94];
    /* 0x9C */ s16* unk9C;
    /* 0xA0 */ s16* unkA0;
    /* 0xA4 */ u8 padA4[0xB0 - 0xA4];
} Unk8039B190;

extern Unk8039B190 lbl_8039B190;

s16* fn_8009BECC(s32 size);

void fn_8003FB88(s32 a, s32 b) {
    s32 top = (a << 8) / 0x1000;
    s32 bot = (b << 8) / 0x1000;
    s16* p = fn_8009BECC(0x1C0);
    s32 i;

    if (p != NULL) {
        lbl_8039B190.unkA0 = p;
        lbl_8039B190.unk93 |= 1;
        for (i = 0xE0; i > 0xBE; i--) {
            p[i] = 0;
        }
        for (; i >= 0x48; i--) {
            p[i] = bot;
        }
        for (; i >= 0; i--) {
            p[i] = top;
        }
    }
}
