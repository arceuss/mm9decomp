#include "types.h"

typedef struct Unk32ED8 {
    /* 0x000 */ u8 pad000[0x26E];
    /* 0x26E */ u8 unk26E;
} Unk32ED8;

extern void fn_800316C8(Unk32ED8* o, u32 v);

void fn_80032ED8(Unk32ED8* o) {
    if (o->unk26E == 2) {
        fn_800316C8(o, 0x115000B);
        return;
    }
    if (o->unk26E == 3) {
        o->unk26E = 1;
    }
}
