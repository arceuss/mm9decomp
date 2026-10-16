#include "types.h"

char* fn_80027394(s32 key);

void fn_800264A0(s32 key, u64* out) {
    char* str;
    u64 scale = 1;
    char* p;

    str = fn_80027394(key);
    if (str != NULL) {
        for (p = str; *p != '\0'; p++) {
            scale *= 10;
        }
        scale /= 10;
        *out = 0;
        for (; *str != '\0'; str++) {
            *out += (s32)(*str - '0') * scale;
            scale /= 10;
        }
    } else {
        *out = 0;
    }
}
