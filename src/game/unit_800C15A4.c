#include "types.h"

typedef struct Unk800C15A4 {
    /* 0x00 */ u8 pad0[0x11];
    /* 0x11 */ u8 unk11;
} Unk800C15A4;

typedef void (*Unk800C15A4Func)(Unk800C15A4*);

extern Unk800C15A4Func lbl_8027F184[];
extern Unk800C15A4Func lbl_8027F190[];

BOOL fn_800C24C0(Unk800C15A4* work);

void fn_800C15A4(Unk800C15A4* work) {
    if (fn_800C24C0(work) == FALSE) {
        lbl_8027F184[work->unk11](work);
        lbl_8027F190[work->unk11](work);
    }
}
