#include "types.h"

void fn_80029AB8(u32* ctx, u32* n) {
    u32* prev;
    u32* next;
    prev = (u32*)n[0];
    if (prev == 0) {
        next = (u32*)n[1];
        *(u32*)next = 0;
        ctx[2] = n[1];
    } else {
        prev[1] = n[1];
        next = (u32*)n[1];
        next[0] = n[0];
    }
    if (ctx[4] == (u32)n) {
        ctx[4] = n[0];
    }
    n[1] = ctx[3];
    ctx[3] = (u32)n;
}
