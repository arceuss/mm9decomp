#include "types.h"

typedef struct Unk8037BF30 {
    /* 0x000 */ u8 pad0[0x41C];
    /* 0x41C */ s32 unk41C;
    /* 0x420 */ u8 unk420;
    /* 0x421 */ u8 pad421[0x428 - 0x421];
} Unk8037BF30;

extern Unk8037BF30 lbl_8037BF30;

void fn_8003FD44(s32 arg0, s32 arg1);

void fn_800A67CC(u8 arg0, s32 arg1) {
    lbl_8037BF30.unk41C = arg1;
    lbl_8037BF30.unk420 = arg0;
    fn_8003FD44(2, 0);
}
