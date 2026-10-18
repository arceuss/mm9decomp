#include "types.h"

extern u8 lbl_80301320[];
void OSLockMutex(u8* p);

void fn_80025484(void) {
    OSLockMutex((u8*)*(u32**)(lbl_80301320 + 0x38) + 0x330);
}
