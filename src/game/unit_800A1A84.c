#include "types.h"

void fn_800BB7B8(s32 id);

void fn_800A1A84(void) {
    s32 i;

    fn_800BB7B8(0x8000);
    fn_800BB7B8(0x8100);
    for (i = 0; i < 4; i++) {
        fn_800BB7B8(i | 0x8200);
        fn_800BB7B8(i | 0x8300);
        fn_800BB7B8(i | 0x8400);
    }
}
