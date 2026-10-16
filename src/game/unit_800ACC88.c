#include "types.h"

u32 fn_800B417C(void* obj);

u32 fn_800ACC88(void* obj) {
    u32 result = fn_800B417C(obj);

    if (result == 14) {
        return 14;
    }
    return result;
}
