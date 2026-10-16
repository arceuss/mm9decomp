#include "types.h"

typedef struct Unk802BDCC0 {
    /* 0x0F0AA */ u8 pad0[0xF0AA];
    /* 0x0F0AA */ u8 unkF0AA;
    /* 0x0F0AB */ u8 padF0AB[0xF0BC - 0xF0AB];
    /* 0x0F0BC */ s16 unkF0BC;
} Unk802BDCC0;

extern Unk802BDCC0 lbl_802BDCC0;
extern u8 lbl_80301420[];

extern void fn_800E534C(s32 a);
extern void fn_800E5274(s32 a);
extern void fn_800316C8(u8* p, u32 v);

void fn_8003BD28(u8* o) {
    if (o[0x277] == 0) {
        s8 t = o[0x26D];
        o[0x277] = 1;
        if (t == 0) {
            fn_800E534C(3);
        } else if (t == 1) {
            fn_800E5274(3);
        }
        if ((s8)o[0x26E] == 1) {
            fn_800E5274(4);
        } else if ((s8)o[0x26E] == 0) {
            fn_800E534C(4);
        }
    }
    {
        s32 v;
        if (lbl_802BDCC0.unkF0AA == 2) {
            v = 0;
        } else {
            v = lbl_802BDCC0.unkF0BC;
        }
        if (v != 0) {
            fn_800316C8(lbl_80301420, 0x20A0007);
        }
    }
}
