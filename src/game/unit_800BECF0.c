#include "types.h"

typedef struct Unk800BECF0 {
    /* 0x00 */ u8 pad0[0x11];
    /* 0x11 */ u8 state;
} Unk800BECF0;

typedef void (*Unk800BECF0Func)(Unk800BECF0*);

// one-entry state tables in .sdata; the size has to be known or mwcc won't use sda21.
extern Unk800BECF0Func lbl_804ECF30[1];
extern Unk800BECF0Func lbl_804ECF38[1];

BOOL fn_800BF494(Unk800BECF0* work);

void fn_800BECF0(Unk800BECF0* work) {
    if (fn_800BF494(work) == FALSE) {
        lbl_804ECF30[work->state](work);
        lbl_804ECF38[work->state](work);
    }
}
