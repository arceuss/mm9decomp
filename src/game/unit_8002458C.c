#include "types.h"

void fn_8002458C(u8* p, s32 v) {
    switch (v) {
    case 1:
        p[0xA] |= 1;
        p[0x8B] = 1;
        break;
    case 2:
        p[0xA] &= ~1;
        p[0x8B] = 0;
        break;
    }
    p[0x8A] = v;
}
