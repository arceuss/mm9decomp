#include "types.h"

extern u8 lbl_80301320[];
extern u8 lbl_804EC880[8];
void fn_80027234(u8* args, u32 a);
void fn_80029B30(u8* list);
void fn_80029B4C(u32* ctx, u32 size, u32 align);
void fn_800289E8(void);
void fn_80025C34(u32, u32, u32);

void fn_8002609C(u32 A, u32 B, u32 C) {
    u8* base;
    u8* p;
    u32 n;
    u8 s0;
    u8 s1;
    u32 t;
    u32* p27;
    u32 tstk[8];
    u32 i;
    u32 k;

    base = lbl_80301320;
    p = *(u8**)(base + 0x5C);
    n = p[0];
    s0 = base[0x28];
    if (n != 0x10 || (*(u32*)(base + 4) & 0x80) == 0) {
        return;
    }
}
