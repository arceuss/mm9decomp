#include "types.h"
typedef struct Unk80080484 {
    /* 0x00 */ u8 pad00[0x40];
    /* 0x40 */ s32 unk40;
    /* 0x44 */ s32 unk44;
    /* 0x48 */ u8 pad48[0x34];
} Unk80080484;
typedef struct Unk80080484Pair { /* 0x00 */ s32 unk0; /* 0x04 */ s32 unk4; } Unk80080484Pair;
s32 fn_80080484(Unk80080484* p, Unk80080484Pair* v, s32 n) {
    s32 result = -1;
    s32 x, y;
    for (; n > 0; n--, p++) {
        x = p->unk40 - v->unk0;
        if (x < 0) { x = -x - 0x8000; if (x < 0) x = 0; }
        else { x -= 0x8000; if (x < 0) x = 0; }
        y = p->unk44 - v->unk4;
        if (y < 0) { y = -y - 0x7000; if (y < 0) y = 0; }
        else { y -= 0x7000; if (y < 0) y = 0; }
        if (x < y) x = y;
        if (x == 0) result = 0;
        if (result != 0 && x > result) result = x;
    }
    if (result < 0) result = 0;
    return result;
}
