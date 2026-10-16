#include "types.h"

void memset(void* dst, s32 value, u32 size);

u32 fn_80029B4C(u32* ctx, u32 size, u32 align) {
    u32 result = 0;
    u32 base;
    u32 tbl;
    u32 limit;
    u32 off;

    if (size < ctx[3]) {
        result = ctx[2];
        if (result & (align - 1)) {
            result = (result + align) & (u32)~(align - 1);
        }
        base = ctx[0];
        tbl = ctx[1];
        tbl = result + size;
        limit = tbl - base;
        ctx[2] = tbl;
        limit = ctx[1] - limit;
        ctx[3] = limit;
        memset((void*)result, 0, size);
    }
    return result;
}
