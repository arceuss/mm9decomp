#include "types.h"

typedef struct Unk800C0B24 {
    /* 0x00 */ u8 pad0[0x11];
    /* 0x11 */ u8 unk11;
} Unk800C0B24;

typedef void (*Unk800C0B24Func)(Unk800C0B24*);

// one-entry state tables in .sdata; the size has to be known or mwcc won't use sda21.
extern Unk800C0B24Func lbl_804ECF80[1];
extern Unk800C0B24Func lbl_804ECF88[1];

BOOL fn_800C1040(Unk800C0B24* work);

void fn_800C0B24(Unk800C0B24* work) {
    if (fn_800C1040(work) == FALSE) {
        lbl_804ECF80[work->unk11](work);
        lbl_804ECF88[work->unk11](work);
    }
}
