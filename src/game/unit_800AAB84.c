#include "types.h"

s32 fn_801E2648(void);
void fn_800AB27C(void);

s32 fn_800AAB84(void) {
    s32 result = fn_801E2648();

    fn_800AB27C();
    return result;
}
