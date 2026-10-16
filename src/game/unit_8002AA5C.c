#include "types.h"

extern u8 lbl_80301320[];
void fn_80025860(void);
void fn_80025358(void);
s32 fn_8022FA44(void);

void fn_8002AA5C(void) {
    s32 r = fn_8022FA44();
    void (*f)(u32, u32, u32);

    if (r < 0) {
        lbl_80301320[0x29] = 3;
        *(u32*)(lbl_80301320 + 0x2C) = -r;
        fn_80025860();
        f = *(void (**)(u32, u32, u32))(lbl_80301320 + 0x60);
        f(3, 0, *(u32*)(lbl_80301320 + 0x64));
    } else {
        fn_80025358();
    }
}
