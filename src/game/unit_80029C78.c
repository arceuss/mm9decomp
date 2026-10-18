#include "types.h"

void OSSignalCond(u8* p);

void fn_80029C78(u8* obj) {
    u16 h = *(u16*)(obj + 0x382);
    h |= 1;
    *(u16*)(obj + 0x382) = h;
    if ((h & 2) == 0) {
        OSSignalCond(obj + 0x348);
    }
}
