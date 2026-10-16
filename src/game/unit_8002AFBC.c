
#include "types.h"

extern u8 lbl_80301320[];
extern u8 lbl_804EC880[8];
void fn_80027234(u8* args, u32 a);
void fn_80029B30(u8* list);
void fn_80029B4C(u32* ctx, u32 size, u32 align);
void fn_800289E8(void);
void fn_80025484(void);
void fn_80025498(void);
void fn_80025860(void);
void fn_80025358(void);
s32 fn_8022FF74(void);
s32 fn_8022FA44(void);
s32 fn_801F6724(void);
void fn_801E7030(void);
s32 fn_801F7870(u32 a);
s32 fn_801F787C(u32 a);
void fn_8002ABC4(u8* obj);
void fn_8002ADBC(u8* obj);

void fn_8002AFBC(void) {
    u8* base;
    u8* p;
    void (*f)(u32, u32, u32);
    s32 r;

    fn_80025484();
    r = fn_801F6724();
    if (r != 0) {
        base = lbl_80301320;
        base[0x29] = 4;
        *(u32*)(base + 0x2C) = -r;
        fn_80025860();
        f = *(void (**)(u32, u32, u32))(base + 0x60);
        f(3, 0, *(u32*)(base + 0x64));
        fn_80025498();
        return;
    }
    base = lbl_80301320;
    *(u32*)(base + 4) = *(u32*)(base + 4) & ~0x20;
    fn_80025498();
    r = *(u32*)(base + 4);
    if ((r & 0x1000000)) {
        fn_80025484();
        fn_801E7030();
        *(u32*)(base + 4) = *(u32*)(base + 4) & ~0x10;
        fn_80025498();
        r = fn_801F7870(*(u32*)(*(u32*)(*(u8**)(base + 0x5C) + 8) + 4));
        if (r != 0) {
            fn_801F787C(*(u32*)(*(u32*)(*(u8**)(base + 0x5C) + 8) + 4));
            f = *(void (**)(u32, u32, u32))(base + 0x60);
            f(1, 0, *(u32*)(base + 0x64));
        }
        base = lbl_80301320;
        if (*(u32*)(base + 4) & 0x1000000) {
            fn_80025484();
            fn_801E3258();
            fn_80025498();
            r = fn_8022FF74();
            if (r < 0) {
                base[0x29] = 3;
                *(u32*)(base + 0x2C) = -r;
                fn_80025860();
                f = *(void (**)(u32, u32, u32))(base + 0x60);
                f(3, 0, *(u32*)(base + 0x64));
            } else {
                r = fn_8022FA44();
                if (r < 0) {
                    base[0x29] = 3;
                    *(u32*)(base + 0x2C) = -r;
                    fn_80025860();
                    f = *(void (**)(u32, u32, u32))(base + 0x60);
                    f(3, 0, *(u32*)(base + 0x64));
                } else {
                    fn_80025358();
                }
            }
        } else {
            p = *(u8**)(base + 0x5C);
            *(u32*)(p + 0x18) = (u32)fn_8002ABC4;
        }
    } else {
        p = *(u8**)(base + 0x5C);
        *(u32*)(p + 0x18) = (u32)fn_8002ADBC;
    }
}
