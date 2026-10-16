#include "types.h"

extern u8 lbl_8043CD08[];
extern u32 lbl_8027430C[];
extern void* lbl_804EE948;
extern u8 lbl_80316D78[];

void fn_800E6A78(void*);
void fn_8009C04C(s32, void*, s32);
void fn_800A78AC(void);
void fn_800E8D30(void*, u32);
void fn_800E8FC4(void*, void*);
void fn_800E69E8(void*);
void fn_800963D8(void*);

void fn_8009484C(u8* p) {
    fn_800E6A78(p + 0xDD0);
    fn_8009C04C(0, lbl_8043CD08, 0x20);
    fn_800A78AC();
    ((void (*)(u8*))lbl_8027430C[p[2]])(p);
    fn_800E8D30(lbl_804EE948, 0x100);
    fn_800E8FC4(lbl_804EE948, p + 0xDD0);
    fn_800E69E8(p + 0xDD0);
    fn_800963D8(*(u8**)(lbl_80316D78 + 0x3004) + 0xD4102A);
}
