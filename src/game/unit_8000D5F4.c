#include "types.h"

typedef struct Unk802BDCC0 {
    /* 0x0000 */ u8 pad0[0xF0A8];
    /* 0xF0A8 */ u16 unkF0A8;
} Unk802BDCC0;

extern Unk802BDCC0 lbl_802BDCC0;
extern u8 lbl_802CCDC0[];

void fn_8000E900(void);
void fn_8000E91C(void);
s32 fn_8011A778(s32, void (*)(void), void*);

void fn_8000D5F4(s32 a) {
    lbl_802BDCC0.unkF0A8 = 0;
    if (fn_8011A778(a, fn_8000E900, lbl_802CCDC0 + 0xBC)) {
        fn_8000E91C();
    } else {
        volatile u16* p = &lbl_802BDCC0.unkF0A8;
        while (*p == 0) {
        }
    }
}
