#include "types.h"

extern u8 lbl_80301320[];
s32 fn_8024D800(void*);
void fn_800264A0(s32, void*);

s32 fn_800267F0(void) {
    u8* q = *(u8**)(lbl_80301320 + 0x5C);
    u64 a;
    u64 b;

    if (q[0x15] < *(u32*)(q + 0xC)) {
        if (fn_8024D800(&a) == 0) {
            fn_800264A0(9, &b);
            if (a > b) {
                return 1;
            }
        }
    }
    return 0;
}
