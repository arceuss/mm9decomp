#include "types.h"

extern u8 lbl_80301320[];
void fn_8002AC80(void);
s32 fn_801F7530(u32);
void fn_801F74F8(u32);
void fn_80025C34(u32, u32, u32);

void fn_8002A1E8(u32 a, u32 b) {
    u8* p;
    u8* p2;

    p2 = *(u8**)(lbl_80301320 + 0x5C);
    if (p2[0] != 7) {
        return;
    }
    if (!(*(u32*)(lbl_80301320 + 4) & 0x10)) {
        return;
    }
    if (a == 0) {
        return;
    }
    *(u32*)(p2 + 8) = a;
    p2 = *(u8**)(lbl_80301320 + 0x5C);
    *(u32*)(p2 + 0xC) = b;
    if (fn_801F7530(*(u32*)(a + 4)) == 0) {
        fn_801F74F8(*(u32*)(a + 4));
    }
    p2 = *(u8**)(lbl_80301320 + 0x5C);
    p2[1] = p2[0];
    p2 = *(u8**)(lbl_80301320 + 0x5C);
    p2[0] = 8;
    fn_80025C34((u32)fn_8002AC80, 0, 0);
}
