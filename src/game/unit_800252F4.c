#include "types.h"

extern u8 lbl_80301320[];
extern void (*lbl_80263A10[])(void);

void fn_800252F4(void) {
    s32 idx;

    if (lbl_80301320[0] <= 1) {
        return;
    }
    idx = *(u32*)(lbl_80301320 + 4) & 0xF;
    if (idx == 0) {
        return;
    }
    idx = idx - 1;
    if (idx >= 3) {
        return;
    }
    lbl_80263A10[idx]();
}
