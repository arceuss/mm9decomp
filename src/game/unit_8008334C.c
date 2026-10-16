#include "types.h"

extern u8 lbl_803051D8[];

void fn_8009C120(u8*, u8*, s32);

void fn_8008334C(u8* p) {
    fn_8009C120(p, lbl_803051D8, 0x34);
    if (*(u8*)(lbl_803051D8 + 0x12) == 0) {
        *(u8*)(lbl_803051D8 + 0x12) = 1;
    }
}
