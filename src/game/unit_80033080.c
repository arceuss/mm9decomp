#include "types.h"

extern void fn_80036130(u8* o, s32 a);

void fn_80033080(u8* o) {
    fn_80036130(o, 1);
    if (o[0x28B] == 0) {
        o[0x26C] = 0xA;
    }
}
