#include "types.h"

extern u8 lbl_80301320[];
void fn_800F6238(u8* p);

void fn_80025498(void) {
    fn_800F6238((u8*)*(u32**)(lbl_80301320 + 0x38) + 0x330);
}
