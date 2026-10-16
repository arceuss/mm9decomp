#include "types.h"
extern u8 lbl_8037CC40[], lbl_80316D78[], lbl_80383E70[];
extern char lbl_8027E308[], lbl_8027E318[];
extern u32 fn_800AA3D8(const char*, u8, void*);
extern void fn_800A80F8(void*, s32);
void fn_800A77E4(void) {
    fn_800AA3D8(lbl_8027E308, 2, lbl_8037CC40);
    fn_800AA3D8(lbl_8027E318, 1, lbl_8037CC40 + 0x804);
    fn_800A80F8(lbl_8037CC40 + 0x1008, 0x1000);
    *(u8**)lbl_80383E70 = *(u8**)(lbl_80316D78 + 0x3004) + 0xC75000;
}
