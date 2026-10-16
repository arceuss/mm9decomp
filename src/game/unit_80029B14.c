#include "types.h"

typedef struct Unk29B14 {
    /* 0x00 */ u32 unk0;
    /* 0x04 */ u32 unk4;
    /* 0x08 */ u32 unk8;
    /* 0x0C */ u32 unkC;
} Unk29B14;

void fn_80029B14(Unk29B14* n, u32 a, u32 b) {
    if (n != 0) {
        n->unk0 = a;
        n->unk8 = a;
        n->unk4 = b;
        n->unkC = b;
    }
}
