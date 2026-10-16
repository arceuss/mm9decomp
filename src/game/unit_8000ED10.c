#include "types.h"

void fn_8009C110(void* src, void* dst, u32 size);

void fn_8000ED10(void* unused, u8* dst, u32* arc, u8 idx, s8 x, s8 y) {
    u8* data = (u8*)arc + arc[idx];
    s32 width = *(u16*)(data + 4);
    s32 height = *(u16*)(data + 6);
    u16* src = (u16*)(data + 8);
    u16* base = src;
    s32 stride = width;
    s8 x0 = x;
    s32 rowY;
    s32 rows;
    s32 cols;
    u8* out;
    u32 size;
    s32 j;
    s32 off;
    s32 s;

    while (height > 0) {
        rowY = y << 5;
        rows = 32 - (y & 31);
        while (width > 0) {
            cols = 32 - (x & 31);
            out = dst + (x + rowY) * 2;
            size = cols * 2;
            if (width < cols) {
                size = width * 2;
            }
            for (j = 0, off = 0, s = 0; j < height && j < rows; j++, off += 0x40, s += stride) {
                fn_8009C110(src + s, out + off, size);
            }
            width -= cols;
            src += cols;
            x = 0;
            dst += 0x800;
        }
        width = stride;
        x = x0;
        height -= rows;
        y = 0;
        src = base + stride * rows;
    }
}
