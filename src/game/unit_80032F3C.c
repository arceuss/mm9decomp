#include "types.h"

typedef struct Unk32F3C {
    /* 0x000 */ u8 pad000[0x26E];
    /* 0x26E */ u8 unk26E;
} Unk32F3C;

extern void fn_800316C8(Unk32F3C* o, u32 v);

void fn_80032F3C(Unk32F3C* o) {
    if (o->unk26E == 2) {
        fn_800316C8(o, 0x202000B);
        return;
    }
    if (o->unk26E == 3) {
        o->unk26E = 1;
    }
}
