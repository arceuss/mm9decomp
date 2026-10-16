#include "types.h"

extern u8 lbl_80301388[];
void fn_80027A38(u32, u32);

void fn_80029980(u32* pr) {
    fn_80027A38(pr[0], pr[1]);
    *(u16*)(lbl_80301388 + 0x2A) &= ~0x4;
}
