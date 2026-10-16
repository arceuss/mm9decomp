#include "types.h"

extern u32 lbl_80301308[];

void fn_8002458C(void* p, s32 n);
s32 fn_800B5AA4(void* p);

void fn_80023F64(void) {
    if (lbl_80301308[0] != 0) {
        fn_8002458C((void*)lbl_80301308[2], 1);
        if (fn_800B5AA4((void*)lbl_80301308[0])) {
            fn_8002458C((void*)lbl_80301308[3], 1);
        }
    }
}
