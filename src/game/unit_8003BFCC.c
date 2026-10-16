#include "types.h"
#include "game/sound.h"

typedef struct Unk863BFCC {
    /* 0x000 */ u8 pad000[0x864];
    /* 0x864 */ u16 unk864;
} Unk863BFCC;

extern Unk863BFCC lbl_80319DA0;

extern void fn_800D5234(s32 a);

void fn_8003BFCC(u8* o) {
    u16 st = lbl_80319DA0.unk864;

    if (st & 4) {
        fn_800D5234(SE_CURSOR);
        o[0x26D] = o[0x26D] - 1;
    } else if (st & 8) {
        fn_800D5234(SE_CURSOR);
        o[0x26D] = o[0x26D] + 1;
    }
    if ((s8)o[0x26D] < 0) {
        o[0x26D] = 1;
    } else if ((s8)o[0x26D] > 1) {
        o[0x26D] = 0;
    }
}
