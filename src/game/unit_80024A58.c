#include "types.h"

extern u8 lbl_804EC838[];
extern u8 lbl_804EC828[];
extern void (*lbl_80263964[])(u8* obj);
void fn_800E7960(u8* a);
void fn_80024E48(u8* obj);

void fn_80024A58(u8* obj) {
    void (*fn)(u8* obj);
    u32* tbl;
    u8 kind;
    u8 a;
    u8 v;
    u8* sda;

    tbl = (u32*)lbl_804EC838;
    fn = fn_80024E48;
    sda = lbl_804EC828;
    kind = obj[9];
    a = obj[0x0A];
    v = obj[0x14];
    a = a | 3;
    *(u32*)(obj + 0x18) = *(u32*)(*(u32*)((u8*)tbl + kind * 4) + 4);
    obj[0x10] = 1;
    obj[0x12] = 0;
    obj[0x13] = 0;
    obj[0x11] = sda[v];
    obj[0x0A] = a;
    obj[0x16] = 0;
    fn_800E7960(obj + 0x40);
    a = obj[0x0A];
    *(u32*)(obj + 0x48) = (u32)fn;
    obj[0x0A] = a & 0xF7;
    obj[0x88] = 0;
    lbl_80263964[obj[0x11]](obj);
}
