#include "types.h"

extern u8 lbl_80303E58[];
extern s32 fn_800836D8(void* p);
extern void fn_80083714(void* p);

void fn_8003FDE0(void) {
    if (*(u16*)(lbl_80303E58 + 0xCD0) & 1) {
        u8* p = lbl_80303E58;
        s32 i = 0;

        do {
            if (fn_800836D8(p) != 0) {
                fn_80083714(p);
            }
            i++;
            p += 0x41C;
        } while (i < 3);
    }
    *(u16*)(lbl_80303E58 + 0xCCC) = 0;
    *(u16*)(lbl_80303E58 + 0xCD0) &= 0x10;
    *(u16*)(lbl_80303E58 + 0xCD2) = 0;
    lbl_80303E58[0xCD4] = 0xFF;
    lbl_80303E58[0xCD5] = 0;
    lbl_80303E58[0xCD6] = 0;
    lbl_80303E58[0xCD7] = 0;
    lbl_80303E58[0xCD8] = 0;
    lbl_80303E58[0xCD9] = 0;
    lbl_80303E58[0xCDA] = 0;
}
