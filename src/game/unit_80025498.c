#include "types.h"

extern u8 lbl_80301320[];
void OSUnlockMutex(u8* p);

void fn_80025498(void) {
    OSUnlockMutex((u8*)*(u32**)(lbl_80301320 + 0x38) + 0x330);
}
