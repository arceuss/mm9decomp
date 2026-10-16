#include "types.h"

typedef struct Unk800C9EA8 {
    /* 0x0 */ u8 pad0[0x8];
    /* 0x8 */ u16 unk8;
    /* 0xA */ u16 unkA;
} Unk800C9EA8;

void fn_800C9EA8(Unk800C9EA8* src, u16* dst) {
    dst[0] = src->unk8;
    dst[1] = src->unkA;
}
