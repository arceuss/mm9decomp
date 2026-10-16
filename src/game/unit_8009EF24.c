#include "game/work_8031BF70.h"
extern void fn_8009C110(const void*, void*, s32);
void fn_8009EF24(s32 x, s32 y, u16* data) {
    s32 stride;
    s16* dst = lbl_8031BF70.unk8A8;
    s16 row;
    s16 width;
    s16 height;
    u16* src;
    width = *data++ * 2;
    height = *data++;
    stride = (*(u8**)((u8*)lbl_8031BF70.unk288 + 0x10))[2] * 16;
    src = data;
    dst += x + stride * y;
    for (row = 0; row < height; row++) {
        fn_8009C110(src, dst, width);
        src += width >> 1;
        dst += stride;
    }
    lbl_8031BF70.unk4AEAC = 1;
}
