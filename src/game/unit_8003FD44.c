#include "types.h"

extern u8 lbl_80303E58[];
extern u8 lbl_804ECA08[8];

extern s32 fn_800AAA88(u32 v);
extern void fn_80150D20(void);
extern void fn_8003FDE0(void);

void fn_8003FD44(void) {
    if (!(*(u16*)(lbl_80303E58 + 0xCD0) & 0x10)) {
        u8* p = lbl_80303E58;
        u32* q = (u32*)lbl_804ECA08;
        s32 i = 0;

        do {
            *(u32*)(p + 0xCF4) = fn_800AAA88(*q);
            fn_80150D20();
            i++;
            p += 4;
            q++;
        } while (i < 2);
    }
    *(u16*)(lbl_80303E58 + 0xCD0) |= 0x10;
    fn_8003FDE0();
    lbl_80303E58[0xCDB] = 2;
    *(u16*)(lbl_80303E58 + 0xCCE) = 0;
}
