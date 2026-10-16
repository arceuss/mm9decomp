#include "types.h"

extern u8 lbl_80301320[];
void fn_80029C98(u8* w, u32 a, u32 b, u32 c);

void fn_80025C34(u32 a, u32 b, u32 c) {
    fn_80029C98(*(u8**)(lbl_80301320 + 0x38), a, b, c);
}
