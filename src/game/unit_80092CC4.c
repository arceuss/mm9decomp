#include "types.h"

typedef struct Unk92CC4 {
    /* 0x0000 */ u8 pad0[0x1008];
    /* 0x1008 */ u8 unk1008;
} Unk92CC4;

extern u8 lbl_803140C0[];

s32 fn_80092CC4(Unk92CC4* p) {
    s32 r5 = 0;

    switch (p->unk1008) {
    case 0:
        if (lbl_803140C0[0x21E0] == 9) r5 = 1;
        break;
    case 1:
        if (lbl_803140C0[0x224D] == 9) r5 = 1;
        break;
    case 2:
        if (lbl_803140C0[0x224E] == 1) r5 = 1;
        break;
    case 3:
        if (lbl_803140C0[0x224F] == 1) r5 = 1;
        break;
    case 4:
        if (lbl_803140C0[0x2250] == 3) r5 = 1;
        break;
    case 5:
        if (lbl_803140C0[0x2247] & 0x80) r5 = 1;
        break;
    case 6:
        if (lbl_803140C0[0x2251] == 1) r5 = 1;
        break;
    case 7:
        if (lbl_803140C0[0x2252] == 3) r5 = 1;
        break;
    }
    return r5;
}
