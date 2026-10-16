
#include "types.h"

extern u8 lbl_80263B88[0x18];
extern u8 lbl_80301320[];
void fn_80025484(void);
void fn_80025498(void);
void fn_80025860(void);
s32 fn_801F6864(u32, u32, u32);
void fn_8002AC80(void);

void fn_8002B218(u8* obj) {
    u8* p;
    void (*f)(u32, u32, u32);
    s32 r;

    r = fn_801F6864(obj[0] * 8, (u32)lbl_80263B88, *(u32*)(obj + 4));
    if (r != 0) {
        lbl_80301320[0x29] = 4;
        *(u32*)(lbl_80301320 + 0x2C) = r;
        fn_80025860();
        f = *(void (**)(u32, u32, u32))(lbl_80301320 + 0x60);
        f(3, 0, *(u32*)(lbl_80301320 + 0x64));
        fn_80025498();
    } else {
        p = *(u8**)(lbl_80301320 + 0x5C);
        p[1] = p[0];
        p = *(u8**)(lbl_80301320 + 0x5C);
        p[0] = 0xC;
        fn_80025498();
    }
}
