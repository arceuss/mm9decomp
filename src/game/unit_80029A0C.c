#include "types.h"

typedef struct Unk29A0C {
    /* 0x00 */ u32 unk0;
    /* 0x04 */ u32 unk4;
    /* 0x08 */ u32 unk8;
    /* 0x0C */ u32 unkC;
    /* 0x10 */ u32 unk10;
    /* 0x14 */ u16 unk14;
    /* 0x16 */ u16 unk16;
} Unk29A0C;

void fn_80029A0C(Unk29A0C* list, u32 start, s16 width, u16 count) {
    u16 stride;
    u32 member;
    s32 i;
    u32 step;

    list->unk14 = width;
    list->unk0 = start;
    list->unk16 = count;
    list->unk10 = 0;
    stride = (u16)((u16)width + 8);
    member = start;
    step = 0;
    i = 0;
    while (i < list->unk16) {
        *(u32*)(member + 4) = step;
        step = member;
        member += stride;
        i++;
    }
    list->unk4 = 0;
    list->unk8 = (u32)&list->unk4;
    list->unkC = member - stride;
}
