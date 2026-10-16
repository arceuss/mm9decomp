#include "types.h"

extern u8 lbl_8027F040[];
extern u8 lbl_8027F070[];

void fn_800D5234(s32 a0);
void fn_800E91F0(void* a0, void* a1, s32 a2);
void fn_800BF9A8(void* a0, void* a1);
void fn_800C011C(void);

void fn_800BFC54(u8* a0) {
    s32 i;

    fn_800D5234(0x2B);
    fn_800E91F0(a0, lbl_8027F040, 0);
    *(void**)(a0 + 0xAC) = fn_800C011C;
    for (i = 0; i < 4; i++) {
        fn_800BF9A8(a0, lbl_8027F070 + i * 8);
    }
}
