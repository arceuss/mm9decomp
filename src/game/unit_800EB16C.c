#include "types.h"

f64 fn_8017D388(f64 x);
s32 fn_80182580(f64 x);

s32 fn_800EB16C(s32 x, s32 y) {
    return fn_80182580(fn_8017D388((f64)(x * x) + (f64)(y * y)));
}
