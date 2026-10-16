#include "types.h"

s16 fn_800A5ED4(u8* text) {
    s16 lines = 1;

    while (*text < 0xFD) {
        u8 c = *text;

        if (c >= 0xF0) {
            if (c == 0xF0) {
                while (*++text == 0xFF) {
                }
            } else if (c <= 0xF8) {
                text++;
            } else if (c == 0xF9) {
                text += 2;
            }
            if (*text == 0xFC) {
                lines++;
            }
        }
        text++;
    }
    return lines;
}
