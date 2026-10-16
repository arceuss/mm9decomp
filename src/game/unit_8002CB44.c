#include "types.h"

extern u8 lbl_80263F90[0x18];
extern u8 lbl_803013F4[0x2C];
void fn_800A5BE0(void* a, void* b, u32 c, u32 d);

void fn_8002CB44(u8* obj) {
    u8* p;
    u8* q;
    u8 a0;
    u8 a1;
    u8 a2;
    u8 a3;
    u8 a4;
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    u8 b4;
    u8 b5;

    p = lbl_80263F90;
    q = lbl_80263F90;
    p[15] = 0xF;
    a0 = obj[0x374];
    p[1] = 0xF;
    a1 = obj[0x375];
    p[2] = 0xF;
    a2 = obj[0x376];
    p[3] = 0xF;
    a3 = obj[0x377];
    p[4] = 0xF;
    a4 = obj[0x378];
    p[5] = 0xF;
    b0 = obj[0x379];
    p[6] = 0xF;
    b1 = obj[0x37A];
    p[7] = 0xF;
    b2 = obj[0x37B];
    p[8] = 0xF;
    b3 = obj[0x37C];
    p[9] = 0xF;
    b4 = obj[0x37D];
    b5 = obj[0x37E];
    p[0] = a0;
    p[1] = a1;
    p[2] = a2;
    p[3] = a3;
    p[4] = a4;
    p[5] = b0;
    p[6] = b1;
    p[7] = b2;
    p[8] = b3;
    p[9] = b4;
    *(u32*)(obj + 0x370) = *(u32*)(obj + 0x370);
    fn_800A5BE0(p, lbl_803013F4, 0, 0);
}
