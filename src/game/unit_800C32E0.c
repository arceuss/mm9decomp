#include "types.h"

typedef struct Unk800C32E0 {
    /* 0x00 */ u8 pad0[0x11];
    /* 0x11 */ u8 unk11;
} Unk800C32E0;

typedef void (*Unk800C32E0Func)(Unk800C32E0*);

extern Unk800C32E0Func lbl_8027F264[];
extern Unk800C32E0Func lbl_8027F270[];

BOOL fn_800C3B24(Unk800C32E0* work);

void fn_800C32E0(Unk800C32E0* work) {
    if (fn_800C3B24(work) == FALSE) {
        lbl_8027F264[work->unk11](work);
        lbl_8027F270[work->unk11](work);
    }
}
