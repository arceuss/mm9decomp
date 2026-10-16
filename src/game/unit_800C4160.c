#include "types.h"

typedef struct Unk800C4160 {
    /* 0x00 */ u8 pad0[0x11];
    /* 0x11 */ u8 unk11;
} Unk800C4160;

typedef void (*Unk800C4160Func)(Unk800C4160*);

extern Unk800C4160Func lbl_8027F2E8[];
extern Unk800C4160Func lbl_8027F2F8[];

BOOL fn_800C4F38(Unk800C4160* work);

void fn_800C4160(Unk800C4160* work) {
    if (fn_800C4F38(work) == FALSE) {
        lbl_8027F2E8[work->unk11](work);
        lbl_8027F2F8[work->unk11](work);
    }
}
