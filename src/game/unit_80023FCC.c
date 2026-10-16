#include "types.h"

extern u32 lbl_80301308[];

void fn_8002458C(void* p, s32 n);

void fn_80023FCC(void) {
    fn_8002458C((void*)lbl_80301308[2], 2);
    fn_8002458C((void*)lbl_80301308[3], 2);
}
