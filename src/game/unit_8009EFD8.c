#include "game/work_8031BF70.h"
extern void fn_8009C110(const void*, void*, s32);
void fn_8009EFD8(s32 x, s32 y, s32 index) {
    s32 row;
    s32 stride;
    s16* dst = lbl_8031BF70.unk8A8;
    u16* src;
    u8* map = *(u8**)((u8*)lbl_8031BF70.unk288 + 0xC);
    stride = (*(u8**)((u8*)lbl_8031BF70.unk288 + 0x10))[2] * 16;
    src = (u16*)(map + *(u32*)(map + 8)) + index * 0xE0;
    dst += x * 16 + stride * y * 14;
    for (row = 0; row < 14; row++) {
        fn_8009C110(src, dst, 32);
        dst += stride;
        src += 16;
    }
    lbl_8031BF70.unk4AEAC = 1;
}
