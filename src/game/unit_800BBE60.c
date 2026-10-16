#include "types.h"

typedef struct Unk800BBE60 {
    /* 0x00 */ u8 pad0[0x11];
    /* 0x11 */ u8 state;
} Unk800BBE60;

typedef void (*Unk800BBE60Func)(Unk800BBE60*);

// one-entry state tables in .sdata; the size has to be known or mwcc won't use sda21.
extern Unk800BBE60Func lbl_804ECEAC[1];
extern Unk800BBE60Func lbl_804ECEB0[1];

BOOL fn_800BC214(Unk800BBE60* work);

void fn_800BBE60(Unk800BBE60* work) {
    if (fn_800BC214(work) == FALSE) {
        lbl_804ECEAC[work->state](work);
        lbl_804ECEB0[work->state](work);
    }
}
