#include "types.h"

typedef struct Unk802BDCC0 {
    /* 0x0000 */ u8 pad0[0xF0A8];
    /* 0xF0A8 */ u16 unkF0A8;
} Unk802BDCC0;

extern Unk802BDCC0 lbl_802BDCC0;
extern u8 lbl_802CCDC0[];

void fn_8000E900(s32);
void fn_8000E91C(void);
u32 fn_8011D7A0(s32, s32, s32*, void (*)(s32), void*);

s32 fn_8000C238(s32 a, s32 b) {
    s32 ret = -1;
    s32 out = -1;
    lbl_802BDCC0.unkF0A8 = 0;
    if (fn_8011D7A0(a, b, &out, fn_8000E900, lbl_802CCDC0)) {
        fn_8000E91C();
        return -1;
    }
    {
        volatile u16* p = &lbl_802BDCC0.unkF0A8;
        while (*p == 0) {
        }
    }
    if (out == 0) {
        ret = 0;
    } else if (out & 4) {
        ret = 1;
    } else if (out & 8) {
        ret = 2;
    }
    return ret;
}
