#include "types.h"
typedef struct Unk8006DE4C {
    /* 0x00 */ u8 pad00[0x11];
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 pad12[2];
    /* 0x14 */ u8 unk14;
} Unk8006DE4C;
extern void (*lbl_802686B8[])(Unk8006DE4C*);
extern void (*lbl_802686D0[])(Unk8006DE4C*);
extern u8 fn_8006EAC4(Unk8006DE4C*);
void fn_8006DE4C(Unk8006DE4C* p) {
    if (p->unk14 != 0 && fn_8006EAC4(p)) return;
    lbl_802686B8[p->unk11](p);
    lbl_802686D0[p->unk11](p);
}
