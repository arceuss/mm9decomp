#include "types.h"

typedef struct Unk33054 {
    /* 0x000 */ u8 pad000[0x26E];
    /* 0x26E */ u8 unk26E;
} Unk33054;

extern void fn_800316C8(Unk33054* o, u32 v);

void fn_80033054(Unk33054* o) {
    if (o->unk26E == 2) {
        fn_800316C8(o, 0x105000B);
        return;
    }
    if (o->unk26E == 3) {
        o->unk26E = 1;
    }
}
