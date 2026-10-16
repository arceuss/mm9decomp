#include "types.h"
typedef struct Unk800537FC {
    /* 0x00 */ u8 pad00[0x11];
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 pad13[3];
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17[0x60 - 0x17];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ u8 pad64[0x88 - 0x64];
    /* 0x88 */ u8 unk88[0x18];
    /* 0xA0 */ u32 unkA0;
} Unk800537FC;
extern Unk800537FC* lbl_804EE984;
extern u8 lbl_80266588[];
extern void fn_800E946C(Unk800537FC*, s32);
extern void fn_800E9750(Unk800537FC*, u16);
extern void fn_8009996C(void*, void*);
void fn_800537FC(Unk800537FC* p) {
    u8 flag;
    s32 d;
    switch (p->unk12) {
    case 0:
        fn_800E946C(p, 0);
        fn_8009996C(p->unk88, lbl_80266588);
        p->unk16 = 60; p->unk12++;
    case 1:
        fn_800E9750(p, 0xFFFF);
        flag = 0;
        if (p->unk16 == 0) {
            d = lbl_804EE984->unk60 - p->unk60;
            if ((d < 0 ? -d : d) <= 0x5000) flag = 1;
        } else p->unk16--;
        if (p->unkA0 & 8) flag++;
        if (flag) { p->unk11 = 1; p->unk12 = 0; }
        break;
    }
}
