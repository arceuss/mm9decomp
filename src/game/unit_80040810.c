#include "types.h"

typedef struct Unk40810 {
    /* 0x000 */ u8 pad000[0x28C];
    /* 0x28C */ u16 unk28C;
} Unk40810;
extern Unk40810 lbl_8031BF70;
extern u32 lbl_804EE988;
extern u16 lbl_80264FC0[][8];
extern u8 lbl_804ECA10[8];

u8 fn_80040810(s32 arg) {
    s32 random;
    s32 sum = 0;
    s32 i;
    u32 value;
    if ((lbl_8031BF70.unk28C & 0x7F) == 13) {
        arg = 7;
    }
    value = lbl_804EE988 * 214013 + 2531011;
    random = (value >> 16) & 0xFF;
    lbl_804EE988 = value & 0x7FFFFFFF;
    for (i = 0; i < 7; i++) {
        sum += lbl_80264FC0[arg][i];
        if (random < sum) {
            break;
        }
    }
    return lbl_804ECA10[i];
}
