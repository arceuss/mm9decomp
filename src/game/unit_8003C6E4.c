#include "types.h"

void fn_8003C6E4(u32* p, s32 mode, u8 amount) {
    switch (mode) {
    case 0:
        p[0] = 0x6400;
        p[1] = (u32)(amount << 12) + 0x4400;
        break;
    case 1:
        p[0] = 0x10000 - 0x2300;
        p[1] = amount * 0x2800 + 0x10000 - 0x4400;
        break;
    case 2:
        p[0] = 0x10000 - 0x8000;
        p[1] = (u32)(amount << 12) + 0x2400;
        break;
    case 3:
        p[0] = 0x10000 - 0x3000;
        p[1] = 0x10000 - 0x3200;
        break;
    }
}
