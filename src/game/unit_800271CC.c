#include "types.h"

extern u8 lbl_80301388[];
void OSLockMutex(u8*);
void fn_80116038(u32, u32);
void OSUnlockMutex(u8*);
void fn_8002541C(u32);

void fn_800271CC(u32 a) {
    if ((*(u16*)(lbl_80301388 + 0x2A) & 1) == 0) {
        OSLockMutex(lbl_80301388);
        fn_80116038(*(u32*)(lbl_80301388 + 0x18), a);
        OSUnlockMutex(lbl_80301388);
        return;
    }
    fn_8002541C(a);
}
