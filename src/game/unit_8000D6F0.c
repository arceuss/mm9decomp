#include "types.h"

typedef struct Unk802BDCC0 {
    /* 0x0000 */ u8 pad0[0xF0A0];
    /* 0xF0A0 */ u8 unkF0A0;
    /* 0xF0A1 */ u8 unkF0A1;
    /* 0xF0A2 */ u8 padF0A2[0xF0A8 - 0xF0A2];
    /* 0xF0A8 */ s16 unkF0A8;
    /* 0xF0AA */ u8 unkF0AA;
    /* 0xF0AB */ u8 unkF0AB;
    /* 0xF0AC */ s32 unkF0AC;
    /* 0xF0B0 */ s32 unkF0B0;
    /* 0xF0B4 */ s32 unkF0B4;
    /* 0xF0B8 */ u8 padF0B8[0xF0BC - 0xF0B8];
    /* 0xF0BC */ s16 unkF0BC;
    /* 0xF0BE */ s16 unkF0BE;
} Unk802BDCC0;

extern Unk802BDCC0 lbl_802BDCC0;
extern u32 lbl_80261B70[9];

u32 fn_8000C5A4(s32, u32);

s32 fn_8000D6F0(s32 a, s32 b, u32 c) {
    lbl_802BDCC0.unkF0BE = -1;
    if ((u32)a >= 9) {
        return lbl_802BDCC0.unkF0BE;
    }
    if (lbl_802BDCC0.unkF0AA != 0) {
        return lbl_802BDCC0.unkF0BE;
    }
    if (!fn_8000C5A4(a, c)) {
        return lbl_802BDCC0.unkF0BE;
    }
    if (c > lbl_80261B70[(u8)a] - 0x14) {
        return lbl_802BDCC0.unkF0BE;
    }
    lbl_802BDCC0.unkF0AB = a;
    lbl_802BDCC0.unkF0B0 = b;
    lbl_802BDCC0.unkF0B4 = c;
    lbl_802BDCC0.unkF0BE = 0;
    lbl_802BDCC0.unkF0AA = 1;
    lbl_802BDCC0.unkF0A0 = 2;
    lbl_802BDCC0.unkF0A1 = 0;
    return lbl_802BDCC0.unkF0BE;
}
