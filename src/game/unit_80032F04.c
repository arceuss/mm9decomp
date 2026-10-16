#include "types.h"

typedef struct Unk32F04 {
    /* 0x000 */ u8 pad000[0x26E];
    /* 0x26E */ u8 unk26E;
} Unk32F04;

extern void fn_800316C8(Unk32F04* o, u32 v);

void fn_80032F04(Unk32F04* o) {
    if (o->unk26E == 2) {
        fn_800316C8(o, 0x5000B);
        return;
    }
    if (o->unk26E == 3) {
        o->unk26E = 1;
    }
}
