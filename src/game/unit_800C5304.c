#include "types.h"

typedef struct Unk800C5304 {
    /* 0x00 */ u8 pad0[0x11];
    /* 0x11 */ u8 unk11;
} Unk800C5304;

typedef void (*Unk800C5304Func)(Unk800C5304*);

extern Unk800C5304Func lbl_8027F368[];
extern Unk800C5304Func lbl_8027F378[];

BOOL fn_800C6414(Unk800C5304* work);

void fn_800C5304(Unk800C5304* work) {
    if (fn_800C6414(work) == FALSE) {
        lbl_8027F368[work->unk11](work);
        lbl_8027F378[work->unk11](work);
    }
}
