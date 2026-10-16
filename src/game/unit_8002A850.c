#include "types.h"

typedef struct Unk2A80C {
    /* 0x00 */ u32 unk0;
    /* 0x04 */ u32 unk4;
    /* 0x08 */ u32 unk8;
    /* 0x0C */ u32 unkC;
} Unk2A80C;

void fn_8002A850(Unk2A80C* dst, u32* src) {
    dst->unk0 = 0xC;
    dst->unk4 = src[1];
    dst->unk8 = src[2];
    dst->unkC = src[3];
}
