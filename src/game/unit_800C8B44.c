#include "types.h"

typedef struct Unk800C8B44 {
    /* 0x00 */ s32 x;
    /* 0x04 */ s32 y;
    /* 0x08 */ u16 unk8;
    /* 0x0A */ u16 unkA;
    /* 0x0C */ void* unkC;
    /* 0x10 */ void* unk10;
    /* 0x14 */ void* unk14;
} Unk800C8B44;

void fn_800C8B44(Unk800C8B44* work, s32* pos, s32 unused, void* a, void* b, void* c) {
    work->x = pos[0];
    work->y = pos[1];
    work->unkC = a;
    work->unk10 = b;
    work->unk14 = c;
    work->unk8 = pos[0] & 0x1FF;
    work->unkA = pos[1] & 0x1FF;
}
