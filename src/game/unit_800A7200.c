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

typedef struct Unk8037C3D8 {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 idx;
    /* 0x02 */ u8 pad2[0x14 - 0x2];
    /* 0x14 */ s32 top;
    /* 0x18 */ s32 scale;
    /* 0x1C */ u8 pad1C[0x50 - 0x1C];
} Unk8037C3D8;

extern Unk8039B190 lbl_8039B190;
extern Unk8037C3D8 lbl_8037C3D8;
extern u16 lbl_804ECDF0[4];

s16* fn_8009BECC(s32 size);

void fn_800A7200(void) {
    s32 i;
    s32 off;
    s32 h;
    s32 top;
    s16* p;
    s32 lim;

    i = 0xDF;
    h = lbl_804ECDF0[lbl_8037C3D8.idx];
    top = lbl_8037C3D8.top;
    off = ((h >> 1) * lbl_8037C3D8.scale) / 0x1000;
    p = fn_8009BECC(0x1C0);

    if (p != NULL) {
        lbl_8039B190.unk9C = p;
        lbl_8039B190.unk92 |= 2;
        lim = (top + off + 7) & ~7;
        for (; i >= lim && i >= top; i--) {
            p[i] = h + 1 - i;
        }
        for (; i >= top; i--) {
            p[i] = h - lim;
        }
        lim = (top - off) & ~7;
        for (; i >= 0 && i >= lim; i--) {
            p[i] = -lim;
        }
        for (; i >= 0; i--) {
            p[i] = h + 1 - i;
        }
    }
}
