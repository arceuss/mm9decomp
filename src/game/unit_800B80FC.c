#include "types.h"

s32 fn_800B810C(void* a, void* b, void* c, void* d, s32 e, s32 f);

s32 fn_800B80FC(void* a, void* b, void* c, void* d, s32 e) {
    return fn_800B810C(a, b, c, d, e, 2);
}
