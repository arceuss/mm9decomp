#include "types.h"

typedef struct Unk800BFB58 {
    /* 0x00 */ u8 pad0[0x11];
    /* 0x11 */ u8 state;
} Unk800BFB58;

typedef void (*Unk800BFB58Func)(Unk800BFB58*);

// one-entry state tables in .sdata; the size has to be known or mwcc won't use sda21.
extern Unk800BFB58Func lbl_804ECF58[1];
extern Unk800BFB58Func lbl_804ECF60[1];

BOOL fn_800BFFE8(Unk800BFB58* work);

void fn_800BFB58(Unk800BFB58* work) {
    if (fn_800BFFE8(work) == FALSE) {
        lbl_804ECF58[work->state](work);
        lbl_804ECF60[work->state](work);
    }
}
