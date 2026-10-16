#include "types.h"

typedef struct Unk800BD1D0 {
    /* 0x00 */ u8 pad0[0x11];
    /* 0x11 */ u8 state;
} Unk800BD1D0;

typedef void (*Unk800BD1D0Func)(Unk800BD1D0*);

// one-entry state tables in .sdata; the size has to be known or mwcc won't use sda21.
extern Unk800BD1D0Func lbl_804ECEF8[1];
extern Unk800BD1D0Func lbl_804ECEFC[1];

BOOL fn_800BD770(Unk800BD1D0* work);

void fn_800BD1D0(Unk800BD1D0* work) {
    if (fn_800BD770(work) == FALSE) {
        lbl_804ECEF8[work->state](work);
        lbl_804ECEFC[work->state](work);
    }
}
