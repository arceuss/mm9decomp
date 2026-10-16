#include "types.h"

extern u8 lbl_80301388[];
void fn_800F615C(u8*);
void fn_80116038(u32, u32);
void fn_800F6238(u8*);
void fn_8002541C(u32);

void fn_800271CC(u32 a) {
    if ((*(u16*)(lbl_80301388 + 0x2A) & 1) == 0) {
        fn_800F615C(lbl_80301388);
        fn_80116038(*(u32*)(lbl_80301388 + 0x18), a);
        fn_800F6238(lbl_80301388);
        return;
    }
    fn_8002541C(a);
}
