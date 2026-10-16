#include "types.h"

typedef struct Unk80099998 {
    /* 0x00 */ void* unk0;
    /* 0x04 */ u8 pad4[0x36 - 0x4];
    /* 0x36 */ u8 unk36;
    /* 0x37 */ s8 unk37;
    /* 0x38 */ s8 unk38;
    /* 0x39 */ s8 unk39;
    /* 0x3A */ s8 unk3A;
    /* 0x3B */ u8 unk3B;
} Unk80099998;

void fn_80099998(Unk80099998* work, void* arg, s32 a, s32 b, s32 c, s32 d) {
    work->unk0 = arg;
    work->unk37 = a;
    work->unk38 = b;
    work->unk39 = c;
    work->unk3A = d;
    work->unk3B = 0;
    work->unk36 = (a >= 0) | ((b >= 0) << 1) | ((c >= 0) << 2) | ((d >= 0) << 3);
}
