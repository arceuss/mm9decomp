#include "types.h"

typedef struct UnkF3C8 {
    /* 0x00 */ u8 pad0[0x5C];
    /* 0x5C */ s32 unk5C;
} UnkF3C8;

extern u8 lbl_80301280[];

void fn_8009F3C8(UnkF3C8* rec) {
    *(u16*)((rec->unk5C >> 4) * 4 + 0x10 + *(u8**)(lbl_80301280 + 0x40)) = 0;
    *(u16*)((rec->unk5C >> 4) * 4 + 0x12 + *(u8**)(lbl_80301280 + 0x40)) = 0;
    *(u32*)(*(u8**)(lbl_80301280 + 0x40)) &= -1 ^ ((rec->unk5C & 0xF) << 8);
}
