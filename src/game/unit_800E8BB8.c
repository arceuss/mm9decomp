#include "types.h"

typedef struct Unk800E8BB8 {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s16 unk4;
    /* 0x6 */ s16 unk6;
    /* 0x8 */ s16 unk8;
} Unk800E8BB8;

void fn_800E8ABC(Unk800E8BB8* work, s8 arg1, s32 arg2, s16 arg3, s16 arg4);

void fn_800E8BB8(Unk800E8BB8* work) {
    fn_800E8ABC(work, work->unk4, work->unk0, work->unk6, work->unk8);
}
