#include "types.h"

extern u8 lbl_80301320[];
void OSLockMutex(u8*);
u32 fn_80115F88(u32, u32, u32);
void OSUnlockMutex(u8*);

u32 fn_800253B0(u32 a, u32 b) {
    u32 r;

    OSLockMutex(lbl_80301320 + 0x3C);
    r = fn_80115F88(*(u32*)(lbl_80301320 + 0x54), a, b);
    OSUnlockMutex(lbl_80301320 + 0x3C);
    return r;
}
