#include "types.h"

typedef struct Unk800BC9D8 {
    /* 0x00 */ u8 pad0[0x11];
    /* 0x11 */ u8 state;
} Unk800BC9D8;

typedef void (*Unk800BC9D8Func)(Unk800BC9D8*);

// one-entry state tables in .sdata; the size has to be known or mwcc won't use sda21.
extern Unk800BC9D8Func lbl_804ECED0[1];
extern Unk800BC9D8Func lbl_804ECED4[1];

BOOL fn_800BCB88(Unk800BC9D8* work);

void fn_800BC9D8(Unk800BC9D8* work) {
    if (fn_800BCB88(work) == FALSE) {
        lbl_804ECED0[work->state](work);
        lbl_804ECED4[work->state](work);
    }
}
