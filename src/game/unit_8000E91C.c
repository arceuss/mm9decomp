#include "types.h"

extern u8 lbl_804EF4A0;
extern u8 lbl_804EF4A1;
extern u8 lbl_804EF4A2;
extern u8 lbl_804EF4A3;
extern u32 lbl_8036CF50[];
extern u8 lbl_8026F9B8[];

void OSFatal(void*, void*, void*);

static inline void Fatal(s32 i) {
    u8 fg[4];
    u32 bg = 0;

    fg[0] = lbl_804EF4A0;
    fg[1] = lbl_804EF4A1;
    fg[2] = lbl_804EF4A2;
    fg[3] = lbl_804EF4A3;
    OSFatal(fg, &bg, *(void**)(lbl_8026F9B8 + lbl_8036CF50[0] * 0x24 + i * 4));
}

void fn_8000E91C(s32 err) {
    switch (err) {
    case -4:
        Fatal(0);
        break;
    case -2:
        Fatal(1);
        break;
    case -3:
        Fatal(1);
        break;
    case -9:
        Fatal(7);
        break;
    case -0xB:
        Fatal(8);
        break;
    case -0x40:
        Fatal(3);
        break;
    }
}
