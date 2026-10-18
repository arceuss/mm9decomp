#include "types.h"

extern u8 lbl_80301320[];
void OSLockMutex(u8*);
void fn_80116038(u32, u32);
void OSUnlockMutex(u8*);

void fn_8002541C(u32 a) {
    OSLockMutex(lbl_80301320 + 0x3C);
    fn_80116038(*(u32*)(lbl_80301320 + 0x54), a);
    OSUnlockMutex(lbl_80301320 + 0x3C);
}
