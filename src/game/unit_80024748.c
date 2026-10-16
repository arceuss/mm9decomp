#include "types.h"

extern u8 lbl_804EC838[];
extern u16 lbl_804EC81C[4];
extern u8 lbl_804EE6C8[8];
extern u8 lbl_804EC824[4];
extern void (*lbl_804EC818[1])(u8*);
void fn_800E9A84(u8*, u32);

void fn_80024748(u8* p) {
    *(u32*)(p + 0x18) = *(u32*)(*(u8**)(lbl_804EC838 + p[9] * 4) + 4);
    p[0x10] = 1;
    p[0x11] = 0;
    p[0x12] = 0;
    p[0x13] = 0;
    p[0x11] = lbl_804EE6C8[p[0x14]];
    p[0x2E] = 0xF;
    p[0xA] |= 3;
    fn_800E9A84(p, lbl_804EC81C[p[0x14]]);
    p[0x2F] = lbl_804EC824[p[0x14]];
    lbl_804EC818[p[0x11]](p);
}
