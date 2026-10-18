#include "types.h"

extern u8 lbl_80301320[];
void OSTryLockMutex(u8* p);

void fn_80025470(void) {
    OSTryLockMutex((u8*)*(u32**)(lbl_80301320 + 0x38) + 0x330);
}
