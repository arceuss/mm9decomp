#include "types.h"

extern u8 lbl_80301320[];
s32 fn_8024CB74(u32*);
s32 fn_8024BD64(s32);
void fn_80025860(void);

u32 fn_80026D2C(void) {
    u32 v;
    s32 r1;
    u8* p;
    void (*f)(u32, u32, u32);

    v = 0;
    p = *(u8**)(lbl_80301320 + 0x5C);
    if (p[0] == 0x10) {
        r1 = fn_8024CB74(&v);
        if (r1 < 0) {
            if ((u32)(fn_8024BD64(r1) - 0x30000) != 0x1D2B) {
                lbl_80301320[0x29] = 5;
                *(u32*)(lbl_80301320 + 0x2C) = fn_8024BD64(r1);
                fn_80025860();
                f = *(void (**)(u32, u32, u32))(lbl_80301320 + 0x60);
                f(3, 0, *(u32*)(lbl_80301320 + 0x64));
                v = 0;
            }
        }
    }
    return v;
}
