#include "types.h"

extern u8 lbl_80301308[];
void fn_8002458C(u8* work, u32 mode);

void fn_80024020(void) {
    fn_8002458C(*(u8**)(lbl_80301308 + 0x10), 1);
}
