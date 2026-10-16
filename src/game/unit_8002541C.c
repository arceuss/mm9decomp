#include "types.h"

extern u8 lbl_80301320[];
void fn_800F615C(u8*);
void fn_80116038(u32, u32);
void fn_800F6238(u8*);

void fn_8002541C(u32 a) {
    fn_800F615C(lbl_80301320 + 0x3C);
    fn_80116038(*(u32*)(lbl_80301320 + 0x54), a);
    fn_800F6238(lbl_80301320 + 0x3C);
}
