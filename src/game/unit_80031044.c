#include "types.h"

void fn_80031044(s32 a, s32 b, u8* o) {
    switch (a) {
    case 2:
        o[0x2AE] |= 8;
        break;
    case 3:
        o[0x2AE] |= 4;
        break;
    }
    o[0x298] = a;
}
