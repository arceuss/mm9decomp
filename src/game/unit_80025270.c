#include "types.h"

extern u8 lbl_80301320[];
extern void (*lbl_80263A04[])(void);
void fn_80029C78(u32*);

void fn_80025270(void) {
    u8 v = lbl_80301320[0];
    u32 f;
    s32 s;
    s32 idx;

    if (v <= 1) {
        return;
    }
    f = *(u32*)(lbl_80301320 + 4);
    s = f & 0xF;
    if (s == 0) {
        return;
    }
    idx = s - 1;
    if (idx >= 3) {
        return;
    }
    lbl_80301320[1] = v;
    lbl_80301320[0] = 4;
    *(u32*)(lbl_80301320 + 4) = f | 0x1000000;
    lbl_80263A04[idx]();
    fn_80029C78(*(u32**)(lbl_80301320 + 0x38));
}
