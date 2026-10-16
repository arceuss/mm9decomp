#include "types.h"

u32 fn_800B417C(void* obj);

u32 fn_800AC97C(void* obj) {
    u32 result = fn_800B417C(obj);

    if (result == 6) {
        return 6;
    }
    return result;
}
