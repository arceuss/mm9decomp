#include "types.h"

typedef struct Unk8037CC40 {
    /* 0x0000 */ u8 pad0[0x1008];
    /* 0x1008 */ u8 unk1008[0x7230 - 0x1008];
} Unk8037CC40;

extern Unk8037CC40 lbl_8037CC40;

void fn_800AA0E4(void* work, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7);

void fn_800A7F64(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    fn_800AA0E4(lbl_8037CC40.unk1008, arg0, arg1, arg1, arg2, arg3, 0, 1);
}
