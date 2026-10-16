#include "types.h"

extern u8 lbl_8027E8F0[];
extern void fn_800B68A8(u8* obj);
void fn_800E91F0(u8* obj, u8* src, u32 n);

void fn_800B6790(u8* obj) {
    fn_800E91F0(obj, lbl_8027E8F0, 0x1C);
    *(void**)(obj + 0xAC) = (void*)fn_800B68A8;
    obj[0x117] = 0;
    obj[0xFD] = 0xFF;
    obj[0x115] = 0;
    obj[0x114] = 0;
    obj[0x108] = 0;
    obj[0x116] = 0;
    obj[0x118] = 0;
}
