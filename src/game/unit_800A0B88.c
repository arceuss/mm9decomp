#include "types.h"

extern void fn_800BB7B8(s32);

void fn_800A0B88(void) {
    s32 i;
    fn_800BB7B8(0x8000);
    fn_800BB7B8(0x8100);
    fn_800BB7B8(0x8300);
    for (i = 0; i < 3; i++) {
        fn_800BB7B8(0x8200 | i);
    }
}
