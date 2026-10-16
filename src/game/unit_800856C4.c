#include "types.h"

typedef struct Unk800856C4 {
    /* 0x0000 */ u8 pad0[0x1004];
    /* 0x1004 */ u8 unk1004;
    /* 0x1005 */ u8 unk1005;
} Unk800856C4;

extern u8 lbl_80305648[0x34];

void fn_800856C4(Unk800856C4* menu) {
    u8 i;
    u8 count;

    count = 0;
    for (i = 0; i < 50; i++) {
        if (lbl_80305648[i] == 1) {
            count++;
            if (++menu->unk1004 >= 5) {
                menu->unk1004 = 0;
                menu->unk1005++;
            }
        }
    }
    menu->unk1004 *= 2;
    if (count == 50) {
        menu->unk1005 = count;
    }
}
