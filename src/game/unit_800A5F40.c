#include "types.h"

u8* fn_800A5F40(u8* text, s32 count) {
    if (count == 0) {
        return text;
    }
    while (*text < 0xFD) {
        u8 c = *text;

        if (c > 0xF0) {
            if (c <= 0xF8) {
                text++;
            } else if (c == 0xF9) {
                text += 2;
            }
        } else {
            if (count == 0) {
                return text;
            }
            if (c == 0xF0) {
                while (*++text == 0xFF) {
                }
            }
            count--;
        }
        text++;
    }
    return text;
}
