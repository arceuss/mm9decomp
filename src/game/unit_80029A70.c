#include "types.h"

u32* fn_80029A70(u32* ctx) {
    u32* n;
    u32 t;
    n = (u32*)ctx[3];
    if (n != 0) {
        ctx[3] = n[1];
        n[0] = 0;
        n[1] = ctx[2];
        *(u32*)ctx[2] = (u32)n;
        t = ctx[4];
        ctx[2] = (u32)n;
        if (t == 0) {
            ctx[4] = (u32)n;
        }
    }
    return n;
}
