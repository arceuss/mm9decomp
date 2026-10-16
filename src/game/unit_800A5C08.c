#include "types.h"

typedef struct Unk800A62B8 {
    /* 0x00 */ u8 pad0[0x5];
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 pad6[0x28 - 0x6];
    /* 0x28 */ s16 unk28;
    /* 0x2A */ s16 unk2A;
} Unk800A62B8;

void fn_800A62B8(Unk800A62B8* work, s32 arg1, u32 arg2, s32 arg3, u16 arg4);

void fn_800A5C08(Unk800A62B8* work, s32 arg1, s32 arg2, u32 arg3, u8 arg4) {
    work->unk5 = arg4;
    fn_800A62B8(work, arg2, arg3, arg1, 0xFFFF);
}
