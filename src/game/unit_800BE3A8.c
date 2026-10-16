#include "types.h"

typedef struct Unk800BE3A8 {
    /* 0x00 */ u8 pad0[0x11];
    /* 0x11 */ u8 state;
} Unk800BE3A8;

typedef void (*Unk800BE3A8Func)(Unk800BE3A8*);

// one-entry state tables in .sdata; the size has to be known or mwcc won't use sda21.
extern Unk800BE3A8Func lbl_804ECF00[1];
extern Unk800BE3A8Func lbl_804ECF08[1];

BOOL fn_800BE7C4(Unk800BE3A8* work);

void fn_800BE3A8(Unk800BE3A8* work) {
    if (fn_800BE7C4(work) == FALSE) {
        lbl_804ECF00[work->state](work);
        lbl_804ECF08[work->state](work);
    }
}
