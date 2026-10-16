#include "types.h"

void fn_800F6508(u8* p);

void fn_80029C78(u8* obj) {
    u16 h = *(u16*)(obj + 0x382);
    h |= 1;
    *(u16*)(obj + 0x382) = h;
    if ((h & 2) == 0) {
        fn_800F6508(obj + 0x348);
    }
}
