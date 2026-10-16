#include "types.h"

typedef struct Unk800C03EC {
    /* 0x00 */ u8 pad0[0x11];
    /* 0x11 */ u8 unk11;
} Unk800C03EC;

typedef void (*Unk800C03ECFunc)(Unk800C03EC*);

// one-entry state tables in .sdata; the size has to be known or mwcc won't use sda21.
extern Unk800C03ECFunc lbl_804ECF78[1];
extern Unk800C03ECFunc lbl_804ECF7C[1];

BOOL fn_800C05AC(Unk800C03EC* work);

void fn_800C03EC(Unk800C03EC* work) {
    if (fn_800C05AC(work) == FALSE) {
        lbl_804ECF78[work->unk11](work);
        lbl_804ECF7C[work->unk11](work);
    }
}
