#include "types.h"

u32 fn_80027394(u32);
u32 fn_80177360(u32, u32, u32);

void fn_80026450(u32 a, u32* out) {
    u32 r = fn_80027394(a);

    if (r != 0) {
        *out = fn_80177360(r, 0, 0xA);
    } else {
        *out = 0;
    }
}
