#include "types.h"

typedef struct Unk863C064 {
    /* 0x000 */ u8 pad000[0x864];
    /* 0x864 */ u16 unk864;
} Unk863C064;

extern Unk863C064 lbl_80319DA0;

extern void fn_800D5234(s32 a);

void fn_8003C064(u8* o) {
    u16 st = lbl_80319DA0.unk864;

    if (st & 4) {
        fn_800D5234(0);
        o[0x26E] = o[0x26E] - 1;
    } else if (st & 8) {
        fn_800D5234(0);
        o[0x26E] = o[0x26E] + 1;
    }
    if ((s8)o[0x26E] < 0) {
        o[0x26E] = 1;
    } else if ((s8)o[0x26E] > 1) {
        o[0x26E] = 0;
    }
}
