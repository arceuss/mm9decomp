#include "types.h"

typedef struct Unk29B30 {
    /* 0x00 */ u32 unk0;
    /* 0x04 */ u32 unk4;
    /* 0x08 */ u32 unk8;
    /* 0x0C */ u32 unkC;
} Unk29B30;

void fn_80029B30(Unk29B30* n) {
    if (n != 0) {
        n->unk8 = n->unk0;
        n->unkC = n->unk4;
    }
}
