#include "types.h"
extern u8 lbl_8036CF50[];
u32 fn_800A5FA8(u8* src, u8* dst, u32 length) {
    u32 original = length;
    u8 c;
    while ((c = *src) < 0xFD && length > 3) {
        if (c < 0xF0) *dst = c;
        else if (c == 0xF0) {
            do { *dst++ = c; c = *++src; } while (c == 0xFF);
            *dst = c;
        } else if (c <= 0xF8) {
            *dst = c; *++dst = *++src;
        } else if (c == 0xF9) {
            dst[0] = c; dst[1] = src[1];
            src += 2; dst += 2; *dst = *src;
        } else if (c == 0xFA) {
            u32 size = fn_800A5FA8(lbl_8036CF50 + 0xEFBC, dst, length) - 1;
            length -= size; dst += size;
        } else *dst = c;
        src++; dst++; length--;
    }
    if (length == 0) dst[-1] = 0xFF;
    else *dst = 0xFF;
    return original - length;
}
