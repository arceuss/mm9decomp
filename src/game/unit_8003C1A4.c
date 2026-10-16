#include "types.h"

typedef struct Unk3C1A4 {
    /* 0x000 */ u8 pad000[5];
    /* 0x005 */ u8 unk5;
    /* 0x006 */ u8 pad006[0x26C - 0x006];
    /* 0x26C */ u8 unk26C;
    /* 0x26D */ u8 pad26D[0x276 - 0x26D];
    /* 0x276 */ u8 unk276;
} Unk3C1A4;

void fn_8003C1A4(Unk3C1A4* o) {
    if (o->unk26C == 2) {
        o->unk5 = 2;
        o->unk276 = 1;
        return;
    }
    if (o->unk26C == 3) {
        o->unk26C = 1;
    }
}
